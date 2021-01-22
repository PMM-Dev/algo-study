// Memory : 2408 KB
// Time : 32 ms
#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	vector<int> cache(100001);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cache[i] = i;
		for (int j = 1; j * j <= i; j++) {
			cache[i] = min(cache[i], cache[i - j*j] + 1);
		}
	}

	cout << cache[n];
	return 0;
}
