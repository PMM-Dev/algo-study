// 문자열 복사
// https://www.acmicpc.net/problem/2195
// Memory	:	2020 KB
// Time		:	108 ms

#include <iostream>
#include <string>

using namespace std;

string S, P;

int main() {
	cin >> S >> P;
	int pSize = P.size();
	int counter = 0;
	for (int i = 0; i < pSize; i++) {
		counter++;
		if (i == pSize - 1)
			break;
		for (int j = pSize - 1; j >= i; j--) {
			string str = P.substr(i, j - i + 1);
			int find = S.find(str);
			if (find != (int)string::npos) {
				i += str.size() - 1;
				break;
			}
		}
	}
	cout << counter << "\n";
	return 0;
}
