// 마법사 상어와 파이어볼
// https://www.acmicpc.net/problem/20056
// Memory	: 2020	KB
// Time		: 0		ms

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int dx[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int dy[8] = { 1, 1, 0, -1. -1, -1, 0, 1 };

int N, M, K;

class Ball;
class Grid;
Grid *grids[51][51];

vector<Ball> fireBalls;

class Ball {
public:
	int r;
	int c;
	int m;
	int s;
	int d;

	Grid* grid;

	Ball() {

	}

	Ball(int info[5]) {
		r = info[0];
		c = info[1];
		m = info[2];
		s = info[3];
		d = info[4];
	}

	void Translate() {
		for (int i = 0; i < s; i++) {
			r = r + dy[d] < 0 ? N + dy[d] : (r + dy[d]) % N;
			c = c + dx[d] < 0 ? N + dx[d] : (c + dx[d]) % N;
		}

		grid = grids[r][c];
		grid->balls.push_back(*this);
	}
};
class Grid {
public:
	int r;
	int c;
	vector<Ball&> balls;

	Grid() {

	}

	Grid(int r, int c) {
		this->r = r;
		this->c = c;
	}

	void CheckBig(){
		if (balls.size() < 2)
			return;
		auto it = balls.begin();
		int m = 0, s = 0;
		int dFlag = (*it).d % 2;
		while (it != balls.end()) {
			m += (*it).m;
			s += (*it).s;
			if (dFlag != - 1 && (*it).d % 2 != dFlag)
				dFlag = -1;
			balls.erase(it);
		}

		for (int i = 0; i <= 6; i += 2) {
			auto d = dFlag == -1 ? i + 1 : i;
			if (m / 5 > 0) {
				int bigBallInfo[5] = { this->r, this->c, m / 5, s / (balls.size()), d };
				fireBalls.push_back(Ball(bigBallInfo));
			}
		}
	}
};


int main() {
	cin >> N >> M >> K;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			grids[i][j] = new Grid(i, j);

	for (int i = 0; i < M; i++){
		int ballInfo[5];
		for (int j = 0; j < 5; j++) 
			cin >> ballInfo[j];
		Ball ball = Ball(ballInfo);
		fireBalls.push_back(ball);
	}

	for (int i = 0; i < K; i++) {
		auto it = fireBalls.begin();
		while (it != fireBalls.end()) {
			(*it).Translate();
			it++;
		}

		for (int i = 0; i < N; i++) 
			for (int j = 0; j < N; j++)
				grids[i][j]->CheckBig();
	}

	int result = 0;
	auto it = fireBalls.begin();
	while (it != fireBalls.end()) {
		result += (*it).m;
		it++;
	}

	cout << result << "\n";
	return 0;
}