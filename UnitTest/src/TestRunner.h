/*
 * TestRunner.h
 *
 *  Created on: 15 ���. 2018 �.
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
			// ��������� ����� ������
			func();
			cout << testName << " OK" << endl;
		}
		catch(runtime_error& e){
			cout << testName << " fail: " << e.what() << endl;
		}
	}
};



//#endif /* TESTRUNNER_H_ */
