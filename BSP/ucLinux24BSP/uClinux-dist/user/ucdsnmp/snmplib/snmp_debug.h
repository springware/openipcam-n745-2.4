#ifndef SNMP_DEBUG_H
#define SNMP_DEBUG_H

#ifdef __cplusplus
extern "C" {
#endif

/* snmp_debug.h:

   - prototypes for snmp debugging routines.
   - easy to use macros to wrap around the functions.  This also provides
     the ability to reove debugging code easily from the applications at
     compile time.
*/


/* These functions should not be used, if at all possible.  Instead, use
   the macros below. */
#if HAVE_STDARG_H
void debugmsg(const char *token, const char *format, ...);
void debugmsgtoken(const char *token, const char *format, ...);
#else
void debugmsg(va_alist);
void debugmsgtoken(va_alist);
#endif
void debugmsg_oid(const char *token, oid *theoid, size_t len);
void debugmsg_hex(const char *token, u_char *thedata, size_t len);
void debugmsg_hextli(const char *token, u_char *thedata, size_t len);
void debug_indent_add(int amount);
char *debug_indent(void);

/* Use these macros instead of the functions above to allow them to be
   re-defined at compile time to NOP for speed optimization.

   They need to be called enclosing all the arguments in a single set of ()s.
   Example:
      DEBUGMSGTL(("token", "debugging of something %s related\n", "snmp"));

Usage:
   All of the functions take a "token" argument that helps determine when
   the output in question should be printed.  See the snmpcmd.1 manual page
   on the -D flag to turn on/off output for a given token on the command line.

     DEBUGMSG((token, format, ...)):      equivelent to printf(format, ...)
                                          (if "token" debugging output
                                          is requested by the user)
  
     DEBUGMSGT((token, format, ...)):     equivelent to DEBUGMSG, but prints
                                          "token: " at the beginning of the
                                          line for you.
  
     DEBUGTRACE                           Insert this token anywhere you want
                                          tracing output displayed when the
                                          "trace" debugging token is selected.
  
     DEBUGMSGL((token, format, ...)):     equivelent to DEBUGMSG, but includes
                                          DEBUGTRACE debugging line just before
                                          yours.
  
     DEBUGMSGTL((token, format, ...)):    Same as DEBUGMSGL and DEBUGMSGT
                                          combined.

Important:
   It is considered best if you use DEBUGMSGTL() everywhere possible, as it
   gives the nicest format output and provides tracing support just before
   every debugging statement output.

To print multiple pieces to a single line in one call, use:

     DEBUGMSGTL(("token", "line part 1"));
     DEBUGMSG  (("token", " and part 2\n"));

   to get:

     token: line part 1 and part 2

   as debugging output.
*/

#ifndef SNMP_NO_DEBUGGING  /* make sure we're wanted */

/*
 * define two macros : one macro with, one without,
 *                     a test if debugging is enabled.
 * 
 * Generally, use the macro with _DBG_IF_
 */

/******************* Start private macros ************************/
#define _DBG_IF_            snmp_get_do_debugging()
#define DEBUGIF(x)         if (_DBG_IF_ && debug_is_token_registered(x) == SNMPERR_SUCCESS)

#define __DBGMSGT(x)     debugmsgtoken x,  debugmsg x

#ifdef  HAVE_CPP_UNDERBAR_FUNCTION_DEFINED
#define __DBGTRACE       __DBGMSGT(("trace","%s(): %s, %d\n",__FUNCTION__,\
                                 __FILE__,__LINE__))
#else
#define __DBGTRACE       __DBGMSGT(("trace"," %s, %d\n", __FILE__,__LINE__))
#endif

#define __DBGMSGL(x)     __DBGTRACE, debugmsg x
#define __DBGMSGTL(x)    __DBGTRACE, debugmsgtoken x, debugmsg x
#define __DBGMSGOID(x)     debugmsg_oid x
#define __DBGMSGHEX(x)     debugmsg_hex x
#define __DBGMSGHEXTLI(x)  debugmsg_hextli x
#define __DBGINDENT()      debug_indent()
#define __DBGINDENTADD(x)  debug_indent_add(x)
#define __DBGINDENTMORE()  debug_indent_add(2)
#define __DBGINDENTLESS()  debug_indent_add(-2)
#define __DBGPRINTINDENT(token) __DBGMSGTL((token, "%s", __DBGINDENT()))

