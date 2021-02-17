//6132kb 84ms
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

int N;
int after[22][22];
int arr[22][22];
vector<int> mv;
int ans = -1;

int dX[4] = {0, 1, 0, -1};
int dY[4] = {-1, 0, 1, 0};

void movsub()
{
    copy(&arr[0][0], &arr[0][0] + 22 * 22, &after[0][0]);
    rep(k, 5)
    {
        queue<int> q;
        if (mv[k] == 0)
        {
            for (int j = 0; j < N; j++)
            {
                for (int i = 0; i < N; i++)
                {
                    if (after[i][j] != 0)
                    {
                        q.push(after[i][j]);
                        after[i][j] = 0;
                    }
                }

                int idx = 0;

                while (!q.empty())
                {
                    int qF = q.front();
                    q.pop();

                    if (after[idx][j] == 0)
                    {
                        after[idx][j] = qF;
                    }
                    else
                    {
                        if (qF == after[idx][j])
                        {
                            after[idx][j] *= 2;
                            idx++;
                        }
                        else
                        {
                            idx++;
                            after[idx][j] = qF;
                        }
                    }
                }
            }
        }
        else if (mv[k] == 1)
        {

            for (int i = 0; i < N; i++)
            {
                for (int j = N - 1; j >= 0; j--)
                {
                    if (after[i][j] != 0)
                    {
                        q.push(after[i][j]);
                        after[i][j] = 0;
                    }
                }
                int idx = N - 1;

                while (!q.empty())
                {
                    int qF = q.front();
                    q.pop();

                    if (after[i][idx] == 0)
                    {
                        after[i][idx] = qF;
                    }
                    else
                    {
                        if (qF == after[i][idx])
                        {
                            after[i][idx] *= 2;
                            idx--;
                        }
                        else
                        {
                            idx--;
                            after[i][idx] = qF;
                        }
                    }
                }
            }
        }
        else if (mv[k] == 2)
        {
            for (int j = 0; j < N; j++)
            {
                for (int i = N - 1; i >= 0; i--)
                {
                    if (after[i][j] != 0)
                    {
                        q.push(after[i][j]);
                        after[i][j] = 0;
                    }
                }
                int idx = N - 1;

                while (!q.empty())
                {
                    int qF = q.front();
                    q.pop();

                    if (after[idx][j] == 0)
                    {
                        after[idx][j] = qF;
                    }
                    else
                    {
                        if (qF == after[idx][j])
                        {
                            after[idx][j] *= 2;
                            idx--;
                        }
                        else
                        {
                            idx--;
                            after[idx][j] = qF;
                        }
                    }
                }
            }
        }
        else if (mv[k] == 3)
        {
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    if (after[i][j] != 0)
                    {
                        q.push(after[i][j]);
                        after[i][j] = 0;
                    }
                }
                int idx = 0;

                while (!q.empty())
                {
                    int qF = q.front();
                    q.pop();

                    if (after[i][idx] == 0)
                    {
                        after[i][idx] = qF;
                    }
                    else
                    {
                        if (qF == after[i][idx])
                        {
                            after[i][idx] *= 2;
                            idx++;
                        }
                        else
                        {
                            idx++;
                            after[i][idx] = qF;
                        }
                    }
                }
            }
        }
    }
    //DEBUG
    // for (auto i : mv)
    // {
    //     cout << i << " ";
    // }
    // cout << "\n";
    // rep(i, N)
    // {
    //     rep(j, N)
    //     {
    //         cout << after[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            ans = max(ans, after[i][j]);
        }
    }
}

void select()
{
    if (mv.size() == 5)
    {
        movsub();
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        mv.push_back(i);
        select();
        mv.pop_back();
    }
}

int main()
{
    freopen("input.txt", "r", stdin);

    scanf("%d", &N);

    rep(i, N)
    {
        rep(j, N)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    select();

    printf("%d", ans);

    return 0;
}
