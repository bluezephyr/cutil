/*
 * Circular Buffer Implementation
 *
 * Copyright (c) 2020. BlueZephyr, blue.zephyr.git@gmail.com
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 *
 */

#ifndef CUTIL_CBUFFER_H
#define CUTIL_CBUFFER_H

#include <stdint.h>
#include <stdbool.h>

typedef struct cbuffer
{
    uint8_t* data;
    uint8_t capacity;
    uint8_t start;
    uint8_t end;
} cbuffer_t;

/*
 * The init function must be called before the buffer is used.  It is the responsibility
 * of the caller to allocate memory for both the data array and the cbuffer struct.
 *
 * Note that the capacity of the data array MUST be a power of 2.
 */
void cbuf_init(cbuffer_t *cbuffer, uint8_t *data, uint8_t capacity);

/*
 * Returns true/full if the buffer is empty/full.
 */
bool cbuf_empty(cbuffer_t *cbuffer);
bool cbuf_full(cbuffer_t *cbuffer);

/*
 * Return the number of bytes currently stored in the buffer.
 */
uint8_t cbuf_size(cbuffer_t *cbuffer);

/*
 * Write one data byte to the buffer.  It is the responsibility of the caller to make sure
 * that there are available room in the buffer before the function is called.  Writing to
 * a full buffer has undefined behavior.
 */
void cbuf_write(cbuffer_t *cbuffer, uint8_t data);

/*
 * Read one data byte from the buffer.  It is the responsibility of the caller to make sure
 * that the buffer is not empty.  Reading from an empty buffer has undefined behavior.
 */
uint8_t cbuf_read(cbuffer_t *cbuffer);

#endif //CUTIL_CBUFFER_H
