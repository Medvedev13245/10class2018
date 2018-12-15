#pragma once

#include <exception>
#include <sstream>
#include "Synonyms.h"

template<class T, class U>
void AssertEqual(const T& t, const U& u, const int& hint){
	if (t != u){
		std::stringstream ss;
		ss << "Assert failed: " << t << " != " << u << ", hint: " << hint;
		throw std::runtime_error(ss.str());
	}
}

void TestAddSynonyms(){
	{
		Synonyms empty;
		AddSynonyms(empty, "a", "b");

		const Synonyms expected  = {
				{"a", {"b", "c"}}, // ќжидаем, что в map, будет 2 записи
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
}

void TestCount(){ // Test Count
	{
		Synonyms empty;
		AssertEqual(CountSynonym(empty, "a"), 0u, __LINE__);
	}
	{
		Synonyms synonyms = {
						{"a", {"b"}},
						{"b", {"a", "c"}},
						{"c", {"b"}}
				};
		AssertEqual(CountSynonym(synonyms, "a"), 1u, __LINE__);
		AssertEqual(CountSynonym(synonyms, "b"), 2u, __LINE__);
		AssertEqual(CountSynonym(synonyms, "c"), 1u, __LINE__);
	}
}

void TestAreSynonyms(){
	{
		Synonyms empty;
		AssertEqual(!AreSynonyms(empty, "a", "b"), false, __LINE__);
		AssertEqual(!AreSynonyms(empty, "b", "a"), false, __LINE__);
	}
	{
		Synonyms synonyms = {
					{"a", {"b"}},
					{"b", {"a", "c"}},
					{"c", {"b"}}
		};

		AssertEqual(AreSynonyms(synonyms, "a", "b"), true, __LINE__);
		AssertEqual(AreSynonyms(synonyms, "b", "a"), true, __LINE__);
		AssertEqual(AreSynonyms(synonyms, "b", "c"), true, __LINE__);
		AssertEqual(AreSynonyms(synonyms, "c", "b"), true, __LINE__);
		AssertEqual(!AreSynonyms(synonyms, "c", "a"), false, __LINE__);
		AssertEqual(!AreSynonyms(synonyms, "a", "c"), false, __LINE__);
	}
}
