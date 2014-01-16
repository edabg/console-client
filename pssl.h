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

#ifndef _PSYNC_SSL_H
#define _PSYNC_SSL_H

#include "pcompiler.h"
#include "pcompat.h"

#if defined(P_SSL_OPENSSL)
#include "pssl-openssl.h"
#elif defined(P_SSL_SECURETRANSPORT)
#include "pssl-securetransport.h"
#else
#error "Please specify SSL library to use"
#endif

extern PSYNC_THREAD int psync_ssl_errno;

#define PSYNC_SSL_ERR_WANT_READ  1
#define PSYNC_SSL_ERR_WANT_WRITE 2
#define PSYNC_SSL_ERR_UNKNOWN    3

#define PSYNC_SSL_NEED_FINISH  -2
#define PSYNC_SSL_FAIL         -1
#define PSYNC_SSL_SUCCESS       0

int psync_ssl_init();
int psync_ssl_connect(psync_socket_t sock, void **sslconn, const char *hostname);
int psync_ssl_connect_finish(void *sslconn);
void psync_ssl_free(void *sslconn);
int psync_ssl_shutdown(void *sslconn);
int psync_ssl_pendingdata(void *sslconn) PSYNC_PURE;
int psync_ssl_read(void *sslconn, void *buf, int num);
int psync_ssl_write(void *sslconn, const void *buf, int num);

#endif
