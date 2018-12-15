#include <string>
#include <map>
#include <set>

using Synonyms = std::map<std::string, std::set<std::string>>;

void AddSynonyms(Synonyms& synonyms, const std::string& firstWord,
		const std::string& secondWord){
	synonyms[firstWord].insert(secondWord);
	synonyms[secondWord].insert(firstWord);
}

size_t CountSynonym(Synonyms& synonyms, const std::string& word){
	return synonyms[word].size();
}

bool AreSynonyms(Synonyms& synonyms, const std::string& firstWord,
		const std::string& secondWord){
	return synonyms[firstWord].count(secondWord) == 1;
}


