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

using namespace std;

using Synonyms = map<string, set<string>>;

template<class T>
void AssertEqual(const T& t, const T& u, const int& hint){
	if (t != u){
		stringstream ss;
		ss << "Assert failed: " << t << " != " << u << ", hint: " << hint;
		throw runtime_error(ss.str());
	}
}

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

class TestRunner{
public:
	template<class TypeFunc>
	void RunTest(TypeFunc func, const string& testName){
		try { // шаблонный метод класса
			func();
			cout << testName << " OK" << endl;
		}
		catch(runtime_error& e){
			cout << testName << " fail: " << e.what() << endl;
		}
	}
};

int Sum (int x, int y){
	return x + y;
}

void TestSum(){ // набор тестов для функции Sum
	AssertEqual(Sum(2, 3), 4, __LINE__); // мы ожидаем что 2+3 = 5
	AssertEqual(Sum(-2, -3), -5, __LINE__); // проверка отрицательных чисел
	AssertEqual(Sum(-2, 8), 6, __LINE__); // проверка - +
	AssertEqual(Sum(0, -2), -2, __LINE__); // проверка нуля
	AssertEqual(Sum(-2, 2), 0, __LINE__); // проверка нуля 2
	cout << "Test Sum OK" << endl;
}

void AddSynonyms(Synonyms& synonyms, const string& firstWord,
		const string& secondWord){
	synonyms[firstWord].insert(secondWord);
	synonyms[secondWord].insert(firstWord);
}

size_t CountSynonym(Synonyms& synonyms, const string& word){
	return synonyms[word].size();
}

bool AreSynonyms(Synonyms& synonyms, const string& firstWord,
		const string& secondWord){
	return synonyms[firstWord].count(secondWord) == 1;
}

void TestAddSynonyms(){
	{
		Synonyms empty;
		AddSynonyms(empty, "a", "b");

		const Synonyms expected  = {
				{"a", {"b", "c"}}, // Ожидаем, что в map, будет 2 записи
				{"b", {"a"}}
		};
		AssertEqual(empty, expected, __LINE__);
	}

	{
		Synonyms synonyms = {
				{"a", {"b"}},
				{"b", {"a", "c"}},
				{"c", {"b"}}
		};
		AddSynonyms(synonyms, "a", "c");
		Synonyms expected = {
						{"a", {"b", "c"}},
						{"b", {"a", "c"}},
						{"c", {"b", "a"}}
				};
		AssertEqual(synonyms, expected,__LINE__);
	}
	cout << "TestAddSynonyms OK" << endl;
}

void TestCount(){ // Test Count
	{
		Synonyms empty;
		assert(CountSynonym(empty, "a")==0);
	}
	{
		Synonyms synonyms = {
						{"a", {"b"}},
						{"b", {"a", "c"}},
						{"c", {"b"}}
				};
		assert(CountSynonym(synonyms, "a")==1);
		assert(CountSynonym(synonyms, "b")==2);
		assert(CountSynonym(synonyms, "c")==1);
	}
}

void TestAreSynonyms(){
	{
		Synonyms empty;
		assert(!AreSynonyms(empty, "a", "b"));
		assert(!AreSynonyms(empty, "b", "a"));
	}
	{
		Synonyms synonyms = {
					{"a", {"b"}},
					{"b", {"a", "c"}},
					{"c", {"b"}}
		};

		assert(AreSynonyms(synonyms, "a", "b"));
		assert(AreSynonyms(synonyms, "b", "a"));
		assert(AreSynonyms(synonyms, "b", "c"));
		assert(AreSynonyms(synonyms, "c", "b"));
		assert(!AreSynonyms(synonyms, "c", "a"));
		assert(!AreSynonyms(synonyms, "a", "c"));
	}
}

void TestAll(){
	TestAddSynonyms();
	TestCount();
	TestAreSynonyms();
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
	TestRunner tr;
	tr.RunTest(TestAddSynonyms, "TestAddSynonyms");
	tr.RunTest(TestCount, "TestCount");
	tr.RunTest(TestAreSynonyms, "TestAreSynonyms");

	cout << "ololo" << endl;
	return 0;
}
