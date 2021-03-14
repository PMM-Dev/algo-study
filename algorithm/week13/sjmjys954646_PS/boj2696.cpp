//freopen("input.txt", "r", stdin);
//2016kb 4ms
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

int main()
{
    freopen("input.txt", "r", stdin);

    int testcase;

    scanf("%d", &testcase);

    while (testcase--)
    {
        priority_queue<int, vector<int>, less<int>> max_heap;
        priority_queue<int, vector<int>, greater<int>> min_heap;

        int N, num;
        scanf("%d", &N);
        printf("%d\n", (N + 1) / 2);

        for (int i = 0; i < N; i++)
        {
            scanf("%d", &num);
            if (max_heap.empty() && min_heap.empty())
                max_heap.push(num);
            else if (max_heap.size() == min_heap.size())
                max_heap.push(num);
            else
                min_heap.push(num);

            if (!max_heap.empty() && !min_heap.empty() && max_heap.top() > min_heap.top())
            {
                int tmp = max_heap.top();
                max_heap.pop();
                max_heap.push(min_heap.top());
                min_heap.pop();
                min_heap.push(tmp);
            }
            if (i % 2 == 0)
            {
                cout << max_heap.top() << " ";

                if ((i / 2) % 10 == 9)
                {
                    printf("\n");
                }
            }
        }
        printf("\n");
    }

    return 0;
}