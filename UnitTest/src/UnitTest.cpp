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

using namespace std;

using Synonyms = map<string, set<string>>;

void Test(){

}

int Sum (int x, int y){
	return x + y;
}

void TestSum(){ // набор тестов для функции Sum
	assert(Sum(2, 3) == 5); // мы ожидаем что 2+3 = 5
	assert(Sum(-2, -3) == -5); // проверка отрицательных чисел
	assert(Sum(-2, 8) == 6); // проверка - +
	assert(Sum(0, -2) == -2); // проверка нуля
	assert(Sum(-2, 2) == 0); // проверка нуля 2
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
				{"a", {"b"}}, // Ожидаем, что в map, будет 2 записи
				{"b", {"a"}}
		};
		assert(empty == expected);
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
		assert(synonyms == expected);
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
	cout << "TestCount OK" << endl;
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
	cout << "TestAreSynonyms OK" << endl;
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
	TestAll();
	return 0;
}
