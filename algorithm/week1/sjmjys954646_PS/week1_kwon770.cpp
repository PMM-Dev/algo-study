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

vector<int> arr[10];
bool check[10];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testcase;

    for (int i = 0; i < 10; i++)
    {
        memset(check, 0, sizeof(check));

        int tmp = i;
        while (check[tmp] != true)
        {
            arr[i].push_back(tmp);
            check[tmp] = true;
            tmp *= i;
            tmp %= 10;
        }
    }

    cin >> testcase;

    while (testcase--)
    {
        int a, b;
        int ans = 0;

        cin >> a >> b;

        a %= 10;
        b %= arr[a].size();
        ans = (b == 0 ? arr[a][arr[a].size()-1] : arr[a][b - 1]);
        if (a == 0)
            ans = 10;
        cout << ans << "\n";
    }

    return 0;
}