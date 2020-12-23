// ¿¬±¸¼Ò
// https://www.acmicpc.net/problem/14502
// Memory	:	2016 KB
// Time		:	192 ms

#include <iostream>

using namespace std;

int N, M;
int inputs[8][8];
int copies[8][8];
int maxNum = 0;

void diffuse(int i, int j) {
	if (i < 0 || j < 0 || i >= N || j >= M)
		return;
	if (copies[i][j] != 0)
		return;
	copies[i][j] = 2;
	diffuse(i + 1, j);
	diffuse(i - 1, j);
	diffuse(i, j + 1);
	diffuse(i, j - 1);
}

void diffuseVirus() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			copies[i][j] = inputs[i][j];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (inputs[i][j] == 2) {
				diffuse(i + 1, j);
				diffuse(i - 1, j);
				diffuse(i, j + 1);
				diffuse(i, j - 1);
			}
		}
	}
}

void process(int depth, int i, int j) {
	if (depth == 3) {
		diffuseVirus();

		int num = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (copies[i][j] == 0)
					num++;
			}
		}
		if (maxNum < num)
			maxNum = num;
		return;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (inputs[i][j] == 0) {
				inputs[i][j] = 1;
				process(depth + 1, i, j);
				inputs[i][j] = 0;
			}
		}
	}
}

int main() {	
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> inputs[i][j];

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			copies[i][j] = inputs[i][j];
	process(0, 0, 0);
	cout << maxNum << "\n";
	return 0;
}
