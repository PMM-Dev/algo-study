// Memory : 2016 KB
// Time : 0 ms

#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;

vector<int> test, arr;
int k;

void print() {
	for (int ele : arr) {
		cout << ele << " ";
	}
	cout << endl;
}

void recursion(int idx) {
	for (int i = idx; i < k; i++) {
		arr.push_back(test[i]);

		if ((int)arr.size() == 6) print();
		else recursion(i + 1);
		
		arr.pop_back();
	}	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (true) {
		cin >> k;
		if (!k) break;

		for (int i = 0; i < k; i++) {
			int tmp;
			cin >> tmp;
			test.push_back(tmp);
		}
		recursion(0);
		cout << endl;
		test.clear();
	}
	
	return 0;
}
