// 아기 상어
// https://www.acmicpc.net/problem/16236
// Memory	:	2020	KB
// Time		:	0		ms

#include <iostream>
#include <tuple>
#include <queue>

using namespace std;

int N;
int board[20][20];
int memo[20][20];
int babySize = 2;
bool isDetect = false;
int eatStack = 0;
int second = 0;
int babyRow, babyCol;
int goalRow, goalCol;

bool isOutside(int row, int col) {
	return (row < 0 || row >= N || col < 0 || col >= N);
}

void initializeMemo() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] > babySize)
				memo[i][j] = -2;
			else
				memo[i][j] = 1000;
		}
	}
}

void judge() {
	int minDistance = 999;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] != 0 && board[i][j] < babySize && memo[i][j] < minDistance) {
				minDistance = memo[i][j];
				isDetect = true;
				goalRow = i;
				goalCol = j;
			}
		}
	}
	if (minDistance != 999)
		second += minDistance;
}

void getNearestFish(int babyRow, int babyCol) {
	int depth = 0;
	queue<tuple<int, int, int>> q;
	q.push(make_tuple(babyRow, babyCol, 0));
	memo[babyRow][babyCol] = 0;
	while (!q.empty()) {
		tuple<int, int, int> temp = q.front();
		q.pop();
		auto row = get<0>(temp);
		auto col = get<1>(temp);
		auto depth = get<2>(temp);

		if (!isOutside(row - 1, col) && memo[row - 1][col] == 1000) {
			memo[row - 1][col] = depth + 1;
			q.push(make_tuple(row - 1, col, depth + 1));
		}
		if (!isOutside(row, col - 1) && memo[row][col - 1] == 1000) {
			memo[row][col - 1] = depth + 1;
			q.push(make_tuple(row, col - 1, depth + 1));
		}
		if (!isOutside(row, col + 1) && memo[row][col + 1] == 1000) {
			memo[row][col + 1] = depth + 1;
			q.push(make_tuple(row, col + 1, depth + 1));
		}
		if (!isOutside(row + 1, col) && memo[row + 1][col] == 1000) {
			memo[row + 1][col] = depth + 1;
			q.push(make_tuple(row + 1, col, depth + 1));
		}
	}
}

void process() {
	do {
		isDetect = false;
		initializeMemo();
		getNearestFish(babyRow, babyCol);
		judge();
		if (isDetect) {
			eatStack++;
			if (eatStack >= babySize) {
				babySize++;
				eatStack = 0;
			}
			board[goalRow][goalCol] = 0;
			babyRow = goalRow;
			babyCol = goalCol;

		}
	} while (isDetect);
	cout << second << "\n";
}

void input() {
	cin >> N;
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cout.tie(0);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int num;
			cin >> num;
			if (num == 9) {
				babyRow = i;
				babyCol = j;
			}
			else
				board[i][j] = num;
		}
	}
}

int main() {
	input();
	process();
	return 0;
}
