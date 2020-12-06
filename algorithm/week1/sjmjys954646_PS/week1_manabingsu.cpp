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

int M, N;
int arr[702][702];
int order[1000001][2];
int cache[1401];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M >> N;


    for (int i = 0; i < N; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        order[i][0] = a;
        order[i][1] = a + b;
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = order[i][0]; j < M * 2 - 1; j++)
        {
            cache[j]++;
        }
        for (int j = order[i][1]; j < M * 2 - 1; j++)
        {
            cache[j]++;
        }
    }

    for (int i = M - 1; i > 0; i--)
    {
        arr[i][0] += ++cache[-i + M - 1];
    }
    for (int i = 0; i < M; i++)
    {
        arr[0][i] += ++cache[i + M - 1];
    }

    for (int i = 1; i < M; i++)
    {
        for (int j = 1; j < M; j++)
        {
            arr[i][j] += max(max(arr[i - 1][j - 1], arr[i - 1][j]), arr[i][j - 1]);
        }
    }

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < M; j++)
            cout << arr[i][j] << " ";
        cout << "\n";
    }

    return 0;
}