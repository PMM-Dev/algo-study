// Memory : 2016 KB
// Time : 0 ms
//
#include <iostream>
#include <vector>
#define endl "\n"

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;
	vector<int> vec(n);
	for (int i = 0; i < n; i++) {
		cin >> vec[i];
	}

	vector<int> ans;
	for (int i = n - 1; i >= 0; i--) {

		int cnt = 0;
		bool isYet = true;
		auto iter = ans.begin();

		while (iter != ans.end()) {
			if (vec[i] == cnt) {
				ans.insert(iter, i + 1); 
				isYet = false;
				break;
			}

			if (i + 1 < *iter) {
				cnt++;
			}

			iter++;
		}

		if (isYet) {
			ans.insert(iter, i + 1);
		}
	}

	for (int tmp : ans) {
		cout << tmp << " ";
	}	

	return 0;
}
