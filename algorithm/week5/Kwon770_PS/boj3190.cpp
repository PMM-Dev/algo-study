// Memory : 2016 KB
// Time : 0 ms
#include <iostream>
#include <deque>
#include <utility>
#include <vector>
#define endl '\n';
using namespace std;

int dRow[] = {-1, 0, 1, 0};
int dCol[] = {0, 1, 0, -1};
int n, k, l;
deque<pair<int, int>> snake(1, make_pair(1, 1));

bool checkCollision() {
	int row = snake.back().first;
	int col = snake.back().second;
	snake.pop_back();
	if (row <= 0 || col <= 0 || row > n || col > n)
		return true;

	for (pair<int, int> part : snake) {
		if (row == part.first && col == part.second)
			return true;
	}

	snake.push_back(make_pair(row, col));
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<pair<int, int>> apples;
	vector<pair<int, char>> directions;
	cin >> n >> k;
	while (k--) {
		int r, c;
		cin >> r >> c;
		apples.push_back(make_pair(r, c));
	}	
	cin >> l;
	while (l--) {
		int x;
		char c;
		cin >> x >> c;
		directions.push_back(make_pair(x, c));
	}

	// 0 top 1 right 2 bottom 3 left
	int curRow = 1, curCol = 1, dir = 1, time = 0;
	auto nextDirection = directions.begin();
	while (true) {	
		time++;

		curRow += dRow[dir];
		curCol += dCol[dir];	

		snake.push_back(make_pair(curRow, curCol));
		if (checkCollision()) break;

		bool isAteApple = false;
		for (auto iter = apples.begin(); iter != apples.end(); iter++) {
			if (curRow == (*iter).first && curCol == (*iter).second) {
				apples.erase(iter);
				isAteApple = true;
				break;
			}
		}
		if (!isAteApple) snake.pop_front();

		if ((*nextDirection).first == time) {
			if ((*nextDirection).second == 'L') dir--;
			else dir++;
			dir = dir == 4 ? 0 : dir;
			dir = dir == -1 ? 3 : dir;
			nextDirection++;
		}	
	} 
	cout << time;
	return 0;
}
