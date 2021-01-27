//2408kb 36ms
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstring>
#include <queue>
#include <cmath>
#define X first
#define Y second
using namespace std;

const int INF = 987654321;

int N;
int cache[100002];
int maxhi;

int main()
{
    fill(cache, cache + 100002, INF);

    scanf("%d", &N);

    maxhi = (int)floor(sqrt(100000));

    for (int i = 1; i <= maxhi; i++)
    {
        cache[i * i] = 1;
    }

    for (int i = 2; i < 100001; i++)
    {
        for (int j = maxhi; j >= 1; j--)
        {
            if (j * j > i)
                continue;

            if (cache[i] > cache[i - j * j] + 1)
                cache[i] = cache[i - j * j] + 1;
        }
    }

    printf("%d", cache[N]);

    return 0;
}