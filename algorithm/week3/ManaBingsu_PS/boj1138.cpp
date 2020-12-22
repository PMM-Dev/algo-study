// 한 줄로 서기
// https://www.acmicpc.net/problem/1138
// Memory	:	2016 KB
// Time		:	0 ms

#include <iostream>
#include <cstring>

using namespace std;

int main() {
	int N = 0;
	int result[10];

	memset(result, 0, sizeof(result));
	cin >> N;

	for (int i = 0; i < N; i++) {
		int num = 0;

		cin >> num;
		int index = 0;
		while (num >= 0) {
			if (result[index] == 0)
				num--;
			index++;
		}
		result[index - 1] = i + 1;
	}
	for (int i = 0; i < N; i++)
		cout << result[i] << " ";
	cout << "\n";
	return 0;
}
