// ¹ì
// https://www.acmicpc.net/problem/3190
// Memory	:	2072	KB
// Time		:	0		ms

#include <iostream>
#include <deque>
#include <vector>
#include <utility>
#include <set>
#include <algorithm>

using namespace std;

class Location
{
public:
	int x;
	int y;

	Location(int x, int y) {
		this->x = x;
		this->y = y;
	}
	bool operator == (const Location& other) const;
	bool operator < (const Location& other) const;
};

bool Location::operator==(const Location& other) const{
	return (this->x == other.x) && (this->y == other.y);
}

bool Location::operator < (const Location& other) const {
	return (this->x < other.x) && (this->y < other.y);
}

int N, K, L;
int board[101][101];
int snakeDirection = 0;
int second = 0;
char command[10001];
deque<Location> snake;

bool setToBoard() {
	int directionX = 0, directionY = 0;
	if (snakeDirection == 0 || snakeDirection == 2) {
		directionX = snakeDirection == 0 ? 1 : -1;
	}
	else {
		directionY = snakeDirection == 1 ? -1 : 1;
	}
	snake.push_front(Location(snake.at(0).x + directionX, snake.at(0).y + directionY));

	if (snake.at(0).x > N || snake.at(0).y > N || snake.at(0).x < 1 || snake.at(0).y < 1) {
		return false;
	}
	
	set<Location> locationSet = set<Location>();
	deque<Location>::iterator iter = snake.begin();

	for (; iter != snake.end(); iter++) {
		set<Location>::iterator it = std::find(locationSet.begin(), locationSet.end(), *iter);
		if (it != locationSet.end()) {
			return false;
		}
		else {
			locationSet.insert(*iter);
		}
	}

	if (board[snake.at(0).y][snake.at(0).x] != 2) {
		snake.pop_back();
	}
	else {
		board[snake.at(0).y][snake.at(0).x] = 0;
	}

	second++;
	return true;
}

int main() {
	fill_n(command, 10001, 0);
	cin >> N >> K;
	snake = deque<Location>();
	snake.push_front(Location(1, 1));
	while (K--) {
		int x, y;
		cin >> y >> x;
		board[y][x] = 2;
	}
	cin >> L;

	while (L--) {
		int count;
		char type;
		cin >> count >> type;
		command[count] = type;
	}

	bool isEnd = false;
	while (!isEnd) {
		if (!setToBoard())
			isEnd = true;
		if (command[second] != 0) {
			if (command[second] == 'L') {
				snakeDirection = (snakeDirection + 1) % 4;
			}
			else {
				snakeDirection = snakeDirection - 1 < 0 ? 3 : snakeDirection - 1;
			}
		}
	}
	cout << second + 1 << "\n";
	return 0;
}