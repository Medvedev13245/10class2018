#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <algorithm>

struct Student {
	std::string name;
	int age;
};

void PrintVector(const std::vector<std::string>& v) {
	for (const auto& i : v) {
		std::cout << i << " ";
	}
}

template<class It>
void PrintMapRange(It rangeBegin, It rangeEnd) {
	for (auto it = rangeBegin; it != rangeEnd; it++) {
		std::cout << it->first << "/" << it->second << " ";
	}
}

template<class It>
void PrintRange(It rangeBegin, It rangeEnd) {
	for (auto it = rangeBegin; it != rangeEnd; it++) {
		cout << *it << " ";
	}
}

int main() {
	std::map<std::string, int> studMap = {
		{"Vova", 21},
		{"Jenya", 22},
		{"Maks", 23},
		{"Danya", 24}
	};

	PrintMapRange(begin(studMap), end(studMap));

	std::set<std::string> studSet = { "Vova", "Jenya", "Maks", "Maks", "Danya" };

		/*auto it = studSet.find("Jenya");
	PrintRange(begin(studSet), it);
	cout << endl;
	PrintRange(it, end(studSet));*/

	std::vector<Student> students = {
			{"Vova", 21},
			{"Jenya", 22},
			{"Maks", 23},
			{"Danya", 24} };

	std::string stud;

	std::vector<std::string> stud2 = { "Vova", "Jenya", "Maks", "Maaaks", "Danya" };

	auto it = end(stud2);
	while (it != begin(stud2)) {
		--it;
		std::cout << *it << std::endl;
	}
	char let = 'M';

	// *end(c)
	// auto i = end(c); i++;
	// auto i = begin(c); i--;
	// sort, count, count_if, find, find_if, reverse

	sort(stud2.begin(), stud2.end());
	auto result2 = find_if(stud2.begin(), stud2.end(), [let](const std::string& st) {
		return st[0] == let;
	});

	// [begin, end)

	/*PrintRange(stud2.begin(), result2);
	cout << endl;
	PrintRange(result2, stud2.end());*/

	/*string test1 = "Python";
	auto res = find(test1.begin(), test1.end(), 't');
	PrintRange(test1.begin(), res);
	PrintRange(res, test1.end());*/

	auto result = find_if(begin(students), students.end(), [let](const Student& stud) {
		return stud.name[0] == let;
	});

	/*for(auto it = begin(students); it != end(students); it++){
		cout << it->name << " ";
	}*/


	/*if(result == students.end()){
		cout << "Not found" << endl;
	}else
	{
		result++;
		cout << result->name << " " << result->age << endl;
	}*/


	//PrintVector(students);
	//cout << endl;
	//auto& ref = *result;
	//ref = "ABCD";

	//PrintVector(students);

	std::cout << "Hello" << std::endl;

	system("pause");
	return 0;
}