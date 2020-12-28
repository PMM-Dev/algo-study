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

int N, R, C;
int turn;

int convertor(int si, int rt, int rc)
{
	if (R < rt + si && C < rc + si)
	{
		return 0;
	}
	else if (R < rt + si  && C >= rc + si )
	{
		return 1;
	}
	else if (R >= rt + si && C < rc + si)
	{
		return 2;
	}
	else if (R >= rt + si  && C >= rc + si)
	{
		return 3;
	}
}

void makeZ(int size,int row, int column)
{
	if (size == 1)
	{
		if (row == R && column == C)
		{
			cout << turn;
		}
		return;
	}

	int a = R >= row + size / 2 ? row + size / 2 : row;
	int b = C >= column + size / 2 ? column + size / 2 : column;

	turn += size / 2 * size / 2 * convertor(size / 2, row, column);
	makeZ(size / 2, a, b);
}

int main(void)
{
	cin >> N >> R >> C;

	makeZ(pow(2, N),0 ,0 );

	return 0;
}