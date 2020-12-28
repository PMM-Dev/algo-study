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
stack<char> st;
int total = 0;
int idx = 0;

int bracket()
{
	int total = 0;

	while (idx < s.length())
	{
		if (s[idx] == '(')
		{
			idx++;
			total += 2 * bracket();
		}
		else if (s[idx] == '[')
		{
			idx++;
			total += 3 * bracket();
		}
		else if (s[idx] == ')' || s[idx] == ']')
		{
			idx++;
			return total == 0 ? 1 : total;
		}
	}
	
	return total;
}

bool check()
{
	while (!st.empty())
	{
		st.pop();
	}

	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '(' || s[i] == '[')
			st.push(s[i]);
		else if (s[i] == ')' || s[i] == ']')
		{
			if (st.size() != 0 && ( ( s[i] == ')' && st.top() == '(' ) || (  s[i] == ']' && st.top() == '[' ) ) )
			{
				st.pop();
			}
			else
			{
				return false;
			}
		}
	}

	if (st.empty())
		return true;
	else
		return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> s;

	if (check())
	{
		cout << bracket();
	}
	else
	{
		cout << "0\n";
	}

	return 0;
}