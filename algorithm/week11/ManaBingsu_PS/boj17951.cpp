// 흩날리는 시험지 속에서 내 평점이 느껴진거야
// https://www.acmicpc.net/problem/17951
// Memory	: 2288		KB
// Time		: 28		ms

#include <iostream>
#include <algorithm>
#define SIZE 100000

using namespace std;

/// <summary>
/// 여러 그룹 중 최소의 점수를 갖는다는 것은
/// 모든 그룹이 최소 점수 이상을 갖는다는 것과 같다.
/// 따라서 이분탐색을 통해 0 ~ 20 * N 범위에서
/// 최대한 큰 최소 점수를 찾아야 한다.
/// </summary>


int main() {
	int N, K;
	int input[SIZE];
	cin >> N >> K;
	for (int i = 0; i < N; cin >> input[i], i++);
	int left = 0, right = 20 * N;
	int mid = (left + right) / 2;
	while (left + 1 < right) {
		mid = (left + right) / 2;
		int groupNum = 0, counter = 0;
		for (int i = 0; i < N; i++) {
			counter += input[i];
			if (counter >= mid) {
				groupNum++;
				counter = 0;
			}
		}
		if (groupNum >= K)
			left = mid;
		else
			right = mid;
	}
	cout << left << "\n";
	return 0;
}