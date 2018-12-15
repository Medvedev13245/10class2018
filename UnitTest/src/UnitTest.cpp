//============================================================================
// Name        : UnitTest.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <map>
#include <set>
#include <string>
#include <cassert>
#include <exception>
#include <sstream>
#include "Tests.h"
#include "TestRunner.h"
#include "Synonyms.h"

using namespace std;

using Synonyms = map<string, set<string>>;

template<class T, class U>
ostream& operator<<(ostream& stream, const map<T, U>& m){
	stream << "{" << endl;
	for (const auto& item: m){
		stream << item.first << ": " << item.second << ";" << endl;
	}
	stream << "}";
	return stream;
}

template<class T>
ostream& operator<<(ostream& stream, const set<T>& s){
	stream << "[";
	for (const auto& item: s){
		stream << item << ",";
	}
	stream << "]";
	return stream;
}

void Synon(){
	int q;
		cin >> q;
		map<string, set<string>> synonyms;
		for(int i = 0; i < q; i++){
			string operationCode;
			cin >> operationCode;
			if (operationCode == "ADD"){ // считываем 2 слова и добавляем в map
				string firstWord, secondWord;
				cin >> firstWord >> secondWord;
				AddSynonyms(synonyms, firstWord, secondWord);
			} else if (operationCode == "COUNT"){ // считываем 1 слово и выводим
				string word;
				cin >> word;
				cout << CountSynonym(synonyms, word) << endl;
			} else if (operationCode == "CHECK"){
				string firstWord, secondWord;
				cin >> firstWord >> secondWord;
				if (AreSynonyms(synonyms, firstWord, secondWord)){
					cout << "YES" << endl;
				}
				else{
					cout << "NO" << endl;
				}
			}
			else {
				cout << "Invalid Command" << endl;
			}
		}
}


int main() {
	cout << "ololo" << endl;
	return 0;
}
