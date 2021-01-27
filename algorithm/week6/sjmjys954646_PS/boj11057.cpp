//2096kb 0ms
#define _CRT_SECURE_NO_WARNINGS
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

long long cache[1003][10];

int main()
{
    memset(cache, 0, sizeof(cache));
    int N;
    long long ans = 0;
    scanf("%d", &N);

    for (int i = 0; i < 10; i++)
    {
        cache[1][i] = 1;
    }

    for (int i = 2; i <= N; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            for (int k = 0; k <= j; k++)
            {
                cache[i][j] += cache[i - 1][k];
                cache[i][j] %= 10007;
            }
        }
    }

    for (int j = 0; j < 10; j++)
    {
        ans += cache[N][j];
    }

    printf("%lld", ans % 10007);

    return 0;
}