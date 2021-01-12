//108464kb 464ms
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

int arr[21][21];
int N;
int fSize = 2;
int ans = 0;
int curFX;
int curFY;
int qX[4] = { 0, -1,1,0 };
int qY[4] = { -1, 0,0,1 };
int stomache = 0;
bool visit[21][21];

bool cmp(pair<pair<int, int>,int> a, pair<pair<int, int>, int> b) {
	if (a.Y != b.Y)
		return a.Y < b.Y;
	else if (a.X.Y == b.X.Y)
		return a.X.X < b.X.X;
	else
		return a.X.Y < b.X.Y;
}


pair<pair<int, int>, int> findF()
{
	memset(visit, 0, sizeof(visit));
	queue<pair<pair<int, int>, int>> q;
	int curX = curFX;
	int curY = curFY;
	q.push({ { curX, curY }, 0 });
	bool findFP = false;
	int fX;
	int fY;
	int fD;

	vector < pair<pair<int, int>, int> > willEat;

	while (!q.empty())
	{
		int cX = q.front().first.first;
		int cY = q.front().first.second;
		int d = q.front().second;
		visit[cY][cX] = true;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nX = cX + qX[i];
			int nY = cY + qY[i];

			if (nX < 0 || nY < 0 || nX >= N || nY >= N)
				continue;

			if (arr[nY][nX] > fSize )
				continue;

			if (visit[nY][nX] == true)
				continue;

			if (arr[nY][nX] != 0 && arr[nY][nX] < fSize)
			{
				willEat.push_back({{ nX,nY }, d});
				findFP = true;
			}

			if (!findFP)
				q.push({ { nX,nY }, d + 1 });
		}
	}
	if (!willEat.empty())
	{
		sort(willEat.begin(), willEat.end(), cmp);
		return { {willEat.front().X.X,willEat.front().X.Y},willEat.front().Y + 1 };
	}
	else
	{
		return {{ -1,-1 }, -1};
	}
}

bool check()
{
	bool findFpos = false;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (arr[i][j] == 9 || arr[i][j] == 0)
				continue;

			if (arr[i][j] < fSize)
			{
				i = N;
				j = N;
				findFpos = true;
			}
		}
	}
	return findFpos;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 9)
			{
				curFX = j;
				curFY = i;
			}
		}
	}

	while (true)
	{
		/*for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cout << arr[i][j] << " ";
			}
			cout << "\n";
		}*/
		if (!check())
			break;

		pair<pair<int, int>, int> t = findF();
		/*cout << t.first.second << " " << t.first.first << " " << t.second << "\n";
		cout << fSize;
		cout << "\n"; cout << "\n";*/
		if (t.Y == -1)
			break;
		arr[curFY][curFX] = 0;
		arr[t.first.second][t.first.first] = 9;
		ans += t.second;
		curFX = t.first.first;
		curFY = t.first.second;
		stomache++;
		if (stomache == fSize)
		{
			fSize++;
			stomache = 0;
		}
	}


	cout << ans;

	return 0;
}