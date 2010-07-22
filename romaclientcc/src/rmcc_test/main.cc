/*
 * main.cc - ????
 *  
 *   Copyright (C) 2010 rakuten 
 *     by hiroaki.kubota <hiroaki.kubota@rakuten.co.jp> 
 *     Date : 2010/06/11
 */

#include <cppunit/TestFixture.h>
#include <cppunit/TestSuite.h>
#include <cppunit/TestCaller.h>
#include <cppunit/Asserter.h>
#include <cppunit/TestAssert.h>
#include <cppunit/SourceLine.h>

#include "nomal_test.h"
#include "loop_test.h"
#include "loop_monkey_test.h"
#include "protocol_test.h"

using namespace std;

#include <cppunit/TestSuite.h>
#include <cppunit/TestCaller.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestRunner.h>

int main ( int argc , char * argv[]  ){
  CppUnit::TestResultCollector collector;
  CppUnit::TestResult result;
  result.addListener(&collector);
  CppUnit::TestSuite suite;
  //suite.addTest(NomalTest::getSuite());
  //suite.addTest(ProtocolTest::getSuite());
  suite.addTest(LoopTest::getSuite());
  //suite.addTest(LoopMonkeyTest::getSuite());
  suite.run(&result);
  CppUnit::CompilerOutputter outputter(&collector, CppUnit::stdCOut());
  outputter.write();
  return collector.wasSuccessful() ? 0 : 1;
}
// int main ( int argc , char * argv[]  ){
//   RomaClientTestLoop2 test;
//   test.setUp();
//   test.testLoop2();
// }
