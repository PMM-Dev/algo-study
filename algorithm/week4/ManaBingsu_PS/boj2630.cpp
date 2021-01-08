// 색종이 만들기
// https://www.acmicpc.net/problem/2630
// Memory	:	2080 KB
// Time		:	4 ms

#include <iostream>

using namespace std;

int N;
int arr[128][128];
int white = 0, blue = 0;

void recursion(int n, int r, int c) {
	if (n == 2) {
		white = arr[r][c] == 0 ? white + 1 : white;
		blue = arr[r][c] == 1 ? blue + 1 : blue;
		return;
	}

	int num = arr[r][c];
	for (int i = r; i < r + n / 2; i++) {
		for (int j = c; j < c + n / 2; j++) {
			if (arr[i][j] != num) {
				i = r + n / 2;
				j = c + n;
				num = -1;
			}
		}
	}
	if (num != -1) {
		white = num == 0 ? white + 1 : white;
		blue = num == 1 ? blue + 1 : blue;
		return;
	}
	recursion(n / 2, r, c);
	recursion(n / 2, r + n / 4, c);
	recursion(n / 2, r, c + n / 4);
	recursion(n / 2, r + n / 4, c + n / 4);
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
	recursion(N, 0, 0);
	recursion(N, N / 2, 0);
	recursion(N, 0, N / 2);
	recursion(N, N / 2, N / 2);
	cout << white << "\n";
	cout << blue << "\n";
	return 0;
}
