#include "var.h"
#include "unity.h"
#include "lib_pid.h"

void setUp( void )
{
}

void tearDown( void )
{
}

void test_0x010C_engine_rpm(void)
{
    uint8_t payload[4] = { 0x12, 0x34, 0xFF, 0xFF };
    TEST_ASSERT_EQUAL_FLOAT( 1165, get_pid_value( 0x01, 0x0C, payload ) );
}

