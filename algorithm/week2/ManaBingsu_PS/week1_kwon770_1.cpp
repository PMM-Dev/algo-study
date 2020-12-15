// 명령 프롬프트
// https://www.acmicpc.net/problem/1032
// Memory	:	2020 KB
// Time		:	0 ms

#include <iostream>
#include <string>
#define SIZE 50

using namespace std;

int N;
string strs[SIZE];
int check[SIZE] = { 0, };

int main(){
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> strs[i];
	}
	int strLen = strs[0].size();
	for (int i = 0; i < strLen; i++) {
		bool isMatch = true;
		for (int j = 0; j < N; j++) {
			isMatch = strs[j][i] == strs[0][i];
			if (!isMatch) {
				break;
			}
		}
		check[i] = isMatch ? 1 : 0;
	}
	for (int i = 0; i < strLen; i++) {
		if (check[i]) {
			cout << strs[0][i];
		}
		else {
			cout << "?";
		}
	}
	cout << "\n";
	return 0;
}
