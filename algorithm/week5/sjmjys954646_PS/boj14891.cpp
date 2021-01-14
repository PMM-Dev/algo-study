//2020kb 0ms
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
#include <string>
#include <queue>
#include <stack>
#include <cstring>
#define X first
#define Y second

using namespace std;

deque<int> dq[4];
int tdir[4];
// 첨에 구현하려한게 dq말고 기본 배열 arr[4][8]에 pointer[4] dir[4]
// 이렇게 있는데 pointer-2 pointer+2로 톱니 왼쪽 오른쪽을 비교하는 방식이었음 근데 왜안되지

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int K;
	int ans = 0;

	for (int i = 0; i < 4; i++)
	{
		string t;
		cin >> t;
		for (int j = 0;j<8;j++)
		{
			dq[i].push_back(t[j] - '0');
		}
	}
		
	cin >> K;
	
	while (K--)
	{
		memset(tdir, 0, sizeof(tdir));
		int num, dir;

		cin >> num >> dir;

		num--;

		tdir[num] = dir;

		for (int i = num; i < 3; i++)
		{
			if (dq[i][2] != dq[i + 1][6])
			{
				tdir[i + 1] = -tdir[i];
			}
		}

		for (int i = num; i > 0; i--)
		{
			if (dq[i][6] != dq[i - 1][2])
			{
				tdir[i - 1] = -tdir[i];
			}
		}

		for (int i = 0; i < 4; i++)
		{
			if (tdir[i] == 0)
				continue;

			if (tdir[i] == 1)
			{
				int tmp = dq[i].back();
				dq[i].pop_back();
				dq[i].push_front(tmp);
			}
			else
			{
				int tmp = dq[i].front();
				dq[i].pop_front();
				dq[i].push_back(tmp);
			}
		}

	} 

	for (int i = 0, j = 1; i < 4; i++, j*=2)
	{
		ans += dq[i][0] * j;
	}

	cout << ans;

	return 0;
}