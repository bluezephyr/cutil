/*
 * Unit tests for the CBuffer.
 *
 * Copyright (c) 2020. BlueZephyr
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 *
 */

#include "CppUTest/CommandLineTestRunner.h"
#include "CppUTest/TestHarness.h"

// CAPACITY must be a power of 2
#define CAPACITY 16

extern "C"
{
    #include "cbuffer.h"
}

TEST_GROUP(CBuffer)
{
    uint8_t data[CAPACITY];
    cbuffer_t cbuf;

    void setup() override
    {
        cbuf_init(&cbuf, data, CAPACITY);
    }

    void teardown() override
    {
    }

    // Write range [start..end] not including end
    void write_range(uint8_t start, uint8_t end)
    {
        uint8_t i;

        for(i=start; i<end; i++)
        {
            cbuf_write(&cbuf, i);
        }
    }
};

/*******************************************************************************
 * TEST CASES
 *******************************************************************************/
TEST(CBuffer, init_buffer_empty)
{
    // Init is done in the setup
    CHECK_TRUE(cbuf_empty(&cbuf));
}

TEST(CBuffer, write_one_item_buffer_contain_one_item)
{
    cbuf_write(&cbuf, 0x40);
    CHECK_FALSE(cbuf_empty(&cbuf));
    CHECK_FALSE(cbuf_full(&cbuf));
    CHECK_EQUAL(1, cbuf_size(&cbuf));
}

TEST(CBuffer, write_capacity_and_buffer_is_full)
{
    write_range(0, CAPACITY);
    CHECK_FALSE(cbuf_empty(&cbuf));
    CHECK_TRUE(cbuf_full(&cbuf));
}

TEST(CBuffer, write_one_item_read_one_item_buffer_empty)
{
    cbuf_write(&cbuf, 0x40);
    CHECK_EQUAL(0x40, cbuf_read(&cbuf));
    CHECK_TRUE(cbuf_empty(&cbuf));
}

/*******************************************************************************
 * TEST RUNNER
 *******************************************************************************/
int main(int ac, char** av)
{
    return CommandLineTestRunner::RunAllTests(ac, av);
}

