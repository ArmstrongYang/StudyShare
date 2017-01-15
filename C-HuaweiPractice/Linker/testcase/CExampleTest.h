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
#ifndef _CEXAMPLE_TEST_H
#define _CEXAMPLE_TEST_H

#include <cppunit/extensions/HelperMacros.h>

class CExampleTest : public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE(CExampleTest);
	CPPUNIT_TEST(TestCase01);

    CPPUNIT_TEST_SUITE_END();

public:
    void setUp();
    void tearDown();

	void TestCase01();

};

#endif /*_CEXAMPLE_TEST_H*/
