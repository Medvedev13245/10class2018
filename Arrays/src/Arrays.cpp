#include <iostream>
using namespace std;

void FirstLesson(){
	const int N = 20;
	int A[N]; // ��� ��� [�����������]
	// ���� � ����������
	for (int i = 0; i < N; i++){
		cin >> A[i];
	}

	// ����� �� �����
	for (int i = 0; i < N; i++){
		cout << A[i] << " ";
	}
}

void CountGreater0(){
	const int N = 10;
	int A[N];

	for (int i = 0; i < N; i++){
		cin >> A[i];
	}
	int k = 0;

	for (int i = 0; i < N; i++){
		if (A[i] > 0){
			k++;
		}
	}
	cout << k;

	// ���������� ������ � �������� ��������� � ������� �� �����
	int ch = 0;
	int nCh = 0;

	for (int i = 0; i < N; i++){
		if (A[i] % 2 == 0){
			ch++;
		}
		else{
			nCh++;
		}
	}
	int c = 0;
	// ���������� ���������� ���������, ������� ������ � ������ 13
	for (int i = 0; i < N; i++){
		if ((A[i] % 2 == 0) && (A[i] > 13)){
			c++;
		}
	}
	// � ������� �������� �������� ���������� � ����� �� �������
	// ����� ������� �����������
	int s = 0;
	for (int i = 0; i < N; i++){
		s += A[i]; // s = s + A[i]
	}
	s = s / N;
	cout << s << endl;

	// � ������� �������� �������� ���������� � ����� �� �������
	// ����� ������� ����������� � �� ���, ����� ����������� ���� < 0
	int s = 0;
	int k = 0;
	for (int i = 0; i < N; i++){
		if (A[i] < 0){
			s += A[i];
			k++;
		}
	}
	s = s / k;
}

int main() {
	const int N = 100;
	int A[N];

	for (int i = 0; i < N; i++){
		cin >> A[i];
	}

	// ����� ���������� ��� ���������, � ������� ���� ��� ������ ����
	// ����� ������ 43

	for (int i = 0; i < N -1; i++){
		if ((A[i] % 2 == 0 && A[i+1] % 2 == 0) || (A[i] + A[i+1] < 43)){
			k++;
		}
	}
	return 0;
}
