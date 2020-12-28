// Mempry : 2032 Kb
// Time : 0 ms
#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;

int n, white = 0, blue = 0;
bool paper[129][129];

void divide(int startX, int endX, int startY, int endY) {
	bool isComplete = true;
	int initColor = paper[startY][startX];
	for (int i = startY; i <= endY; i++) {
		for (int j = startX; j <= endX; j++) {
			if (initColor != paper[i][j]) {
				isComplete = false;
				i = endY;
				j = endX;
			}
		}
	}


	if (isComplete) {
		if (initColor) blue++;
		else white++;
		return;
	} else {
		int half = (endX - startX + 1) / 2 - 1;
		divide(startX, startX + half, startY, startY + half);
		divide(endX - half, endX, startY, startY + half);
		divide(startX, startX + half, endY - half, endY);
		divide(endX - half, endX, endY - half, endY);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> paper[i][j];
		}
	}

	divide(1, n, 1, n);
	cout << white << endl; 
	cout << blue << endl;

	return 0;
}
