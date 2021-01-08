#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#define endl "\n"
using namespace std;

// string의 측면이 아닌 철저히 필요한 값 계산 (길이)를 통해 구현하였으나,
// 12(2) 와 같이 같은 단계 내에서 괄호와 일반 숫자가 섞여있는 경우, 처리되지가 않음.
// 이를 구현할려면 iterator를 통해 원본 string은 변조하는 방식으로 진행해야 할 것으로 보임.
// 다만 string을 erase insert 하는 것이 상당한 시간복잡도를 가지며 비효율적으로 보임

vector<string> substring(string str) {
	vector<string> result;
	auto idxIter = str.begin();
	auto startIter = str.begin();
	auto endIter = str.begin();

	while (idxIter != str.end()) {

		while (startIter != str.end()) {
			if (*startIter == '(') break;
			startIter++;
		}

		int innerbracket = 0;
		while (endIter != str.end()) {
			if (*endIter == '(') {
				innerbracket++;
			} else if (*endIter == ')') {
				if (innerbracket == 0) {
					break;
				} else {
					innerbracket--;
				}
			}		

			endIter++;
		}
		
		if (endIter != str.end()) {
			string tmp;	
			copy(startIter - 1, endIter, back_inserter(tmp));
			result.push_back(tmp);
			startIter = endIter;
		}

		idxIter = endIter;
	}

	return result;
}

int recursion(string str) {
	vector<string> substrs = substring(str);
	if (substrs.size() == 0) {
	} else if (substrs.size() == 1) {
		recur
	} else{
		for (string substr : substrs) {
			vetor<string>
	}	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string str;
	cin >> str;
	cout << recursion(substring(str));

	cout << substring(str);
}
