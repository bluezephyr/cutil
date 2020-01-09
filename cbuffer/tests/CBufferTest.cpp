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

extern "C"
{
    #include "cbuffer.h"
}

TEST_GROUP(CBuffer)
{
    void setup() override
    {
    }

    void teardown() override
    {
    }
};

/*******************************************************************************
 * TEST CASES
 *******************************************************************************/
TEST(CBuffer, init)
{
    FAIL("Not implemented");
}

/*******************************************************************************
 * TEST RUNNER
 *******************************************************************************/
int main(int ac, char** av)
{
    return CommandLineTestRunner::RunAllTests(ac, av);
}

