/*
 * $Log: flreq.h,v $
 * Revision 1.1.1.1  2006-07-11 09:28:45  andy
 * W90N745 BSP
 *
 * Revision 1.1.1.1  2006/04/26 02:35:51  andy
 * W90N745 uCLinux kernel
 *
 * 
 *    Rev 1.4   May 14 2002 15:07:34   oris
 * Separated private definitions to _flreq.h
 * 
 *    Rev 1.3   Jan 29 2002 20:09:12   oris
 * Changed LOW_LEVEL compilation flag with FL_LOW_LEVEL to prevent definition clashes.
 * 
 *    Rev 1.2   Apr 01 2001 07:46:16   oris
 * Updated copywrite notice
 * 
 *    Rev 1.1   Feb 18 2001 12:07:24   oris
 * Added VOLUME_ACCUPIED volume flag.
 *
 *    Rev 1.0   Feb 04 2001 11:42:12   oris
 * Initial revision.
 *
 */

/***********************************************************************************/
/*                        M-Systems Confidential                                   */
/*           Copyright (C) M-Systems Flash Disk Pioneers Ltd. 1995-2001            */
/*                         All Rights Reserved                                     */
/***********************************************************************************/
/*                            NOTICE OF M-SYSTEMS OEM                              */
/*                           SOFTWARE LICENSE AGREEMENT                            */
/*                                                                                 */
/*      THE USE OF THIS SOFTWARE IS GOVERNED BY A SEPARATE LICENSE                 */
/*      AGREEMENT BETWEEN THE OEM AND M-SYSTEMS. REFER TO THAT AGREEMENT           */
/*      FOR THE SPECIFIC TERMS AND CONDITIONS OF USE,                              */
/*      OR CONTACT M-SYSTEMS FOR LICENSE ASSISTANCE:                               */
/*      E-MAIL = info@m-sys.com                                                    */
/***********************************************************************************/

#ifndef FLREQ_H
#define FLREQ_H

#include "flbase.h"
#include "_flreq.h"

#define VOLUME_LOW_LVL_MOUNTED 1  /* Volume is mounted for low level operations */
#define	VOLUME_MOUNTED	       2  /* Volume is mounted */
#define VOLUME_12BIT_FAT       4  /* Volume uses 12-bit FAT */
#define	VOLUME_ABS_MOUNTED     8  /* Volume is mounted for abs calls */
#define VOLUME_WRITE_PROTECTED 16 /* Volume is write protected */
#define VOLUME_ACCUPIED        32 /* Volume record bellongs to a volume */

typedef unsigned FLHandle;	/* Handle of an open file or drive.	*/
				/* Actually an index to file table or	*/
				/* drive table.				*/

/*----------------------------------------------------------------------*/
/*			P a t h - N a m e s				                                      */
/*									                                                    */
/* A path-name is represented as an array of SimplePath records.	      */
/* Each SimplePath record holds a directory or file name segment, with  */
/* the full 8.3 (spaces not compressed) name.				                    */
/*									                                                    */
/* Path-names always start at the root directory. There is no current   */
/* directory. The directories pointers '.' and '..' can be specified	  */
/* as the 'name' part of the path-segment, except at the root-directory.*/
/*									                                                    */
/* Lower-case letters are different from upper-case. To be compatible   */
/* with DOS, file-names should be upper-case. File names may contain    */
/* any character, but files starting with hex E5 are considered deleted */
/* according to DOS convention.						                              */
/*									                                                    */
/* A null (hex 0) in the first byte of the name field denotes that the  */
/* path ends here.							                                        */
/*                                                                      */
/* Note that paths can be specified as strings: For example:     	      */
/*									                                                    */
/* "UTIL       FATLITE H  "    ===> "\UTIL\FATLITE.H".			            */
/* ""				 ===> "\" (root directory)		                              */
/* "AUTOEXECBAT"                ===> "\AUTOEXEC.BAT"			              */
/* "UTIL       ..         "	 ===> "\UTIL\.." (root directory)	          */
/*									                                                    */
/* The optional service flParsePath may be used to convert regular	    */
/* string paths to this format.						                              */
/*----------------------------------------------------------------------*/

typedef struct {
  char	name[8];	/* name part of path segment */
  /* A hex 0 in 1st character indicates end of path */
  char	ext[3];		/* extension part of path segment */
} FLSimplePath;

/*----------------------------------------------------------------------*/
/*			  I O r e q					                                            */
/*									                                                    */
/* IOreq is a common structure passed to all file-system functions.	    */
/* Refer to the description of individual functions for specific usage  */
/* of fields. Some fields have different names when used by different   */
/* functions, hence the use of unions.					                        */
/*									                                                    */
/*----------------------------------------------------------------------*/

typedef struct {
  FLHandle	irHandle;	/* Handle of file or drive for operation*/
  unsigned	irFlags;	/* function-specific flags 		*/
  FLSimplePath FAR1 * irPath;	/* path of file for operation 		*/
  void FAR1 *	irData;		/* Pointer to user-buffer for operation */
  long		irLength;	/* No. of bytes, size or position for   */
				/* operation			 	*/
#if defined(ABS_READ_WRITE) || defined(FL_LOW_LEVEL)
  long		irCount;	/* Count or offset for operaion		*/
#endif
} IOreq;

/* definiftions for absolute read & write */
#define irSectorCount	irCount
#define	irSectorNo	    irLength

/* definitions for physical read & write */
#define irByteCount	    irCount
#define irAddress       irLength

/* definitions for physical erase */
#define irUnitCount     irCount
#define irUnitNo	    irLength

/* definitions for writing exb file */
#define irWindowBase    irCount


#endif /* FLREQ_H */
