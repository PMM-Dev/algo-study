
#include <bits/stdc++.h>

#define endl "\n"

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t, a, b;

	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> a >> b;
		int tmp = 1;
		for (int j = 0; j < b; j++) {
			tmp *= a;
			tmp %= 10;

			if (tmp == 0) {
				tmp = 10;
				break;
			}

		}
		cout << tmp << endl;
	}

	return 0;
}
