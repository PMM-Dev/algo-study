#include <iostream>
#include <stack>
#define endl "\n"
using namespace std;

string str;
stack<char> checker;
int idx = 0;

int recursion() {
	int total = 0;

	while (idx < (int)str.length()) {
		if (str[idx] == '(') {
			idx++;
			total += 2 * recursion();
		} else if (str[idx] == '[') {
			idx++;
			total += 3 * recursion();
		} else if (str[idx] == ')' || str[idx] == ']') {
			idx++;
			return total == 0 ? 1 : total;
		}
	}

	return total;
}

bool check() {
	while(!checker.empty()) checker.pop();

	for (int i = 0; i < (int)str.length(); i++) {
		if (str[i] == '(' || str[i] == '[') {
			checker.push(str[i]);
		} else if (str[i] == ')' || str[i] == ']') {
			if ((checker.size() != 0) &&
					((checker.top() == '(' && str[i] == ')')
					|| (checker.top() == '[' && str[i] == ']'))){
				       checker.pop();
			} else {
	 			return false;
			}
		}
	}

	if (checker.empty()) return true;
	else return false;
}	

int main()
 {
 	ios_base::sync_with_stdio(false);
 	cin.tie(NULL);
 	cout.tie(NULL);

	cin >> str;

	if (check()) {
		cout << recursion();
	} else {
		cout << 0;
	}
	
	return 0;
 }
