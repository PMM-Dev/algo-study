// Memory : 2020KB
// Time : 0 mx
#include <iostream>
#include <vector>
#include <deque>
#define endl "\n"
using namespace std;

#define leftSurface 6
#define rightSurface 2
vector<deque<int>> wheels(4, deque<int>(8));

void rotate(int idx, int dir) {
	if (dir == 1) {
		int tmp = wheels[idx].back();
		wheels[idx].pop_back();
		wheels[idx].push_front(tmp);
	} else {
		int tmp = wheels[idx].front();
		wheels[idx].pop_front();
		wheels[idx].push_back(tmp);
	}

}


void simulate(int idx, int dir) {
	int left = wheels[idx][leftSurface];
	int leftDir= dir;
	for (int i = idx; i > 0; i--) {
		if (left  == wheels[i - 1][rightSurface]) break;

		left = wheels[i - 1][leftSurface];
		leftDir *= -1;
		rotate(i - 1, leftDir);
	}

	int right = wheels[idx][rightSurface];
	int rightDir = dir;
	for (int i = idx; i < 3; i++) {
		if (right  == wheels[i + 1][leftSurface]) break;

		right = wheels[i + 1][rightSurface];
		rightDir *= -1;
		rotate(i + 1, rightDir);
	}	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 8; j++) {
			wheels[i][j] = cin.get() - '0';
		}
		cin.get();

	}

	int k;
	cin >> k;
	while (k--) {
		int idx, dir;
		cin >> idx >> dir;

		simulate(idx - 1, dir);
		rotate(idx - 1, dir);
	}

	int score = 0;
	for (int i = 0; i < 4; i++) {
		if (wheels[i][0] == 0) continue;

		switch (i) {
			case 0:
				score += 1;
				break;
			case 1:
				score += 2;
				break;
			case 2:
				score += 4;
				break;
			case 3:
				score += 8;
				break;
		}
	}
	cout << score;

	return 0;
}
