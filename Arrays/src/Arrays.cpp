#include <iostream>
using namespace std;

void FirstLesson(){
	const int N = 20;
	int A[N]; // тип им€ [размерность]
	// ввод с клавиатуры
	for (int i = 0; i < N; i++){
		cin >> A[i];
	}

	// вывод на экран
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

	// количество четных и нечетных элементов и вывести на экран
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
	// подсчитать количество элементов, которые четные и больше 13
	for (int i = 0; i < N; i++){
		if ((A[i] % 2 == 0) && (A[i] > 13)){
			c++;
		}
	}
	// в массиве хран€тс€ значени€ температур в одном из мес€цев
	// найти среднюю температуру
	int s = 0;
	for (int i = 0; i < N; i++){
		s += A[i]; // s = s + A[i]
	}
	s = s / N;
	cout << s << endl;

	// в массиве хран€тс€ значени€ температур в одном из мес€цев
	// найти среднюю температуру в те дни, когда температура была < 0
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

	// найти количество пар элементов, в которых либо оба четные либо
	// сумма меньше 43

	for (int i = 0; i < N -1; i++){
		if ((A[i] % 2 == 0 && A[i+1] % 2 == 0) || (A[i] + A[i+1] < 43)){
			k++;
		}
	}
	return 0;
}
