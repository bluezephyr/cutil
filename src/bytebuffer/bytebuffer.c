/*
 * Byte Buffer Implementation
 *
 * Copyright (c) 2020. BlueZephyr, blue.zephyr.git@gmail.com
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 *
 */

#include <bytebuffer.h>

/*******************************************************************************
 * LOCAL FUNCTION PROTOTYPES
 *******************************************************************************/
static uint16_t mask(bytebuffer_t *buffer, uint16_t value);


void bytebuffer_init(bytebuffer_t *buffer, uint8_t *data, uint16_t capacity)
{
    buffer->start = 0;
    buffer->end = 0;
    buffer->data = data;
    buffer->capacity = capacity;
}

bool bytebuffer_isEmpty(bytebuffer_t *buffer)
{
    return (buffer->start == buffer->end);
}

bool bytebuffer_isFull(bytebuffer_t *buffer)
{
    return (bytebuffer_getSize(buffer) == buffer->capacity);
}

uint16_t bytebuffer_getSize(bytebuffer_t *buffer)
{
    return (buffer->start - buffer->end);
}

uint16_t bytebuffer_getSpace(bytebuffer_t *buffer)
{
    return (buffer->capacity - bytebuffer_getSize(buffer));
}

void bytebuffer_write(bytebuffer_t *buffer, uint8_t data)
{
    buffer->data[mask(buffer, buffer->start++)] = data;
}

uint8_t bytebuffer_read(bytebuffer_t *buffer)
{
    return buffer->data[mask(buffer, buffer->end++)];
}

/*******************************************************************************
 * LOCAL FUNCTIONS
 *******************************************************************************/
static uint16_t mask(bytebuffer_t *buffer, uint16_t value)
{
    return (value & (buffer->capacity - 1u));
}

