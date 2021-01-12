// Åé´Ï¹ÙÄû
// https://www.acmicpc.net/problem/14891
// Memory	:	1988	KB
// Time		:	0		ms

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> gear[4];

void turnGearByDir(int num, int dir, int chainedNum);

int main()
{
	for (int i = 0; i < 4; i++)
	{
		string input;
		cin >> input;
		for (int j = 0; j < 8; j++)
		{
			gear[i].push_back(input[j] - '0');
		}
	}
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int num;
		int dir;

		cin >> num;
		cin >> dir;
		turnGearByDir(num - 1, dir, 0);
	}
	int result = 0;
	if (gear[0][0] == 1) result += 1;
	if (gear[1][0] == 1) result += 2;
	if (gear[2][0] == 1) result += 4;
	if (gear[3][0] == 1) result += 8;

	cout << result << endl;
	return (0);
}

void turnGearByDir(int num, int dir, int chainedNum)
{
	int leftNum = num - 1 < 0 ? -1 : num - 1;
	int rightNum = num + 1 > 3 ? -1 : num + 1;

	if (leftNum != -1 && chainedNum != -1)
	{
		if (gear[num][6] != gear[leftNum][2])
			turnGearByDir(leftNum, dir * -1, 1);
	}

	if (rightNum != -1 && chainedNum != 1)
	{
		if (gear[num][2] != gear[rightNum][6])
			turnGearByDir(rightNum, dir * -1, -1);
	}

	if (dir > 0)
	{
		int temp = gear[num][7];
		for (int i = 7; i >= 1; i--)
		{
			gear[num][i] = gear[num][i - 1];
		}
		gear[num][0] = temp;
	}
	else
	{
		int temp = gear[num][0];
		for (int i = 0; i <= 6; i++)
		{
			gear[num][i] = gear[num][i + 1];
		}
		gear[num][7] = temp;
	}
}