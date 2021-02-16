// µå·¡°ï Ä¿ºê
// https://www.acmicpc.net/problem/15685
// Memory	: 2020	KB
// Time		: 0		ms

#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int main() {
	int N, x, y, d, g,result = 0;
	cin >> N;

	bool grid[101][101];
	fill_n(&grid[0][0], 101 * 101, false);

	for (int j = 0; j < N; j++) {
		cin >> x >> y >> d >> g;
		int sequence[1100];
		fill_n(sequence, 1100, -1);
		sequence[0] = d;

		int half = 0, end = 1;

		for (int i = 0; i < g; i++){
			half = pow(2, i);
			end = pow(2, i + 1);
			for (int j = half; j < end; j++)
				sequence[j] = (sequence[end - j - 1] + 1) % 4;
		}
		grid[y][x] = true;
		for (int i = 0; i < end; i++) {
			x += dx[sequence[i]];
			y += dy[sequence[i]];
			grid[y][x] = true;
		}

	}
	
	for (int i = 0; i < 101 - 1; i++)
		for (int j = 0; j < 101 - 1; j++)
			result = (grid[i][j] && grid[i + 1][j] && grid[i][j + 1] && grid[i + 1][j + 1]) ? result + 1 : result;
	cout << result << "\n";

	return 0;
}