#pragma once

#include <string>
#include <map>
#include <set>

using Synonyms = std::map<std::string, std::set<std::string>>;

void AddSynonyms(Synonyms& synonyms, const std::string& firstWord,
		const std::string& secondWord);

size_t CountSynonym(Synonyms& synonyms, const std::string& word);

bool AreSynonyms(Synonyms& synonyms, const std::string& firstWord,
		const std::string& secondWord);
