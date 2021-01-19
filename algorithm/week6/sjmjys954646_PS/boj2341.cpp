//2124kb 0ms
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <math.h>
#include <cstdlib>
#include <utility>
using namespace std;

int cache[52][260];
int before[52][260];
vector<int> arr;
int N, W;
int ch[4] = {1, 86, 172, 256};
vector<int> s;
int INF = 987654321;

void DP(int index, int change)
{
    int M = INF;

    for (int i = 0; i < 4; i++)
    {
        if (ch[i] == change)
        {
            if (M > cache[index - 1][ch[i]] + abs(change - arr[index]) + W)
            {
                M = cache[index - 1][ch[i]] + abs(change - arr[index]) + W;
                before[index][change] = ch[i];
            }
        }
        else
        {
            if (M > cache[index - 1][ch[i]] + abs(change - arr[index]) + 3 * W)
            {
                M = cache[index - 1][ch[i]] + abs(change - arr[index]) + 3 * W;
                before[index][change] = ch[i];
            }
        }
    }

    cache[index][change] = M;
}

int main()
{
    cin >> N >> W;

    for (int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }

    for (int j = 0; j < 4; j++)
    {
        cache[0][ch[j]] = abs(ch[j] - arr[0]) + 2 * W;
    }

    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            DP(i, ch[j]);
        }
    }

    int tmp = INF;

    for (int j = 0; j < 4; j++)
    {
        tmp = min(tmp, cache[N - 1][ch[j]]);
    }
    cout << tmp << "\n";

    int start;
    for (int j = 0; j < 4; j++)
    {
        if (tmp == cache[N - 1][ch[j]])
            start = ch[j];
    }
    s.push_back(start);

    int idx = N - 1;
    while (idx > 0)
    {
        s.push_back(before[idx][start]);
        start = before[idx][start];
        idx--;
    }

    reverse(s.begin(), s.end());

    for (int i = 0; i < N; i++)
    {
        if (i > 0)
        {
            if (s[i] != s[i - 1])
                cout << "1";
            else if (s[i] == s[i - 1])
            {
                cout << "0";
                continue;
            }
        }

        if (s[i] == 1)
        {
            cout << "00";
        }
        if (s[i] == 86)
        {
            cout << "01";
        }
        if (s[i] == 172)
        {
            cout << "10";
        }
        if (s[i] == 256)
        {
            cout << "11";
        }
    }

    return 0;
}