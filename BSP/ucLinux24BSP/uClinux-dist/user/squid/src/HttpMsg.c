
/*
 * $Id: HttpMsg.c,v 1.1.1.1 2006-07-11 09:33:06 andy Exp $
 *
 * DEBUG: section 74    HTTP Message
 * AUTHOR: Alex Rousskov
 *
 * SQUID Internet Object Cache  http://squid.nlanr.net/Squid/
 * ----------------------------------------------------------
 *
 *  Squid is the result of efforts by numerous individuals from the
 *  Internet community.  Development is led by Duane Wessels of the
 *  National Laboratory for Applied Network Research and funded by the
 *  National Science Foundation.  Squid is Copyrighted (C) 1998 by
 *  the Regents of the University of California.  Please see the
 *  COPYRIGHT file for full details.  Squid incorporates software
 *  developed and/or copyrighted by other sources.  Please see the
 *  CREDITS file for full details.
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *  
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *  
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111, USA.
 *
 */

#include "squid.h"


/* find end of headers */
int
httpMsgIsolateHeaders(const char **parse_start, const char **blk_start, const char **blk_end)
{
    /*
     * parse_start points to the first line of HTTP message *headers*,
     * not including the request or status lines
     */
    size_t l = strlen(*parse_start);
    size_t end = headersEnd(*parse_start, l);
    int nnl;
    if (end) {
	*blk_start = *parse_start;
	*blk_end = *parse_start + end - 1;
	/*
	 * leave blk_end pointing to the first character after the
	 * first newline which terminates the headers
	 */
	assert(**blk_end == '\n');
	while (*(*blk_end - 1) == '\r')
	    (*blk_end)--;
	assert(*(*blk_end - 1) == '\n');
	*parse_start += end;
	return 1;
    }
    /*
     * If we didn't find the end of headers, and parse_start does
     * NOT point to a CR or NL character, then return failure
     */
    if (**parse_start != '\r' && **parse_start != '\n')
	return 0;		/* failure */
    /*
     * If we didn't find the end of headers, and parse_start does point
     * to an empty line, then we have empty headers.  Skip all CR and
     * NL characters up to the first NL.  Leave parse_start pointing at
     * the first character after the first NL.
     */
    *blk_start = *parse_start;
    *blk_end = *blk_start;
    for (nnl = 0; nnl == 0; (*parse_start)++) {
	if (**parse_start == '\r')
	    (void) 0;
	else if (**parse_start == '\n')
	    nnl++;
	else
	    break;
    }
    return 1;
}

/* returns true if connection should be "persistent" 
 * after processing this message */
int
httpMsgIsPersistent(float http_ver, const HttpHeader * hdr)
{
    if (http_ver >= 1.1) {
	/*
	 * for modern versions of HTTP: persistent unless there is
	 * a "Connection: close" header.
	 */
	return !httpHeaderHasConnDir(hdr, "close");
    } else {
	/*
	 * Persistent connections in Netscape 3.x are allegedly broken,
	 * return false if it is a browser connection.  If there is a
	 * VIA header, then we assume this is NOT a browser connection.
	 */
	const char *agent = httpHeaderGetStr(hdr, HDR_USER_AGENT);
	if (agent && !httpHeaderHas(hdr, HDR_VIA)) {
	    if (!strncasecmp(agent, "Mozilla/3.", 10))
		return 0;
	    if (!strncasecmp(agent, "Netscape/3.", 11))
		return 0;
	}
	/* for old versions of HTTP: persistent if has "keep-alive" */
	return httpHeaderHasConnDir(hdr, "keep-alive");
    }
}
