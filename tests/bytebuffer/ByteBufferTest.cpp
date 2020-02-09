/*
 * Unit tests for the Byte Buffer.
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
    #include "bytebuffer.h"
}

TEST_GROUP(ByteBuffer)
{
    uint8_t data[CAPACITY];
    bytebuffer_t buffer;

    void setup() override
    {
        bytebuffer_init(&buffer, data, CAPACITY);
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
            bytebuffer_write(&buffer, i);
        }
    }
};

/*******************************************************************************
 * TEST CASES
 *******************************************************************************/
TEST(ByteBuffer, init_buffer_empty)
{
    // Init is done in the setup
    CHECK_TRUE(bytebuffer_isEmpty(&buffer));
}

TEST(ByteBuffer, write_one_item_buffer_contain_one_item)
{
    bytebuffer_write(&buffer, 0x40);
    CHECK_FALSE(bytebuffer_isEmpty(&buffer));
    CHECK_FALSE(bytebuffer_isFull(&buffer));
    CHECK_EQUAL(1, bytebuffer_getSize(&buffer));
}

TEST(ByteBuffer, write_capacity_and_buffer_is_full)
{
    write_range(0, CAPACITY);
    CHECK_FALSE(bytebuffer_isEmpty(&buffer));
    CHECK_TRUE(bytebuffer_isFull(&buffer));
}

TEST(ByteBuffer, write_one_item_read_one_item_buffer_empty)
{
    bytebuffer_write(&buffer, 0x40);
    CHECK_EQUAL(0x40, bytebuffer_read(&buffer));
    CHECK_TRUE(bytebuffer_isEmpty(&buffer));
}

/*******************************************************************************
 * TEST RUNNER
 *******************************************************************************/
int main(int ac, char** av)
{
    return CommandLineTestRunner::RunAllTests(ac, av);
}

