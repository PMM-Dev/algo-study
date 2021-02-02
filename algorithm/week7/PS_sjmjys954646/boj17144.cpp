//9860kb 340ms
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

int Barr[1002][1002];
int Narr[1002][1002];
int R, C, T;
pii upCleaner = {0, 0}; // sero garo
pii downCleaner;
int pX[4] = {0, 1, 0, -1};
int pY[4] = {1, 0, -1, 0};

void Spread()
{
    memset(Narr, 0, sizeof(Narr));

    rep(i, R)
    {
        rep(j, C)
        {
            if (Barr[i][j] != 0)
            {
                int tmp = Barr[i][j];
                int spreadAmount = tmp / 5;
                int pos = 0;
                rep(k, 4)
                {
                    int nY = i + pY[k];
                    int nX = j + pX[k];

                    if (nX < 0 || nY < 0 || nX >= C || nY >= R)
                        continue;

                    if (Barr[nY][nX] == -1)
                        continue;

                    Narr[nY][nX] += spreadAmount;
                    pos++;
                }
                Narr[i][j] += (tmp - spreadAmount * pos);
            }
        }
    }

    rep(i, R)
    {
        rep(j, C)
        {
            Barr[i][j] = Narr[i][j];
        }
    }
}

void circulation()
{
    memset(Narr, 0, sizeof(Narr));
    rep(i, R)
    {
        rep(j, C)
        {
            Narr[i][j] = Barr[i][j];
        }
    }

    for (int i = 1; i < C - 1; i++)
    {
        Narr[upCleaner.F][i + 1] = Barr[upCleaner.F][i];
        Narr[downCleaner.F][i + 1] = Barr[downCleaner.F][i];
    }
    Narr[upCleaner.F][1] = 0;
    Narr[downCleaner.F][1] = 0;

    for (int i = upCleaner.F; i >= 1; i--)
    {
        Narr[i - 1][C - 1] = Barr[i][C - 1];
    }
    for (int i = downCleaner.F; i < R - 1; i++)
    {
        Narr[i + 1][C - 1] = Barr[i][C - 1];
    }

    for (int i = C - 1; i >= 1; i--)
    {
        Narr[0][i - 1] = Barr[0][i];
        Narr[R - 1][i - 1] = Barr[R - 1][i];
    }

    for (int i = 0; i < upCleaner.F - 1; i++)
    {
        Narr[i + 1][0] = Barr[i][0];
    }
    for (int i = R - 1; i > downCleaner.F + 1; i--)
    {
        Narr[i - 1][0] = Barr[i][0];
    }

    rep(i, R)
    {
        rep(j, C)
        {
            Barr[i][j] = Narr[i][j];
        }
    }
}

int main()
{
    freopen("input.txt", "r", stdin);

    scanf("%d %d %d", &R, &C, &T);

    rep(i, R)
    {
        rep(j, C)
        {
            scanf("%d", &Barr[i][j]);
            if (Barr[i][j] == -1 && upCleaner.F == 0)
            {
                upCleaner = {i, j};
                downCleaner = {i + 1, j};
            }
        }
    }

    while (T--)
    {
        Spread();
        circulation();
    }

    int total = 0;
    rep(i, R)
    {
        rep(j, C)
        {
            if (Barr[i][j] == -1)
                continue;
            total += Barr[i][j];
        }
    }

    printf("%d", total);

    //Debug
    // rep(i, R)
    // {
    //     rep(j, C)
    //     {
    //         cout << Barr[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    return 0;
}
