/* Copyright (c) 2013 Anton Titov.
 * Copyright (c) 2013 pCloud Ltd.
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of pCloud Ltd nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL pCloud Ltd BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef _PSYNC_STATUS_H
#define _PSYNC_STATUS_H

#include <stdint.h>

#define PSTATUS_NUM_STATUSES 4

#define PSTATUS_TYPE_RUN     0
#define PSTATUS_TYPE_ONLINE  1
#define PSTATUS_TYPE_AUTH    2
#define PSTATUS_TYPE_ACCFULL 3

#define PSTATUS_INVALID   0

#define PSTATUS_RUN_RUN   1
#define PSTATUS_RUN_PAUSE 2
#define PSTATUS_RUN_STOP  4

#define PSTATUS_ONLINE_CONNECTING 1
#define PSTATUS_ONLINE_SCANNING   2
#define PSTATUS_ONLINE_ONLINE     4
#define PSTATUS_ONLINE_OFFLINE    8

#define PSTATUS_AUTH_PROVIDED 1
#define PSTATUS_AUTH_REQURED  2
#define PSTATUS_AUTH_MISMATCH 4
#define PSTATUS_AUTH_BADLOGIN 8

#define PSTATUS_ACCFULL_QUOTAOK   1
#define PSTATUS_ACCFULL_OVERQUOTA 2

void psync_status_init();
void psync_set_status(uint32_t statusid, uint32_t status);
void psync_wait_status(uint32_t statusid, uint32_t status);


#endif