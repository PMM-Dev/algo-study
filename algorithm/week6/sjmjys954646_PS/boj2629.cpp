//5648kb 0ms
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

int chewArr[31];
int chewN;
int goosulN;
int cache[31][30003];
//캐슁은 왼쪽이 사용한 추 오른쪽이 오른쪽접시 라고 생각하고 해결을 하려 했다
//냅색문제와 비슷하다고 하는점은 추 하나를 오른쪽접시에 올릴지 왼쪽에 올릴지 아니면 안쓸지를 정해야 되는점이다.
//하지만 예를들어 오른쪽에 1, 3 추를 올리다 갑자기 왼쪽에 7추를 올리면 구하고자하는 무게가 음수가 되는 문제가 생긴다
//예외처리 해서 return 해버리는 방식은 다음 추를 사용하는 경우의 수가 사라진다
//그래서 결국 답지를 봤는데 절대값처리를 하면 중복처리가 되서 어차피 나중에 사라진다고 한다.

void dp(int cur, int sum)
{
    if (cur > chewN)
        return;

    int &ret = cache[cur][sum];
    if (ret != -1)
        return;
    //메모이제션은 [2][4] 2개사용해서(1,3) 4kg (4) 4kg 이런것 중복처리 해결
    ret = 1;

    dp(cur + 1, abs(sum - chewArr[cur]));
    dp(cur + 1, sum);
    dp(cur + 1, sum + chewArr[cur]);

    return;
}

int main()
{
    memset(cache, -1, sizeof(cache));

    scanf("%d", &chewN);

    for (int i = 0; i < chewN; i++)
    {
        scanf("%d", &chewArr[i]);
    }

    scanf("%d", &goosulN);

    dp(0, 0);

    while (goosulN--)
    {
        int query;
        scanf("%d", &query);

        if (cache[chewN][query] == 1)
            printf("Y ");
        else
            printf("N ");
    }

    return 0;
}