//2056kb 0ms
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
#include <string>
#include <queue>
#include <stack>
#include <cstring>
#include <list>
#include <set>

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define range(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define F first
#define S second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

//https://swjeong.tistory.com/170
const int MAX = 101;
const int dy[] = {0, -1, 0, 1};
const int dx[] = {1, 0, -1, 0};
int n, y, x, d, g;
int map[MAX][MAX];
int solve()
{
    cin >> n;
    while (n--)
    {
        cin >> x >> y >> d >> g;
        vector<int> dir;
        dir.push_back(d);
        map[y][x] = 1;
        for (int i = 0; i < g; i++)
        {
            int dirSize = dir.size();
            for (int j = dirSize - 1; j >= 0; j--)
            {
                dir.push_back((dir[j] + 1) % 4);
            }
        }
        for (int i = 0; i < dir.size(); i++)
        {
            y += dy[dir[i]];
            x += dx[dir[i]];
            if (y < 0 || x < 0 || y >= MAX || x >= MAX)
                continue;
            map[y][x] = 1;
        }
    }
    int ret = 0;
    for (int r = 0; r < MAX - 1; r++)
    {
        for (int c = 0; c < MAX - 1; c++)
        {
            if (map[r][c] == 1 && map[r + 1][c] == 1 && map[r][c + 1] == 1 && map[r + 1][c + 1] == 1)
            {
                ret++;
            }
        }
    }
    return ret;
}

int main()
{
    freopen("input.txt", "r", stdin);

    cout << solve();

    return 0;
}
