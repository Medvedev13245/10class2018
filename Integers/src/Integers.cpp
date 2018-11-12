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
// ������� �������������� �����
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
	int32_t a; // ��������.������ �������� � ������ 32 ����
	uint32_t b; //�����������. ������ �������� � ������ 32 ����
	int16_t c; // ��������. ������ ������� 16 ���
	uint16_t d; //�����������. ������ �������� 16 ���
	int8_t e; // ��������. ������ �������� 8 ���
	uint8_t f; //�����������. ������ �������� 8 ���
	int64_t g; //��������. ������ �������� 64 ����
	uint64_t h; // �����������. ������ �������� 64 ����
}

// sizeof() - ������� ��� ���������� ������� ���� ��� ����������
// ������ ������� ����� - include <limits>; numeric_limits<type>::min(); max()

void FPlusMinusimits(){
	cout << numeric_limits<int>::max() + 1 << " " << numeric_limits<int>::min() << endl;
	cout << numeric_limits<int>::min() - 1 << " " << numeric_limits<int>::max();
}
int main() {
	unsigned int x = numeric_limits<unsigned int>::min() - 1;
	cout << x << endl;
	// 1. ����� ���������� ��� ���� ���������� � ������� ����
	// 2. ��� ����, ������� ��� int, ���������� � int.
	// 3. �� ���� ����� ���������� ������� �� �������
	// 4. ���� ������ ����������, �� ���������� unsigned
	return 0;
}
