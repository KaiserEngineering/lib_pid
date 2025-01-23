
#ifdef TEST

#include "unity.h"

#include "lib_pid.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_lib_pid_clear_PID(void)
{
  PID_DATA test_pid;
  lib_pid_clear_PID(&test_pid);
  TEST_ASSERT_EQUAL_INT(0, test_pid.header);
  TEST_ASSERT_EQUAL_INT(PID_UNASSIGNED, test_pid.mode);
  TEST_ASSERT_EQUAL_INT(PID_UNASSIGNED, test_pid.pid);
  TEST_ASSERT_EQUAL_INT(PID_UNITS_RESERVED, test_pid.pid_unit);
  TEST_ASSERT_EQUAL_INT(PID_UNITS_RESERVED, test_pid.base_unit);
  TEST_ASSERT_EQUAL_INT(0, test_pid.timestamp);
  TEST_ASSERT_EQUAL_INT(PID_UNASSIGNED, test_pid.acquisition_type);
  TEST_ASSERT_EQUAL_INT(0, test_pid.devices);
}

#endif // TEST
