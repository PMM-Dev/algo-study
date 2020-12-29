// Memory : 2200 KB
// Time : 0 ms
//
#include <iostream>
#include <cmath>
#define endl "\n"
using namespace std;

int n, r, c, ans = 0;

void recursion (int size, int startX, int startY) {
	int half = size / 2;

	// 사분면 체크
	bool overHalfX = startX + half <= c ? true : false;
	bool overHalfY = startY + half <= r ? true : false;
	int part;
	if (overHalfY) {
		if (overHalfX) part = 3;
		else part = 2;		
	} else {
		if (overHalfX) part = 1;
		else part = 0;
	}		
	// 지난 사분면들 더하기
	ans += part * (half * half);

	if (size == 1)
		return;

	switch (part) {
		case 0:
			recursion(half, startX, startY);
			break;
		case 1 :
			recursion(half, startX + half, startY);
			break;
		case 2:
			recursion(half, startX, startY + half);
			break;
		case 3:
			recursion(half, startX + half, startY + half);
			break;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> r >> c;
	recursion(pow(2, n), 0, 0);
	// size start from 0, but did't add itself position
	cout << ans;
	return 0;
}
