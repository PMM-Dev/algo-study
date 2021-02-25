// 원숭이 스포츠
// https://www.acmicpc.net/problem/16438
// Memory	: 	2016	KB
// Time		: 	0		ms

/*
	핵심 알고리즘은 구현하였지만
	남은 팀 랜덤 생성 아이디어가 떠오르지 않아
	https://sejinik.tistory.com/144 를 참고하였습니다.
*/

#include <iostream>
#include <algorithm>

using namespace std;

int N, cnt;

char monkeys[7][120];

void f(int sIdx, int eIdx, int depth) {
	if (depth >= 7 || sIdx >= eIdx)
		return;

	cnt = max(cnt, depth);
	int cIdx = (sIdx + eIdx) / 2;
	for (int i = sIdx; i <= eIdx; i++) {
		if (i <= cIdx)
			monkeys[depth][i] = 'A';
		else
			monkeys[depth][i] = 'B';
	}

	f(sIdx, cIdx, depth + 1);
	f(cIdx + 1, eIdx, depth + 1);
}

int main() {
	cin >> N;
	f(1, N, 0);
	for (int i = 0; i <= cnt; i++) {
		for (int j = 1; j <= N; j++) {
			if (monkeys[i][j] == '\0')
				monkeys[i][j] = j % 2 == 0 ? 'A' : 'B';
			cout << monkeys[i][j];
		}
		cout << "\n";
	}
	// 	팀 배치가 중복되도 된다니...
	while (cnt != 6) {
		for (int i = 0; i < N; i++) {
			if (i & 1)
				cout << 'A';
			else
				cout << 'B';
		}
		cout << "\n";
		cnt++;
	}
	return 0;
}