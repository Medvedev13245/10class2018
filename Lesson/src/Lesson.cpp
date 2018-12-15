#include <iostream>
#include <string>
#include <vector>
using namespace std;

void FindF(){
	string str;
	cin >> str;
	bool flag = false;
		int index = 0;

	for (int i = 0; i < str.size(); i++){
			if (str[i] == 'f'){
				if (flag){
					index = i;
					break;
				}
				flag = true;
			}
		}

		int f = 0;
		for(auto x : str){
			f++;
			if (x == 'f'){
				if (flag){
					index = f;
					break;
				}
				flag = true;
			}
		}
}

bool CheckPalindrom(string s){
	int length = s.size();
	for(int i = 0; i < length / 2; i++){
		if (s[i] != s[length - 1 - i]){
			return false;
		}
	}
	return true;
}
// void, char, int, bool, string, double
int Factorial(int n){
	int b = 1;
	for(int i = 1; i <= n; i++){
		b *= i;
	}
	return b;
}

int Factorial2(int n){
	if (n == 1){
		return 1;
	}
	return n * Factorial2(n - 1);
}

int F(int n){
	if (n > 3){
		return F(n - 3) + F(n - 2);
	}
	else{
		return 1;
	}
}


int main() {
	cout << F(12) << endl;
	return 0;
}
