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

string s;

pair<int,int> bracket(int idx)
{
	int total = 0;
	int mul;
	while (idx < s.length())
	{
		if (s[idx] == '(')
		{
			mul = s[idx - 1] - '0';
			pair<int, int> tmp = bracket(++idx);
			total+=mul*tmp.first;
			total--;
			idx = tmp.second + 1;
		}
		else if (s[idx] == ')')
		{
			return { total,idx };
		}
		else
		{
			total++;
			idx++;
		}
	}

	return { total,0 };
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> s;

	cout << bracket(0).first;

	return 0;
}