#define __DBGDUMPHEADER(token,x) \
        __DBGPRINTINDENT(token), \
        debugmsg(token,x), \
        __DBGINDENTMORE()

#define __DBGDUMPSETUP(token,buf,len) \
        __DBGTRACE, \
        __DBGMSGHEXTLI((token,buf,len)), \
        debugmsg(token,"\n"), \
        __DBGPRINTINDENT(token)

/******************* End   private macros ************************/
/*****************************************************************/

/*****************************************************************/
/********************Start public  macros ************************/

#define DEBUGMSG(x)        do {if (_DBG_IF_) {debugmsg x;} }while(0)
#define DEBUGMSGT(x)       do {if (_DBG_IF_) {__DBGMSGT(x);} }while(0)
#define DEBUGTRACE         do {if (_DBG_IF_) {__DBGTRACE;} }while(0)
#define DEBUGMSGL(x)       do {if (_DBG_IF_) {__DBGMSGL(x);} }while(0)
#define DEBUGMSGTL(x)      do {if (_DBG_IF_) {__DBGMSGTL(x);} }while(0)
#define DEBUGMSGOID(x)     do {if (_DBG_IF_) {__DBGMSGOID(x);} }while(0)
#define DEBUGMSGHEX(x)     do {if (_DBG_IF_) {__DBGMSGHEX(x);} }while(0)
#define DEBUGMSGHEXTLI(x)  do {if (_DBG_IF_) {__DBGMSGHEXTLI(x);} }while(0)
#define DEBUGINDENT()      do {if (_DBG_IF_) {__DBGINDENT();} }while(0)
#define DEBUGINDENTADD(x)  do {if (_DBG_IF_) {__DBGINDENTADD(x);} }while(0)
#define DEBUGINDENTMORE()  do {if (_DBG_IF_) {__DBGINDENTMORE();} }while(0)
#define DEBUGINDENTLESS()  do {if (_DBG_IF_) {__DBGINDENTLESS();} }while(0)
#define DEBUGPRINTINDENT(token) \
	do {if (_DBG_IF_) {__DBGPRINTINDENT(token);} }while(0)


#define DEBUGDUMPHEADER(token,x) \
	do {if (_DBG_IF_) {__DBGDUMPHEADER(token,x);} }while(0)

#define DEBUGDUMPSETUP(token,buf,len) \
	do {if (_DBG_IF_) {__DBGDUMPSETUP(token,buf,len);} }while(0)

#else /* SNMP_NO_DEBUGGING := enable streamlining of the code */

#define DEBUGMSG(x)
#define DEBUGMSGT(x)
#define DEBUGTRACE
#define DEBUGMSGL(x)
#define DEBUGMSGTL(x)
#define DEBUGMSGOID(x)
#define DEBUGMSGHEX(x)
#define DEBUGIF(x)        if(0)
#define DEBUGDUMP(t,b,l,p)
#define DEBUGINDENT()
#define DEBUGINDENTMORE()
#define DEBUGINDENTLESS()
#define DEBUGINDENTADD(x)
#define DEBUGMSGHEXTLI(x)
#define DEBUGPRINTINDENT(token)
#define DEBUGDUMPHEADER(token,x)
#define DEBUGDUMPSETUP(token, buf, len)

#endif

#define MAX_DEBUG_TOKENS 256
#define MAX_DEBUG_TOKEN_LEN 128
#define DEBUG_TOKEN_DELIMITER ","
#define DEBUG_ALWAYS_TOKEN "all"

/*
  setup routines:
  
  debug_register_tokens(char *):     registers a list of tokens to
                                     print debugging output for.

  debug_is_token_registered(char *): returns SNMPERR_SUCCESS or SNMPERR_GENERR
                                     if a token has been registered or
                                     not (and debugging output is "on").
  snmp_debug_init(void):             registers .conf handlers.
*/
void debug_register_tokens(char *tokens);
int debug_is_token_registered(const char *token);
void snmp_debug_init(void);

/* provided for backwards compatability.  Don't use these functions. */
#if HAVE_STDARG_H
void DEBUGP (const char *, ...);
#else
void DEBUGP (va_alist);
#endif
void DEBUGPOID(oid *, size_t);
void snmp_set_do_debugging (int);
int snmp_get_do_debugging (void);
int debug_is_token_registered(const char *token);

#ifdef __cplusplus
}
#endif

#endif /* SNMP_DEBUG_H */
