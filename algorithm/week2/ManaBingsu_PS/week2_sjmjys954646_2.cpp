// 여우는 어떻게 울지?
// https://www.acmicpc.net/problem/9536
// Memory	:	2024 KB
// Time		:	0 ms

#include <iostream>
#include <string>
#include <set>

using namespace std;

int T;

int main() {
	cin >> T;
	set<string> types;
	for (int i = 0; i < T; i++) {
		types = set<string>();
		string buffer;
		getline(cin, buffer);
		string str;
		getline(cin, str);
		while (true) {
			string str1, str2, str3;
			cin >> str1 >> str2 >> str3;
			if (str1 == "what") {
				cin >> str2 >> str3;
				break;
			}
			types.insert(str3);
		}
		string check = "";
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == ' ') {
				if (types.find(check) == types.end())
					cout << check << " ";
				check = "";
			}
			else
				check += str[i];
		}
		if (types.find(check) == types.end()) {
			cout << check << " ";
			check = "";
		}
		cout << "\n";
	}
	return 0;
}
