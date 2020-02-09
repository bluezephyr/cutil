/*
 * Byte Buffer Implementation
 *
 * Copyright (c) 2020. BlueZephyr, blue.zephyr.git@gmail.com
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 *
 */

#ifndef CUTIL_BYTEBUFFER_H
#define CUTIL_BYTEBUFFER_H

#include <stdint.h>
#include <stdbool.h>

typedef struct bytebuffer
{
    uint8_t* data;
    uint8_t capacity;
    uint8_t start;
    uint8_t end;
} bytebuffer_t;

/*
 * The init function must be called before the buffer is used.  It is the responsibility
 * of the caller to allocate memory for both the data array and the buffer struct.
 *
 * Note that the capacity of the data array MUST be a power of 2.  Maximum capacity is 128.
 */
void bytebuffer_init(bytebuffer_t *buffer, uint8_t *data, uint8_t capacity);

/*
 * Returns true/full if the buffer is empty/full.
 */
bool bytebuffer_isEmpty(bytebuffer_t *buffer);
bool bytebuffer_isFull(bytebuffer_t *buffer);

/*
 * Return the number of bytes currently stored in the buffer.
 */
uint8_t bytebuffer_getSize(bytebuffer_t *buffer);

/*
 * Write one data byte to the buffer.  It is the responsibility of the caller to make sure
 * that there are available room in the buffer before the function is called.  Writing to
 * a full buffer has undefined behavior.
 */
void bytebuffer_write(bytebuffer_t *buffer, uint8_t data);

/*
 * Read one data byte from the buffer.  It is the responsibility of the caller to make sure
 * that the buffer is not empty.  Reading from an empty buffer has undefined behavior.
 */
uint8_t bytebuffer_read(bytebuffer_t *buffer);

#endif //CUTIL_BYTEBUFFER_H
