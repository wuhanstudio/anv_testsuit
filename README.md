# anv_testsuit
RT-Thread 单元测试框架

    #include <rtthread.h>
    #include "anv_testsuite.h"

    ANV_TESTSUITE_FIXTURE(test_group_1_fixture_1)
    {
        int a = 10;
        expect(a == 10);

        int b = 13;
        expect(a == b);
    }

    ANV_TESTSUITE_FIXTURE(test_group_1_fixture_2)
    {

    }

    ANV_TESTSUITE_FIXTURE(test_group_1_fixture_3)
    {
        expect_msg(0, "rip");
    }

    ANV_TESTSUITE(test_group_1,
        ANV_TESTSUITE_ADD(test_group_1_fixture_1),
        ANV_TESTSUITE_ADD(test_group_1_fixture_2),
        ANV_TESTSUITE_ADD(test_group_1_fixture_3),
    );

    ANV_TESTSUITE_FIXTURE(test_group_2_fixture_1)
    {

    }

    ANV_TESTSUITE(test_group_2,
        ANV_TESTSUITE_ADD(test_group_2_fixture_1),
    );

    int anv_testsuit_example(int argc, char const *argv[])
    {
        ANV_TESTSUITE_BEGIN(stdout);    // optional
        ANV_TESTSUITE_RUN(test_group_1, stdout);
        ANV_TESTSUITE_RUN(test_group_2, stdout);
        ANV_TESTSUITE_END(stdout);      // optional
      return 0;
    }

可以对测试进行分组，查看每个分组的测试结果：

     \ | /
    - RT -     Thread Operating System
     / | \     4.0.3 build Feb 11 2021
     2006 - 2021 Copyright by rt-thread team
    msh />anv
    anv_testsuit_example
    msh />anv_testsuit_example
    ==== BEGIN RUNNING TESTS ====
    ---- BEGIN TEST SUITE: test_group_1 ----

    [0] test_group_1_fixture_1         => FAILURE(10): 'a == b'
    [1] test_group_1_fixture_2         => SUCCESS
    [2] test_group_1_fixture_3         => FAILURE(20): '0' (rip)

    SUCCESS: 1/3

    ---- END TEST SUITE: test_group_1 ----
    ---- BEGIN TEST SUITE: test_group_2 ----

    [0] test_group_2_fixture_1         => SUCCESS

    SUCCESS: 1/1

    ---- END TEST SUITE: test_group_2 ----
    ==== END RUNNING TESTS ====

