/*
 * TestRunner.h
 *
 *  Created on: 15 дек. 2018 г.
 *      Author: dimka
 */

//#ifndef TESTRUNNER_H_
//#define TESTRUNNER_H_
#pragma once

#include <iostream>
#include <string>

using namespace std;

class TestRunner{
public:
	template<class TypeFunc>
	void RunTest(TypeFunc func, const string& testName){
		try {
			// шаблонный метод класса
			func();
			cout << testName << " OK" << endl;
		}
		catch(runtime_error& e){
			cout << testName << " fail: " << e.what() << endl;
		}
	}
};



//#endif /* TESTRUNNER_H_ */
