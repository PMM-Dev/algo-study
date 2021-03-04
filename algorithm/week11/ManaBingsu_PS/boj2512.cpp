// ¿¹»ê
// https://www.acmicpc.net/problem/2512
// Memory	: 2016		KB
// Time		: 4			ms

#include <iostream>
#include <algorithm>

using namespace std;

/// <summary>
/// 
/// </summary>

int main() {
	long N, M;
	int *input = new int[10000];
	cin >> N;
	long counter = 0;
	for (int i = 0; i < N; cin >> input[i], counter += input[i++]);
	cin >> M;
	if (counter <= M) {
		cout << *max_element(input, input + N) << "\n";
		return 0;
	}
	long left = 0, right = 1000000000;
	while (left + 1 < right) {
		long mid = (left + right) / 2;
		counter = 0;
		for (int i = 0; i < N; i++) {
			int finalBudget = input[i] > mid ? mid : input[i];
			counter += finalBudget;

		}
		if (counter <= M)
			left = mid;
		else
			right = mid;
	}
	cout << left << "\n";
	return 0;
}