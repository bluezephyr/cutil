/*
 * Circular Buffer Implementation
 *
 * Copyright (c) 2020. BlueZephyr, blue.zephyr.git@gmail.com
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 *
 */

#include <cbuffer.h>

/*******************************************************************************
 * LOCAL FUNCTION PROTOTYPES
 *******************************************************************************/
static uint8_t mask(cbuffer_t *cbuffer, uint8_t value);


void cbuf_init(cbuffer_t *cbuffer, uint8_t *data, uint8_t capacity)
{
    cbuffer->start = 0;
    cbuffer->end = 0;
    cbuffer->data = data;
    cbuffer->capacity = capacity;
}

bool cbuf_empty(cbuffer_t *cbuffer)
{
    return (cbuffer->start == cbuffer->end);
}

bool cbuf_full(cbuffer_t *cbuffer)
{
    return (cbuf_size(cbuffer) == cbuffer->capacity);
}

uint8_t cbuf_size(cbuffer_t *cbuffer)
{
    return (cbuffer->start - cbuffer->end);
}

void cbuf_write(cbuffer_t *cbuffer, uint8_t data)
{
    cbuffer->data[mask(cbuffer, cbuffer->start++)] = data;
}

uint8_t cbuf_read(cbuffer_t *cbuffer)
{
    return cbuffer->data[mask(cbuffer, cbuffer->end++)];
}

/*******************************************************************************
 * LOCAL FUNCTIONS
 *******************************************************************************/
static uint8_t mask(cbuffer_t *cbuffer, uint8_t value)
{
    return (value & (cbuffer->capacity - 1u));
}

