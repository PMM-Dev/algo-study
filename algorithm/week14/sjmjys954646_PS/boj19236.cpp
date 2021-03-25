#include <cstdio>
#include <algorithm>

using namespace std;

/*
https://kibbomi.tistory.com/140
구현에 백트래킹 적용 문제인데 계속 틀려서 그냥 답지봄

<개선안>

1. 백트래킹 같은 경우는 전역변수를 이용한 초기화는 자제

2. 문제에 주어진 데이터를 더 유연하게 자료화

3. 1번과 매한가지인데 매개변수 함수 전달을 잘 활용

*/

struct FISH
{
    int y, x, dir;
    bool isdead;
};

const int dx[] = {0, -1, -1, -1, 0, 1, 1, 1};
const int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};

void cpmap(int dest[4][4], int src[4][4])
{
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            dest[i][j] = src[i][j];
    return;
}

void cpfish(FISH dest[17], FISH src[17])
{
    for (int i = 0; i <= 16; ++i)
        dest[i] = src[i];
}

int dfs(int origin_map[][4], int y, int x, int dir, FISH origin_fish[17])
{

    int map[4][4];
    FISH fish[17];
    cpmap(map, origin_map);
    cpfish(fish, origin_fish);
    //상어 y,x에 놓을것
    int eat = map[y][x];
    //여기서 dir결정
    dir = fish[map[y][x]].dir;

    fish[map[y][x]].x = -1;

    fish[map[y][x]].y = -1;
    fish[map[y][x]].isdead = true;
    map[y][x] = 0;

    int ans = 0;

    //물고기 이동
    for (int i = 1; i <= 16; ++i)
    {
        if (fish[i].isdead == false)
        {

            int nx = fish[i].x, ny = fish[i].y;
            for (int d = 0; d <= 7; ++d)
            {
                int cx = fish[i].x + dx[fish[i].dir];
                int cy = fish[i].y + dy[fish[i].dir];

                //상어면 방향바꾸기 1 ~ 8이지
                if (cx == x && cy == y)
                {
                    fish[i].dir = (fish[i].dir + 1) % 8;
                    continue;
                }
                //경계밖이면 방향바꾸기
                if (cx < 0 || cy < 0 || cx >= 4 || cy >= 4)
                {
                    fish[i].dir = (fish[i].dir + 1) % 8;
                    continue;
                }

                nx = cx;
                ny = cy;
                break;
            }

            //next위치의 물고기와 자리 바꾸기
            if (map[ny][nx] == 0)
            {
                map[fish[i].y][fish[i].x] = 0;
                map[ny][nx] = i;
                fish[i].y = ny;
                fish[i].x = nx;
            }
            else
            {
                int tx, ty, temp;
                tx = fish[i].x;
                ty = fish[i].y;
                fish[i].x = nx;
                fish[i].y = ny;
                fish[map[ny][nx]].x = tx;
                fish[map[ny][nx]].y = ty;

                map[ty][tx] = map[ny][nx];
                map[ny][nx] = i;
            }
        }
    }

    int cy = y + dy[dir];
    int cx = x + dx[dir];

    while (!(cy < 0 || cx < 0 || cy >= 4 || cx >= 4))
    {
        if (map[cy][cx] != 0)
            ans = max(ans, dfs(map, cy, cx, dir, fish));
        cy += dy[dir];
        cx += dx[dir];
    }
    return ans + eat;
}

int main()
{
    freopen("input.txt", "r", stdin);
    int map[4][4] = {0};
    FISH fish[17];
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
        {
            int l, d;
            scanf("%d %d", &l, &d);
            fish[l].y = i;
            fish[l].x = j;
            fish[l].isdead = false;
            fish[l].dir = d - 1;
            map[i][j] = l;
        }

    printf("%d", dfs(map, 0, 0, 0, fish));

    return 0;
}