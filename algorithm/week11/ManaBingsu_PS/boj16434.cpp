// µå·¡°ï ¾Ø ´øÀü
// https://www.acmicpc.net/problem/16434
// Memory	: 6752	KB
// Time		: 168	ms

#include <iostream>
#include <algorithm>
#include <vector>

typedef long long dl;
using namespace std;

/// <summary>
/// 
/// </summary>


struct Room {
	int t;
	dl a, h;
};

dl N, ATK;
vector<Room> rooms;

bool simulate(dl maxHP) {
	dl curHP = maxHP;
	dl atk = ATK;
	for (int i = 0; i < rooms.size(); i++) {
		Room room = Room();
		room.t = rooms[i].t;
		room.a = rooms[i].a;
		room.h = rooms[i].h;

		if (room.t == 1) {
			if (((room.h - 1) / atk) > ((curHP - 1) / room.a))
				return false;
			curHP -= (room.h - 1) / atk * room.a;
		}
		else {
			curHP = curHP + room.h > maxHP ? maxHP : curHP + room.h;
			atk += room.a;
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> ATK;
	dl result = 0;

	for (int i = 0; i < N; i++) {
		Room room = Room();
		cin >> room.t >> room.a >> room.h;
		rooms.push_back(room);
	}
	dl left = 1, right = 1e18;
	while (left <= right) {
		dl mid = (left + right) / 2;
		if (!simulate(mid))
			left = mid + 1;
		else {
			result = mid;
			right = mid - 1;
		}

	}
	cout << result << "\n";
	return 0;
}