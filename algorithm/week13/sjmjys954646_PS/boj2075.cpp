//freopen("input.txt", "r", stdin);
//10828kb 512ms
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
#include <string.h>
#include <map>
#include <limits.h>

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

const int INF = 987654321;

//그냥 벡터에 다 입력받고 출력하면 메모리초과 납니다.(직접해봄)
int arr[1502][1502];

struct st
{
    int data;
    int y;
    int x;
};

bool operator<(st a, st b)
{
    return a.data < b.data;
}

priority_queue<st> pq;

int main()
{
    freopen("input.txt", "r", stdin);

    int N, tmp;

    scanf("%d", &N);

    rep(i, N)
    {
        rep(j, N)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    rep(i, N)
    {
        pq.push({arr[N - 1][i], N - 1, i});
    }

    int cnt = N - 1;
    while (cnt--)
    {
        int cur = pq.top().data;
        int cury = pq.top().y;
        int curx = pq.top().x;
        pq.pop();

        pq.push({arr[cury - 1][curx], cury - 1, curx});
    }
    cout << pq.top().data;

    return 0;
}