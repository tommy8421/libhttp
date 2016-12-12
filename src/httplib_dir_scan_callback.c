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



void XX_httplib_dir_scan_callback( struct de *de, void *data ) {

	struct dir_scan_data *dsd = (struct dir_scan_data *)data;

	if (dsd->entries == NULL || dsd->num_entries >= dsd->arr_size) {
		dsd->arr_size *= 2;
		dsd->entries = XX_httplib_realloc2(dsd->entries, dsd->arr_size * sizeof(dsd->entries[0]));
	}
	if (dsd->entries == NULL) {
		/* TODO(lsm, low): propagate an error to the caller */
		dsd->num_entries = 0;
	} else {
		dsd->entries[dsd->num_entries].file_name = XX_httplib_strdup(de->file_name);
		dsd->entries[dsd->num_entries].file = de->file;
		dsd->entries[dsd->num_entries].conn = de->conn;
		dsd->num_entries++;
	}

}  /* XX_httplib_dir_scan_callback */
