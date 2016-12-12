/* 
 * Copyright (c) 2016 Lammert Bies
 * Copyright (c) 2013-2016 the Civetweb developers
 * Copyright (c) 2004-2013 Sergey Lyubka
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */



#include "httplib_main.h"



/* Authorize against the opened passwords file. Return 1 if authorized. */
int XX_httplib_authorize( struct mg_connection *conn, struct file *filep ) {

	struct read_auth_file_struct workdata;
	char buf[MG_BUF_LEN];

	if ( conn == NULL  ||  conn->ctx == NULL ) return 0;

	memset(&workdata, 0, sizeof(workdata));
	workdata.conn = conn;

	if (!XX_httplib_parse_auth_header(conn, buf, sizeof(buf), &workdata.ah)) return 0;
	workdata.domain = conn->ctx->config[AUTHENTICATION_DOMAIN];

	return XX_httplib_read_auth_file(filep, &workdata);

}  /* XX_httplib_authorize */
