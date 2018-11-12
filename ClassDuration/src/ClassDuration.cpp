//============================================================================
// Name        : ClassDuration.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;

class Duration{
public:
	int hour;
	int min;

	Duration(int h = 0, int m = 0){
		int total = h * 60 + m;
		hour = total / 60;
		min = (total - 60*hour) % 60;
	}
};
Duration operator+(Duration& dur1, Duration& dur2){
	int a=dur1.hour+dur2.hour;
	int b=dur1.min+dur2.min;

	Duration dur3;
	dur3.hour=a;
	dur3.min=b;
	return dur3;
}

bool operator<(const Duration& lhs, const Duration& rhs){
	if (lhs.hour == rhs.hour){
		return lhs.min < lhs.min;
	}
	return lhs.hour < rhs.hour;
}

Duration operator-(const Duration& lhs, const Duration& rhs){
	if (lhs < rhs){
		Duration dur3(0,0);
		return dur3;
	}
	Duration dur3(lhs.hour - rhs.hour, lhs.min - rhs.min); // 2:05 - 1:45
	return dur3;
}

ostream& operator<<(ostream& stream, const Duration& dur){
	stream << setfill('0');
	stream << setw(2) << dur.hour << ":" << setw(2) << dur.min;
	return stream;
}

istream& operator>>(istream& stream, Duration& dur){
	// 2:55
}
int main() {
	Duration dur1(2, 15);
	Duration dur2(1, 45);
	Duration dur3 = dur1 - dur2;
	cout << "dur1 = " << dur1 << endl;
	cout << "dur2 = " << dur2 << endl;
	cout << "dur3 = " << dur3 << endl;
	return 0;
}
