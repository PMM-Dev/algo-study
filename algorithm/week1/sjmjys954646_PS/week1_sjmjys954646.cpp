#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstring>
#define X first
#define Y second
using namespace std;

const int INF = 987654321;

int arr[52][11];
int N;

vector<int> selected;
bool visited[10];
int ans = -1;

void simulating(vector<int> order)
{
	int score = 0;
	int ru[4];
	int index = 0;
	int out = 0;
	for (int i = 1; i <= N; i++)
	{
		out = 0;
		for (int i = 0; i < 4; i++)
		{
			ru[i] = 0;
		}
		while (out != 3)
		{
			int hit = arr[i][order[index]];
			ru[0] = 1;

			if (hit == 0)
				out++;
			else if (hit == 4)
			{
				for (int i = 0; i <= 3; i++)
				{
					if (ru[i] == 1)
						score++;
					ru[i] = 0;
				}
			}
			else
			{
				for (int i = 3; i >= 0; i--)
				{
					if (ru[i] == 1)
					{
						if (i + hit >= 4)
						{
							score++;
							ru[i] = 0;
						}
						else
						{
							ru[i + hit] = 1;
							ru[i] = 0;
						}
					}
				}


			}

			index++;
			if (index == 9)
				index = 0;
		}
	}
	ans = max(ans, score);
}

void select()
{
	if (selected.size() == 8)
	{
		//make an order
		vector<int> order;
		for (int i = 0; i <= 2; i++)
		{
			order.push_back(selected[i]);
		}
		order.push_back(1);
		for (int i = 3; i < 8; i++)
		{
			order.push_back(selected[i]);
		}
		//simulating
		simulating(order);
	}

	for (int i = 2; i <= 9; i++)
	{
		if (visited[i] == true)
			continue;

		selected.push_back(i);
		visited[i] = true;
		select();
		selected.pop_back();
		visited[i] = false;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			cin >> arr[i][j];
		}
	}

	select();

	cout << ans << "\n";

	return 0;
}