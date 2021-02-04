// 회의실 배정
// https://www.acmicpc.net/problem/1931
// Memory	:	3564	KB
// Time		:	84		ms

#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	auto times = vector<pair<int, int>>();
	cin >> N;
	while (N--) {
		int begin, end;
		cin >> begin >> end;
		times.push_back(make_pair(end, begin));
	}
	sort(times.begin(), times.end());
	int counter = 0, endTime = 0;
	for (auto it = times.begin(); it != times.end(); it++) {
		if ((*it).second >= endTime) {
			endTime = (*it).first;
			++counter;
		}
	}
	cout << counter << "\n";
	return 0;
}