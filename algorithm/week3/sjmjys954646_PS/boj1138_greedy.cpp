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
vector<int> selected;
bool selectcheck[11];
int arr[11];
bool succeed = false;


void check()
{
	for (int i = 1; i <= N; i++)
	{
		int count = 0;
		for (int j = 0; j < N; j++)
		{
			if (selected[j] == i)
				break;
			else if (selected[j] > i)
				count++;
		}
		if (count != arr[i - 1])
			return;

		if (i == N)
		{
			for (int j = 0; j < N; j++)
			{
				cout << selected[j] << " ";
			}
			succeed = true;
		}
	}
}

void select()
{
	if (succeed == true)
		return;

	if (selected.size() == N)
	{
		check();
		return;
	}

	for (int i = 1; i <= N; i++)
	{
		if (selectcheck[i] == true)
			continue;
		selected.push_back(i);
		selectcheck[i] = true;
		select();
		selected.pop_back();
		selectcheck[i] = false;
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	select();

	return 0;
}