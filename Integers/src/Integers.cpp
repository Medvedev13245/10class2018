//============================================================================
// Name        : Integers.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <cstdint>
#include <limits>

using namespace std;
// неявное преобразование типов
void IntToUnsignedInt(){
	vector<int> a = {-8, -7, 3};
		int Sum = 0;
		for (const auto& t : a){
			Sum += t;
		}
		int avTemp = Sum / a.size();
		cout << avTemp;
}

void BigInt(){
	int x = 2'000'000'000;
	cout << x << endl;
	x = x * 2;
	cout << x << endl;
}

void TypesOfInt(){
	int32_t a; // знаковые.всегда занимает в памяти 32 бита
	uint32_t b; //беззнаковый. Всегда занимаеи в памяти 32 бита
	int16_t c; // знаковый. всегда занимет 16 бит
	uint16_t d; //беззнаковый. Всегда занимает 16 бит
	int8_t e; // знаковый. Всегда занимает 8 бит
	uint8_t f; //беззнаковый. Всегда занимает 8 бит
	int64_t g; //знаковый. Всегда занимает 64 бита
	uint64_t h; // беззнаковый. Всегда занимает 64 бита
}

// sizeof() - функция для вычисления размера типа или переменной
// узнать границы типов - include <limits>; numeric_limits<type>::min(); max()

void FPlusMinusimits(){
	cout << numeric_limits<int>::max() + 1 << " " << numeric_limits<int>::min() << endl;
	cout << numeric_limits<int>::min() - 1 << " " << numeric_limits<int>::max();
}
int main() {
	unsigned int x = numeric_limits<unsigned int>::min() - 1;
	cout << x << endl;
	// 1. Перед операциями все типы приводятся к единому типу
	// 2. Все типы, меньшие чем int, приводятся к int.
	// 3. Из двух типов выбирается бОльший по размеру
	// 4. Если размер одинаковый, то выбирается unsigned
	return 0;
}
