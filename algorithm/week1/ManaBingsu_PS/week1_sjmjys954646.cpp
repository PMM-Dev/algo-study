#include <iostream>
#include <algorithm>

#define MAX_INNING 50

using namespace std;

int N;
int record[MAX_INNING][9];
int base[9] = { 0, };

int human_list[9] = { 0, };
int memo[9] = { 0, };

int inning_index = 0;
int result = 0;
int score = 0;

int baseToBase(int hitter_index, int value) {
	if (value == 0)
		return 1;
	for (int i = 0; i < 9; i++) {
		if (i != hitter_index)
			base[i] = base[i] != 0 ? base[i] + value : base[i];
		else
			base[i] += value;
		if (base[i] >= 4) {
			base[i] = 0;
			score++;
		}
	}
	return 0;
}

int play_inning(int human_index)
{
	for (int i = 0; i < 9; i++) base[i] = 0;
	int out = 0;
	while (out < 3) {
		if (base[human_list[human_index]] == 0)
			out += baseToBase(human_list[human_index], record[inning_index][human_list[human_index]]);
		human_index = human_index + 1 < 9 ? human_index + 1 : 0;
	}
	return human_index;
}

void simulation() {
	score = 0;
	inning_index = 0;
	int first_human_index = 0;
	for (int i = 0; i < N; i++){
		first_human_index = play_inning(first_human_index);
		inning_index++;
	}
	if (score > result)
		result = score;
}

void mix(int depth) {
	if (depth >= 9) {
		if (human_list[3] != 0)
			return;
		simulation();
		return;
	}
	for (int i = 0; i < 9; i++) {
		if (memo[i] == 0){
			memo[i] = 1;
			human_list[depth] = i;
			mix(depth + 1);
			memo[i] = 0;
		}
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 9; j++)
			cin >> record[i][j];
	}
	mix(0);
	cout << result << "\n";
	return 0;
}
