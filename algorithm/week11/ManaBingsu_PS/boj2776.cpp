// 암기왕
// https://www.acmicpc.net/problem/2776
// Memory	: 	KB
// Time		: 	ms

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/// <summary>
/// 안할래
/// </summary>

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T, N, M;
	vector<int> firstNote;

	cin >> T;
	while (T--) {
		cin >> N;
		int num = 0;
		for (int i = 0; i < N; i++) {
			cin >> num;
			firstNote.push_back(num);
		}
		sort(firstNote.begin(), firstNote.end());
		cin >> M;
		for (int i = 0; i < M; i++) {
			cin >> num;
			bool isEnd = false;
			int compare = num;
			int left = 0, right = N - 1;
			while (left <= right) {
				int mid = left + (right - left) / 2;
				if (firstNote[mid] < compare)
					left = mid + 1;
				else if (firstNote[mid] > compare)
					right = mid - 1;
				else {
					isEnd = true;
					break;
				}
			}
			cout << isEnd << "\n";
		}
	}
	return 0;
}