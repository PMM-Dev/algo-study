//메모리 : 2016kb 시간 : 0ms
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
using namespace std;

int N;
bool selectcheck[11];
int arr[11];
int ans[11];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	memset(ans, -1, sizeof(ans));

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < N; i++)
	{
		int count = 0;
		for (int j = 0; j < N; j++)
		{
			if (count == arr[i] && ans[j] == -1)
			{
				ans[j] = i + 1;
				break;
			}

			if (ans[j] == -1)
				count++;
		}
	}

	for (int i = 0; i < N; i++)
	{
		cout << ans[i] << " ";
	}

	return 0;
}