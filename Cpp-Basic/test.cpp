#include <gtest/gtest.h>  
#include <tchar.h>
#include "fun.h"

TEST(testCase, test0)
{
	EXPECT_EQ(14, add(4, 10));
}

TEST(testCase, test1)
{
	/*本用例不过*/
	EXPECT_NE(6, add(5, 7));
}

TEST(testCase, test2)
{
	EXPECT_EQ(28, add(10, 18));
}

int _tmain(int argc, _TCHAR* argv[])
{
	testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
	return 0;
}