//2480kb 520ms
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

int N, M, K;
int row, column, mass, speed, dir;

class fireball
{
public:
    fireball(int Im = 0, int Is = 0, int Id = 0)
    {
        m = Im;
        s = Is;
        d = Id;
    }

    int m;
    int s;
    int d;
};

int px[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int py[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int pa[4] = {0, 2, 4, 6};
int pc[4] = {1, 3, 5, 7};

vector<fireball> arr[52][52];

void move()
{
    vector<fireball> after[52][52];

    rep(i, N)
    {
        rep(j, N)
        {
            if (arr[i][j].size() > 0)
            {
                rep(k, arr[i][j].size())
                {
                    int nX = j;
                    int nY = i;
                    rep(t, arr[i][j][k].s)
                    {
                        nX += px[arr[i][j][k].d];
                        nY += py[arr[i][j][k].d];

                        if (nX == -1)
                        {
                            nX = N - 1;
                        }
                        if (nY == -1)
                        {
                            nY = N - 1;
                        }
                        if (nX == N)
                        {
                            nX = 0;
                        }
                        if (nY == N)
                        {
                            nY = 0;
                        }
                    }

                    after[nY][nX].push_back({arr[i][j][k].m, arr[i][j][k].s, arr[i][j][k].d});
                }
            }
        }
    }

    rep(i, N)
    {
        rep(j, N)
        {
            arr[i][j] = after[i][j];
        }
    }
}

void happen()
{
    rep(i, N)
    {
        rep(j, N)
        {
            if (arr[i][j].size() >= 2)
            {
                int siz = arr[i][j].size();
                int sum = 0;
                int chk = 0;
                int spe = 0;
                rep(t, siz)
                {
                    sum += arr[i][j][t].m;
                    spe += arr[i][j][t].s;
                    if (arr[i][j][t].d % 2 == 0)
                        chk++;
                    else
                        chk--;
                }

                sum /= 5;
                spe /= siz;

                arr[i][j].clear();

                if (sum == 0)
                    continue;

                rep(p, 4)
                {
                    if (abs(chk) == siz)
                        arr[i][j].push_back({sum, spe, pa[p]});
                    else
                        arr[i][j].push_back({sum, spe, pc[p]});
                }
            }
        }
    }
}

int main()
{
    freopen("input.txt", "r", stdin);

    scanf("%d %d %d", &N, &M, &K);

    rep(i, M)
    {
        scanf("%d %d %d %d %d", &row, &column, &mass, &speed, &dir);
        arr[row - 1][column - 1].push_back({mass, speed, dir});
    }

    while (K--)
    {
        move();
        happen();
    }

    int ans = 0;

    rep(i, N)
    {
        rep(j, N)
        {
            if (arr[i][j].size() > 0)
            {
                rep(k, arr[i][j].size())
                {
                    ans += arr[i][j][k].m;
                }
            }
        }
    }

    cout << ans;

    return 0;
}
