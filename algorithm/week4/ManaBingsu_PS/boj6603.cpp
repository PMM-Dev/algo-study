// ·Î¶Ç
// https://www.acmicpc.net/problem/6603
// Memory	:	2016 KB
// Time		:	0 ms

#include <iostream>

using namespace std;

int arr[13];
int memo[13];
int N;

void recursion(int depth, int index) {
	if (depth == 6) {
		for (int i = 0; i < 13; i++) {
			if (memo[i] != 0) {
				cout << arr[i] << " ";
			}
		}
		cout << "\n";
		return;
	}

	for (int i = index; i < N; i++) {
		if (memo[i] == 0) {
			memo[i] = 1;
			recursion(depth + 1, i + 1);
			memo[i] = 0;
		}
	}
}

int main() {
	N = -1;
	while (N != 0) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> arr[i];
		}
		recursion(0, 0);
		cout << "\n";
	}
	return 0;
}
