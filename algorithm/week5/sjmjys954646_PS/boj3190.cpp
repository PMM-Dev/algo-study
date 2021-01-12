//2060kb 0ms
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

int arr[103][103];
pair<int, int> lastpos[103];// x y
int N;
int headY = 0;
int headX = 0;
int tailY = 0;
int tailX = 0;
int dirY[4] = { 0,1,0,-1 };
int dirX[4] = { 1,0,-1,0 };
int dirpoint = 0;
int sec = 0;
int curLen = 1;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	queue<pair<int,char>> q;
	memset(arr, 0, sizeof(arr));
	int apple;

	cin >> N;

	cin >> apple;

	for (int i = 0; i < apple; i++)
	{
		int a, b;
		cin >> a >> b;
		arr[a - 1][b - 1] = 5;
	}

	lastpos[0] = { 0,0 };
	arr[0][0] = 1;

	int order;
	cin >> order;

	for (int i = 0; i < order; i++)
	{
		int a;
		char b;
		cin >> a >> b;
		q.push({ a,b });
	}

	while (true)
	{
		int hnY = headY + dirY[dirpoint];
		int hnX = headX + dirX[dirpoint];

		if (hnY < 0 || hnX < 0 || hnY >= N || hnX >= N)
			break;

		if (arr[hnY][hnX] == 1)
			break;

		if (arr[hnY][hnX] == 0)
		{
			arr[hnY][hnX] = 1;

			for (int i = curLen-1; i > 0 ; i--)
			{
				int tmpY = lastpos[i-1].second;
				int tmpX = lastpos[i-1].first;
				arr[tmpY][tmpX] = 1;
				lastpos[i].second = lastpos[i-1].second;
				lastpos[i].first = lastpos[i-1].first;
			}
			lastpos[0].second = headY;
			lastpos[0].first = headX;
			headY = hnY;
			headX = hnX;
			if(lastpos[curLen - 1].second == -1 && lastpos[curLen - 1].first == -1)
				arr[0][0] = 0;
			else
				arr[lastpos[curLen - 1].second][lastpos[curLen - 1].first] = 0;

			
		}
		else if (arr[hnY][hnX] == 5)
		{
			arr[hnY][hnX] = 1;
			curLen++;
			for (int i = curLen-1 ; i > 0; i--)
			{
				if (lastpos[i-1].second == 0 && lastpos[i-1].first == 0)
				{
					lastpos[i].second = -1;
					lastpos[i].first = -1;
					continue;
				}
				else if (lastpos[i-1].second == -1 && lastpos[i-1].first == -1)
				{
					lastpos[i].second = 0;
					lastpos[i].first = 0;
					continue;
				}
				lastpos[i].second = lastpos[i-1].second;
				lastpos[i].first = lastpos[i-1].first;
			}
			lastpos[0].second = headY;
			lastpos[0].first = headX;
			headY = hnY;
			headX = hnX;
		}

		sec++;

		if (!q.empty() && q.front().X == sec)
		{
			char dir = q.front().Y;
			q.pop();
			if (dir == 'D')
				dirpoint = dirpoint == 3 ? 0 : dirpoint + 1;
			else if (dir == 'L')
				dirpoint = dirpoint == 0 ? 3 : dirpoint - 1;
		}

		/*for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cout << arr[i][j] << " "; 
			}
			cout << "\n";
		}
		cout << "\n";*/
	}

	cout << ++sec;

	return 0;
}