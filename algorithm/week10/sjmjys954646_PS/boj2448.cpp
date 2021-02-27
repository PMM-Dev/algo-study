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

char arr[3072][6144];

void Star(int num, int a, int b)
{

    if (num == 1)
    {
        arr[b + 2][a + 2] = '*';
        arr[b + 2][a + 1] = '*';
        arr[b + 2][a] = '*';
        arr[b + 2][a - 1] = '*';
        arr[b + 2][a - 2] = '*';
        arr[b + 1][a + 1] = '*';
        arr[b + 1][a - 1] = '*';
        arr[b][a] = '*';
        return;
    }
    else
    {
        Star(num - 1, a, b);
        Star(num - 1, a + 3 * ((int)pow(2, num - 2)), b + 3 * ((int)pow(2, num - 2)));
        Star(num - 1, a - 3 * ((int)pow(2, num - 2)), b + 3 * ((int)pow(2, num - 2)));
    }
}

int main()
{
    freopen("input.txt", "r", stdin);

    int a, b, c, d, num, l;
    int k = 0;

    scanf("%d", &num);

    l = num;
    num = num / 3;

    if (num > 2)
    {
        for (; num > 2; k++)
        {
            num /= 2;
        }
        num = k + 2;
    }

    a = l - 1;
    b = 0;

    c = l;
    d = 2 * l - 1;

    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < d; j++)
        {
            arr[i][j] = ' ';
        }
    }

    Star(num, a, b);

    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < d; j++)
        {
            printf("%c", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}
