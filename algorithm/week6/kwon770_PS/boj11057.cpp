// Memory : 2016 KB
// Time : 0 ms
#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;

#define MOD 10007
vector<int> cache(10, 1);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 8; j++) {
			cache[j + 1] += cache[j] % MOD;
		}
	}

	int sum = 0;
	for (int i = 0; i < 10; i++) sum += cache[i] % MOD;
	cout << sum % MOD; 

	return 0;
}
