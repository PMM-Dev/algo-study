// ·Îº¿ ½Ã¹Ä·¹ÀÌ¼Ç
// https://www.acmicpc.net/problem/2174
// Memory	:	2064 KB
// Time		:	0 ms

#include <iostream>
#include <utility>
#include <map>

using namespace std;

int A, B;
int N, M;
int inputs[100][100];
int result;

map<int, pair<int, int>> robotLocs;
map<int, int> robotDirs;

int command(int id, char cmd) {
	int x = robotLocs[id].first;
	int y = robotLocs[id].second;

	if (cmd == 'R')
		robotDirs[id] = robotDirs[id] - 1 < 0 ? 3 : robotDirs[id] - 1;
	else if (cmd == 'L')
		robotDirs[id] = (robotDirs[id] + 1) % 4;
	else {
		switch (robotDirs[id]) {
		case 0:
			robotLocs[id] = pair<int, int>(x + 1, y);
			break;
		case 1:
			robotLocs[id] = pair<int, int>(x, y + 1);
			break;
		case 2:
			robotLocs[id] = pair<int, int>(x - 1, y);
			break;
		case 3:
			robotLocs[id] = pair<int, int>(x, y -1);
			break;
		default:
			break;
		}

		inputs[y][x] = 0;
		x = robotLocs[id].first;
		y = robotLocs[id].second;

		if (x < 0 || y < 0 || x >= A || y >= B) {
			cout << "Robot " << id << " crashes into the wall" << "\n";
			return 1;
		}
		if (inputs[y][x] != 0) {
			cout << "Robot " << id << " crashes into robot " << inputs[y][x] << "\n";
			return 2;
		}
		inputs[y][x] = id;
	}
	return 0;
}

int main() {	
	robotLocs = map<int, pair<int, int>>();
	robotDirs = map<int, int>();

	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)
			inputs[i][j] = 0;

	cin >> A >> B;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int x, y;
		char dir;

		cin >> x >> y >> dir;
		inputs[y - 1][x - 1] = i + 1;
		robotLocs.insert(pair<int, pair<int, int>>(i + 1, pair<int, int>(x - 1, y - 1)));
		switch(dir) {
		case 'E':
			robotDirs.insert(pair<int, int>(i + 1, 0));
			break;
		case 'N':
			robotDirs.insert(pair<int, int>(i + 1, 1));
			break;
		case 'W':
			robotDirs.insert(pair<int, int>(i + 1, 2));
			break;
		case 'S':
			robotDirs.insert(pair<int, int>(i + 1, 3));
			break;
		default:
			break;
		}

	}
	for (int i = 0; i < M; i++) {
		int id, repeat;
		char cmd;
		cin >> id >> cmd >> repeat;

		while (repeat--) {
			result = command(id, cmd);
			if (result != 0)
				break;
		}
		if (result != 0)
			break;
	}
	if (result == 0)
		cout << "OK" << "\n";
	return 0;
}
