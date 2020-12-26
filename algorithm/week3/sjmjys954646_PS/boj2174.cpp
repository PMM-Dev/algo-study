//메모리 : 2096kb 시간 : 0ms
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
#define X first
#define Y second

int dir[4] = { 0,1,2,3 }; // 0 N, 1 E, 2 S, 3 W
pair<int,int> ground[102][102];
int A, B;
int N, M;
int pX[4] = {0,1,0,-1};
int pY[4] = {1,0,-1,0};

void debug()
{

	for (int y = 0; y < B; y++)
	{
		for (int x = 0; x < A; x++)
		{
			cout << ground[y][x].first << ground[y][x].second << " ";
		}
		cout << "\n";
	}
	cout << "\n\n";
}

int dirtranslater(char c)
{
	switch (c) 
	{
	case 'N':
		return 0;
	case 'E' :
		return 1;
	case 'S' :
		return 2;
	case 'W' :
		return 3;
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	memset(ground, -1, sizeof(ground));

	cin >> A >> B;
	cin >> N >> M;

	int a, b;
	char c;
	bool failure = false;

	for (int i = 0; i < N; i++)
	{
		cin >> a >> b >> c;
		ground[b - 1][a - 1] = { i + 1,dirtranslater(c) };
	}

	for (int i = 0; i < M; i++)
	{
		cin >> a >> c >> b;

		if (failure)
			continue;

		int findx, findy;
		for (int x = 0; x < A; x++)
		{
			for (int y = 0; y < B; y++)
			{
				if (ground[y][x].first == a)
				{
					findx = x;
					findy = y;
					y = B;
					x = A;
					break;
				}
			}
		}
		for (int j = 0; j < b; j++)
		{
			if (failure)
				break;

			//debug();
			if (c == 'L')
			{
				ground[findy][findx].second = ground[findy][findx].second == 0 ? 3 : ground[findy][findx].second - 1;
			}
			else if (c == 'R')
			{
				ground[findy][findx].second = ground[findy][findx].second == 3 ? 0 : ground[findy][findx].second + 1;
			}
			else if (c == 'F')
			{
				int nX = findx + pX[ground[findy][findx].second];
				int nY = findy + pY[ground[findy][findx].second];
				if (nX < 0 || nY < 0 || nX >= A || nY >= B)
				{
					cout << "Robot " << a << " crashes into the wall\n";
					failure = true;
				}

				if (ground[nY][nX].first > 0)
				{
					cout << "Robot " << a << " crashes into robot " << ground[nY][nX].first<<"\n";
					failure = true;
				}
				ground[nY][nX] = { a,ground[findy][findx].second };
				ground[findy][findx] = { -1,-1 };
				findx = nX;
				findy = nY;
			}
		}

	}

	if (!failure)
		cout << "OK";
	
	return 0;
}