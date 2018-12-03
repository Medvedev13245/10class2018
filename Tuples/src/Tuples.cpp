#include <iostream>
#include <vector>
#include <cstdint>
#include <string>
#include <tuple>

using namespace std;

const int REQUEST_ADD = 0;
const int REQUEST_REMOVE = 1;

// enumeration
enum class RequestType{
	ADD,
	REMOVE = 45,
	FACTOR
};

// можно закастовать enum to int (получить числовой код элемента)
// cout << static_cast<int>(RequestType::FACTOR) << endl;
// написать функцию, котора€ обрабатывает запросы к некому множеству

void ProcessRequest(
		vector<int>& numbers,
		RequestType requestType,
		int requestData){
	switch(requestType){
	case RequestType::ADD:
		numbers.push_back(requestData);
		break;
	case RequestType::REMOVE:
		break;
	case RequestType::FACTOR:
		break;
	}
}

void PrintVector(const vector<int>& numbers){
	for (const auto& b : numbers){
		cout << b << " ";
	}
}

class Date{
public:
	tuple<int, int, int> getTuple() const{
		return tie(year, month, day);
	}
	int year;
	int month;
	int day;
};
// определние оператора сравнени€ через кортеж
bool operator<(const Date& lhs, const Date& rhs){
	tuple<int, int, int> rhsTuple = rhs.getTuple();
	tuple<int, int, int> lhsTuple = lhs.getTuple();
	return lhsTuple < rhsTuple;
}

struct funcReturn{
	bool success;
	string message;
};

tuple<bool, string> someFunc(int a, int b){
	if (a == b){
		return make_tuple(false, "a == b");
	}
	if (a < b){
		return make_tuple(true, "a < b");
	}
	return make_tuple(true, "a > b");
}

void peopleQueue(){

		int N;
		cin >> N;

		string command;
		vector<int> people;

		int peopleCount;

		cin >> command >> peopleCount;
		vector<int> people()
		for (int i = 0; i < N; i++){
			cin >> command;
			switch(command){
			case "COME":
				cin >> peopleCount;
				if (peopleCount > 0){
					for (int i = 0; i < peopleCount; i++){
						people.push_back(0);
					}
				}
				else{
					for (int i = peopleCount; i < 0; i++){
						people.pop_back();
					}
				}
				break;
			case "WORRY":
				cin >> peopleCount;
				people[peopleCount] = 1;
				break;
			case "QUIET":
				cin >> peopleCount;
				people[peopleCount] = 0;
				break;
			case "WORRY_COUNT":
				int count = 0;
				for(const auto& t: people){
					count += t;
				}
				cout << count;
				break;
			}
		}
}

int main(){
	vector<int>


	pair<bool, string> p{false, "olololo"};

	cout << p.first << endl;
	cout << p.second << endl;

	int a = 45;
	string b = "qwerty";

	auto tup = tie(a, b);
	// tie работает со ссылками, make_tuple со значени€ми, make_pair
	//auto tup = make_tuple(45, "qwerty");


	// ќбращение к элементам кортежа
	cout << get<0>(tup) << endl;
	cout << get<1>(tup) << endl;


	Date date1{2018, 11, 17};
	Date date2{2018,10,17};
	if (date2 < date1){
		cout << "true" << endl;
	}
	else {
		cout << "false" << endl;
	}
}
