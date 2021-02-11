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
MSH_CMD_EXPORT(anv_testsuit_example, anv testsuit example);
