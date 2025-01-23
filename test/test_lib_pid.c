
#ifdef TEST

#include "unity.h"

#include "lib_pid.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_RunningDemo_should_DoNormalOperations(void)
{
  PID_DATA test_pid;
  lib_pid_clear_PID(&test_pid);
  TEST_ASSERT_EQUAL_INT(PID_UNASSIGNED, test_pid.mode);
}

#endif // TEST
