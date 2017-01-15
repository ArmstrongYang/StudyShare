/******************************************************************************

  Copyright (C), 2001-2011, Huawei Tech. Co., Ltd.

 ******************************************************************************
  File Name     :
  Version       :
  Author        :
  Created       : 2013/09
  Last Modified :
  Description   :
  Function List :

  History       :
  1.Date        : 2013/09
    Author      :
    Modification: Created file

******************************************************************************/
#include "CExampleTest.h"

#include "Linker.h"


// 注册测试套到CppUnit
CPPUNIT_TEST_SUITE_REGISTRATION( CExampleTest );


// SetUp: 在每个用例前执行一次
void CExampleTest::setUp()
{

}

// tearDown: 在每个用例后执行一次
void CExampleTest::tearDown()
{
    
}


void CExampleTest::TestCase01()
{
	unsigned int file_1_func_array[] = {11,12};
	unsigned int file_2_func_array[] = {21,22};
	unsigned int file_3_func_array[] = {31,32,33};
	unsigned int file_4_func_array[] = {41,42,43};
	unsigned int file_5_func_array[] = {51,52};

	CPPUNIT_ASSERT(0 == AddFile(1,file_1_func_array,2));

	CPPUNIT_ASSERT(0 == AddFile(2,file_2_func_array,2));

	CPPUNIT_ASSERT(0 == AddFile(3,file_3_func_array,3));

	CPPUNIT_ASSERT(0 == AddFile(4,file_4_func_array,3));

	CPPUNIT_ASSERT(0 == AddFile(5,file_5_func_array,2));

	unsigned int callee_name_array_11[] = {12,21};
	unsigned int callee_name_array_21[] = {32,41};
	unsigned int callee_name_array_32[] = {33};
	unsigned int callee_name_array_41[] = {42,43};
	unsigned int callee_name_array_42[] = {22};
	unsigned int callee_name_array_51[] = {52};

	CPPUNIT_ASSERT(0 == AddCallList(11,callee_name_array_11,2));

	CPPUNIT_ASSERT(0 == AddCallList(21,callee_name_array_21,2));

	CPPUNIT_ASSERT(0 == AddCallList(32,callee_name_array_32,1));

	CPPUNIT_ASSERT(0 == AddCallList(41,callee_name_array_41,2));

	CPPUNIT_ASSERT(0 == AddCallList(42,callee_name_array_42,1));

	CPPUNIT_ASSERT(0 == AddCallList(51, callee_name_array_51, 1));


	CPPUNIT_ASSERT(0 == IsFileLinked(2));

	CPPUNIT_ASSERT(0 == IsFileLinked(1));

	CPPUNIT_ASSERT(0 == IsFileLinked(3));

	CPPUNIT_ASSERT(0 == IsFileLinked(4));

	CPPUNIT_ASSERT(-1 == IsFileLinked(5));

	
	return;
}