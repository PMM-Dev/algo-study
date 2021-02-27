//6132kb 84ms
//COMMENT
/*
초기에 자르는 지점 중심을 불순물 기준으로 잡았더니
최종적으로 짤랐을때 최종모양은 같지만 순서만 달라지는 중복되는 현상이 발견됨
그래서 이를 해결하기 위해 아차원벡터를 map에도 넣어봤지만 WC

그래서 나눌때마다 확인해주려고 새로운 코드를 짯으나 
반례가 있는지 이유를 알수없는 WR
https://tastyprogramming.tistory.com/39
그래서 가장 비슷한 답지를 참고했지만 WR
*/
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
int arr[21][21];

int cut(int startX, int endX, int startY, int endY, int dir) //1세로 2가로
{
    vector<pii> hubo; // y, x
    int jewel = 0;
    int bulsun = 0;

    for (int i = startY; i <= endY; i++)
    {
        for (int j = startX; j <= endX; j++)
        {
            if (arr[i][j] == 1)
            {
                bulsun++;
                hubo.pb({i, j});
            }
            if (arr[i][j] == 2)
            {
                jewel++;
            }
        }
    }

    if (jewel == 1 && bulsun == 0)
        return 1;
    else if (jewel > 1 && bulsun == 0)
        return 0;
    else if (jewel == 0)
        return 0;
    else if (bulsun > 0)
    {
        int ans = 0;
        for (int k = 0; k < hubo.size(); k++)
        {
            int huboX = hubo[k].S;
            int huboY = hubo[k].F;

            if (dir == 0 || dir == 1)
            {
                bool pos = true;
                for (int i = startY; i <= endY; i++) // 세로로 그을수 있는 경우
                {
                    if (arr[i][huboX] == 2)
                        pos = false;
                }
                if (huboX - 1 < startX || endX < 1 + huboX)
                    continue;
                if (!pos)
                    continue;
                int pos1 = cut(startX, huboX - 1, startY, endY, 2);
                int pos2 = cut(huboX + 1, endX, startY, endY, 2);
                ans += pos1 * pos2;
            }
            if (dir == 0 || dir == 2) //가로 짜르기
            {
                bool pos = true;
                for (int i = startX; i <= endX; i++) // 가로로 그을수 있는 경우
                {
                    if (arr[huboY][i] == 2)
                        pos = false;
                }
                if (huboY - 1 < startY || endY < 1 + huboY)
                    continue;
                if (!pos)
                    continue;
                int pos1 = cut(startX, endX, startY, huboY - 1, 1);
                int pos2 = cut(startX, endX, huboY + 1, endY, 1);
                ans += pos1 * pos2;
            }
        }
        return ans;
    }
    return 0;
}

int main()
{

    scanf("%d", &N);

    rep(i, N)
    {
        rep(j, N)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    int t = cut(0, N - 1, 0, N - 1, 0);

    if (t == 0)
        t = -1;
    printf("%d", t);

    return 0;
}
