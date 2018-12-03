#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <sstream>

using namespace std;

void Map(){
	map<int, string> names;
	names[1990] = "name1";
	names[1995] = "name3";
	cout << names[1901] << endl;
	names.erase(1901);
}

string PrintSet(set<string> s){
	cout << "Size = " << s.size() << endl;
	stringstream ss;
	bool first = true;
	for(auto& item: s){
		if (!first){
			ss << ", ";
		}
		ss << item;
		first = false;
	}
	return ss.str();
}

void Set(){
	set<string> impPersons;
	impPersons.insert("Strousurp");
	impPersons.insert("Stan Lee");
	impPersons.insert("Stb");
	impPersons.insert("Stb");
	cout << impPersons.count("Stb") << endl;
	cout << PrintSet(impPersons) << endl;
}

template <typename T>
T Sqr(T x){
	return x * x;
}

template<typename First, typename Second>
pair<First, Second> operator *(const pair<First, Second>& lhs,
								const pair<First, Second>& rhs){
	First t = lhs.first * rhs.first;
	Second r = lhs.second * rhs.second;
	return make_pair(t, r);
}

template<typename First, typename Second>
ostream& operator << (ostream& stream, const pair<First, Second>& p){
	stream << p.first << ", " << p.second;
}

template<typename T>
ostream& operator << (ostream& stream, const vector<T>& v){
	bool first = true;
	for (const auto& item: v){
		if(!first){
			cout << ", ";
		}
		cout << item;
		first = false;
	}
	return stream;
}

template<typename Key, typename Value>
ostream& operator << (ostream& stream, const map<Key,Value>& g)
{
	for (const auto& i: g)
	{
		stream << i<<", ";
	}
	return stream;
}
// сделать красивый (без зап€той в конце) вывод всех контейнеров
// пару заключаем в <>
// вектор заключаем в []
// map в {}

int main() {
	return 0;
}
