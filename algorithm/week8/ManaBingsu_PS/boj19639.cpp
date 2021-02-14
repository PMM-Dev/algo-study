// ¹èÆ²·Î¾â
// https://www.acmicpc.net/problem/19639
// Memory	:	5100	KB
// Time		:	136		ms

#include <iostream>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;

typedef pair<int, int> pi;

priority_queue<pi, vector<pi>, less<pi>> enemies;
priority_queue<pi, vector<pi>, greater<pi>> items;

int main()
{
	int X, Y, M, input, totalDamage = 0, totalHeal = 0, index = 0;

	cin >> X >> Y >> M;
	while (X--) {
		cin >> input;
		enemies.push(make_pair(input, ++index));
		totalDamage += input;
	}
	index = 0;
	while (Y--) {
		cin >> input;
		items.push(make_pair(input, ++index));
		totalHeal += input;
	}

	if (M + totalHeal - totalDamage <= 0) {
		cout << 0 << "\n";
		return 0;
	}

	int currentHP = M;
	
	while (!enemies.empty() || !items.empty()) {
		if ((currentHP <= M / 2 && !items.empty()) || enemies.empty()) {
			int heal = items.top().first;
			currentHP += heal;
			cout << items.top().second << "\n";
			items.pop();
		}
		else {
			int damage = enemies.top().first;
			currentHP -= damage;
			cout << "-" << enemies.top().second << "\n";
			enemies.pop();
		}
	}
	
	return 0;
}
