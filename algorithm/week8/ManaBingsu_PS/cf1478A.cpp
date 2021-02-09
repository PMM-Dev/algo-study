// Nezzar and Colorful Balls
// https://codeforces.com/contest/1478/problem/A
// Memory	:	31		KB
// Time		:	0		ms

#include <iostream>
#include <string.h>

using namespace std;

int main()
{
	bool memo[101];
	int input[101];

	int t, n;
	cin >> t;
	while (t--) {
		memset(memo, false, sizeof(memo));
		cin >> n;

		int index = 0;
		while (index < n)
			cin >> input[index++];
		int count = 0;
		int result = 0;
		while (count < n) {
			int pointer = -1;
			count = 0;
			index = 0;
			while (index < n) {
				if (memo[index] == 1) {
					count++;
				}
				else {
					if (input[index] > pointer) {
						pointer = input[index];
						memo[index] = 1;
					}
				}
				index++;
			}
			if (count < n)
				result++;
		}
		cout << result << "\n";
 	}
	return 0;
}
