/*      $Id: hw_default.h,v 1.1.1.1 2006-07-11 09:31:22 andy Exp $      */

/****************************************************************************
 ** hw_default.h ************************************************************
 ****************************************************************************
 *
 * routines for hardware that supports ioctl() interface
 * 
 * Copyright (C) 1999 Christoph Bartelmus <lirc@bartelmus.de>
 *
 */

#ifndef _HW_DEFAULT_H
#define _HW_DEFAULT_H

#include "ir_remote.h"

inline lirc_t time_left(struct timeval *current,struct timeval *last,
			lirc_t gap);

int default_init(void);
int default_deinit(void);
int write_send_buffer(int lirc,int length,lirc_t *signals);
int default_send(struct ir_remote *remote,struct ir_ncode *code);
char *default_rec(struct ir_remote *remotes);
int default_decode(struct ir_remote *remote,
		   ir_code *prep,ir_code *codep,ir_code *postp,
		   int *repeat_flagp,lirc_t *remaining_gapp);
#endif