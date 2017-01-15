/******************************************************************************

  Copyright (C), 2001-2011, Huawei Tech. Co., Ltd.

 ******************************************************************************
  File Name     :
  Version       :
  Author        :
  Created       : 2010/03/12
  Last Modified :
  Description   :
  Function List :

  History       :
  1.Date        : 2010/03/12
    Author      :
    Modification: Created file

******************************************************************************/
#include <cppunit/TextOutputter.h>
#include <cppunit/XmlOutputter.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestRunner.h>
#include "Linker.h"

int main(int argc, char* argv[])
{
	unsigned int callee_name_array_11[] = { 12,21 };
	unsigned int callee_name_array_21[] = { 32,41 };
	unsigned int callee_name_array_32[] = { 33 };
	unsigned int callee_name_array_41[] = { 42,43 };
	unsigned int callee_name_array_42[] = { 22 };
	unsigned int callee_name_array_51[] = { 52 };

    // Create the event manager and test controller
    CPPUNIT_NS::TestResult controller;

    // Add a listener that colllects test result
    CPPUNIT_NS::TestResultCollector result;
    controller.addListener( &result );

    // Add a listener that print dots as test run.
    CPPUNIT_NS::BriefTestProgressListener progress;
    controller.addListener( &progress );

    // Add the top suite to the test runner
    CPPUNIT_NS::TestRunner runner;
    runner.addTest( CPPUNIT_NS::TestFactoryRegistry::getRegistry("All Tests").makeTest() );
    runner.run( controller );

    // Print test in a text format.
    CPPUNIT_NS::TextOutputter outputter( &result, CPPUNIT_NS::stdCOut() );
    outputter.write();

    // This for XML output
    std::ofstream file( "TestResult.xml" );
    CPPUNIT_NS::XmlOutputter xml( &result, file );
    xml.setStyleSheet( "report.xsl" );
    xml.write();
    file.close();
	getchar();
    return result.wasSuccessful() ? 0 : 1;
}
