// 단어 뒤집기 2
// https://www.acmicpc.net/problem/17413
// Memory	:	2264 KB
// Time		:	4 ms

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string str;

int main(){
	int strLen = 0;
	int index = 0;
	int pick = 0;
	bool isWord = false;
	bool isTag = false;

	getline(cin, str);
	strLen = str.size();
	while (index < strLen) {
		if (isTag) {
			if (str[index] == '>')
				isTag = false;
		}
		else {
			if (isWord) {
				if (!isalnum(str[index])) {
					if (str[index] == '<')
						isTag = true;
					reverse(begin(str) + pick, begin(str) + index);
					isWord = false;
				}
			}
			else {
				if (isalnum(str[index])) {
					isWord = true;
					pick = index;
				}
				else if (str[index] == '<')
					isTag = true;
			}
		}
		index++;
	}
	if (isWord)
		reverse(begin(str) + pick, begin(str) + index);
	cout << str << "\n";
	return 0;
}
