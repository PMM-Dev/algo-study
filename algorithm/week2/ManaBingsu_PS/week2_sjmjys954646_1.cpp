// 태보태보 총난타
// https://www.acmicpc.net/problem/17249
// Memory	:	2016 KB
// Time		:	0 ms

#include <iostream>
#include <string>

using namespace std;

string str;

int main() {
	cin >> str;
	int index = 0;
	int spectrum = 0;
	while (str[index] != '(')
		spectrum = str[index++] == '@' ? spectrum + 1 : spectrum;
	cout << spectrum << " ";
	spectrum = 0;
	while (str[index++] != ')');
	while (index < str.size())
		spectrum = str[index++] == '@' ? spectrum + 1 : spectrum;
	cout << spectrum << "\n";
	return 0;
}
