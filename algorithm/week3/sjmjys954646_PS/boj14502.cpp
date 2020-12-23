//메모리 : 1984kb 시간 : 40ms
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#define X first
#define Y second
using namespace std;

const int INF = 987654321;

int arr[8][8];
int N, M;
vector<pair<int, int> > posWall;
vector<pair<int, int> > virus;
int board[8][8];
int spreadDir[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };

void showBoard()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << board[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}


void copy()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			board[i][j] = arr[i][j];
		}
	}
}

void refillVirus()
{
	virus.clear();
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (arr[i][j] == 2)
			{
				virus.push_back({ i,j });
			}
		}
	}
}


void spread()
{
	int index = 0;
	while (index < virus.size())
	{
		for (int i = 0; i < 4; i++)
		{
			int mY = virus[index].X + spreadDir[i][0];
			int mX = virus[index].Y + spreadDir[i][1];


			if (mX < 0 || mX >= M || mY < 0 || mY >= N)
				continue;

			if (board[mY][mX] != 0)
				continue;

			board[mY][mX] = 2;
			virus.push_back({ mY,mX });

		}
		index++;
	}
}

int count()
{
	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (board[i][j] == 0)
				sum++;
		}
	}
	return sum;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 0)
			{
				posWall.push_back({ i,j });
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < posWall.size(); i++)
	{
		for (int j = i + 1; j < posWall.size(); j++)
		{
			for (int k = j + 1; k < posWall.size(); k++)
			{
				refillVirus();
				copy();
				board[posWall[i].X][posWall[i].Y] = 1;
				board[posWall[j].X][posWall[j].Y] = 1;
				board[posWall[k].X][posWall[k].Y] = 1;
				spread();
				int tot = count();
				ans = max(tot, ans);
			}
		}
	}
	cout << ans;
	return 0;
}