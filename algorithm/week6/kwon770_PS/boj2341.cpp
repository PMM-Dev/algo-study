// https://www.acmicpc.net/problem/2341
// 2341 팩스문제
//
// i번째 짜리까지 압축하였으며, i번째 자리를 j로 압축했을 때의 최소 변환 비용 = cache[i][j]
// i번째 짜리까지 압축하였으며, i번째 자리를 j로 압축했을 때, 최소 변환 비용이 들었던 i - 1번째의 압축 형식  = backtrack[i][j]
// 
// 위치와 값에 따른 캐싱을 해야하며, 캐싱값은 주어진 공식을 이용해야 한다.
// 각 자리의 숫자가 4개의 압축형식으로 변환될 수 있기 때문에 4^50 (최대 50개의 수열) 의 복잡도를
// 가진다고 생각하여 다른 방법을 생각만하다 포기한 문제이다.
// 캐싱이 없다면 실제 저만큼의 복잡도만큼 계산을 하게 되지만, 캐싱을 통해 시간이 단축되기 때문에
// 구현하면 되는 문제였다.
//
// 이 문제는 결과값뿐만 아니라 결과의 형태도 출력해야 하므로, dp 역추적 또한 필요하다.
// 이전 단계의 최적의 압축형식을 현재 단계에 저장하여서 마지막부터 앞으로 차례차례 이동하면서 압축형식을
// 다시 찾고, 그에 따른 압축결과를 다시 출력한다.
// reverse 하는 과정을 생략하고 싶어서, rbein rend 를 사용했다.
//
#include <climits>
#include <cmath>
#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;

int n, w;
vector<vector<int>> cache;
vector<vector<int>> backtrack;
vector<int> arr;
vector<int> format = {1, 86, 172, 256};

void dp() {
	for (int i = 0; i < 4; i++) {
		cache[1][format[i]] = abs(format[i] - arr[1]) + w * 2;
	}

	for (int i = 2; i <= n; i++) {
		for (int cur = 0; cur < 4; cur++) {
			int minVal = INT_MAX;
			for (int prev = 0; prev < 4; prev++) {
				int tmpVal;
				if (format[cur] == format[prev]) {
					tmpVal = cache[i - 1][format[prev]] + abs(format[cur] - arr[i]) + w * 1;
					if (tmpVal < minVal) {
						minVal = tmpVal;
						backtrack[i][format[cur]] = format[prev];
					}

				} else {
					tmpVal = cache[i - 1][format[prev]] + abs(format[cur] - arr[i]) + w * 3;
					if (tmpVal < minVal) {
						minVal = tmpVal;
						backtrack[i][format[cur]] = format[prev];
					}
				}
			}
			cache[i][format[cur]] = minVal;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> w;
	cache.resize(n + 1, vector<int>(257));
	backtrack.resize(n + 1, vector<int>(257));
	arr.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	dp();

	int ans = INT_MAX, lastMinFormat;
	for (int i = 0; i < 4; i++) {
		if (ans > cache[n][format[i]]) {
			ans = cache[n][format[i]];
			lastMinFormat = format[i];
		}
	}
	cout << ans << endl;

	vector<int> ansFormat;
	ansFormat.push_back(lastMinFormat);
	for (auto riter = backtrack.rbegin(); riter != backtrack.rend() - 2; riter++) {
		ansFormat.push_back((*riter)[lastMinFormat]);
		lastMinFormat = (*riter)[lastMinFormat];
	}

	int prevFormat = -1;
	for (auto riter = ansFormat.rbegin(); riter != ansFormat.rend(); riter++) {
		if (riter != ansFormat.rbegin()) {
			if (prevFormat == *riter) {
				cout << "0";
				continue;
			} else {
				cout << "1";
			}	
		}

		if (*riter == 1) cout << "00";
		if (*riter == 86) cout << "01";
		if (*riter == 172) cout << "10";
		if (*riter == 256) cout << "11";
		prevFormat = *riter;
	}
	return 0;
}
