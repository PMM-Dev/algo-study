// 2048(Easy)
// https://www.acmicpc.net/problem/12100
// Memory	:	2020 KB
// Time		:	28 ms

#include <iostream>
#include <algorithm>

using namespace std;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int input[21][21];
int board[21][21];
bool memo[21][21];

int sequence[5];

int N;

int result;

void translate(int srcX, int srcY, int dir){
	if (board[srcY][srcX] == 0)
		return ;

	int destX = srcX, destY = srcY;
	for (int i = 0; i < N; i++) {
		destX += dx[dir];
		destY += dy[dir];
		if (destX < 0 || destX > N - 1 || destY < 0 || destY > N - 1)
			return;
		if (memo[destY][destX])
			return;
		if (board[destY][destX] != 0) {
			if (board[destY][destX] == board[srcY][srcX]) {
				board[destY][destX] *= 2;
				board[srcY][srcX] = 0;
				memo[destY][destX] = true;
			}
			return;
		}
		else {
			board[destY][destX] = board[srcY][srcX];
			board[srcY][srcX] = 0;
			srcX = destX;
			srcY = destY;
		}
	}
}

void optimizedLoop(int dir) {
	if (dir == 0) {
		for (int i = N - 1; i >= 0; i--)
			for (int j = 0; j < N; j++)
				translate(i, j, dir);
	}
	else if (dir == 1) {
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				translate(i, j, dir);
	}
	else if (dir == 2) {
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				translate(j, i, dir);
	}
	else {
		for (int i = N - 1; i >= 0; i--)
			for (int j = 0; j < N; j++)
				translate(j, i, dir);
	}
}

void process(int depth) {

	if (depth == 5) {
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				board[i][j] = input[i][j];
		for (int i = 0; i < 5; i++) {
			
			for (int i = 0; i < N; i++)
				for (int j = 0; j < N; j++)
					memo[i][j] = false;
			optimizedLoop(sequence[i]);
		}
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				result = result < board[i][j] ? board[i][j] : result;
		return;
	}

	for (int i = 0; i < 4; i++) {
		sequence[depth] = i;
		process(depth + 1);
		sequence[depth] = -1;
	}
}

int main() {
	cin >> N;
	fill_n(sequence, 5, -1);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> input[i][j];
	result = 0;
	process(0);
	cout << result << endl;
	return 0;
}