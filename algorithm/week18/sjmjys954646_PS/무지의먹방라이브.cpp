#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>
#include <time.h>

using namespace std;

//pair의 두번째 값 우선으로 계산하는 함수
bool cmp(const std::pair<int, int>& left, const std::pair<int, int>& right) {
    return left.second < right.second;
}

int main()
{
    clock_t start = clock();

    vector<pair<long long, int>> food_times_index;
    vector<pair<long long, int>> left;
    long long N;
    long long answer = 0;//정답
    long long before = 0;//이전에 확인한 배열
    long long pivot = 0;// 배열에서 현재 확인하는 위치
    long long cycle = 0;// 현재 사이클(한사이클당 먹는 음식량)
    long long tot = 0;// 음식의 총량
    long long k;// 방송이 중단된 시간

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        //입력을 받아 음식량과 index를 vector에 넣습니다.
        int food;
        cin >> food;
        food_times_index.push_back({food,i+1});
        tot += food;
    }

    cin >> k;

    cycle = N;

    //정렬해서 가장 적은 음식량 부터 한번에 뽑아 냅니다.
    sort(food_times_index.begin(), food_times_index.end());

    //음식총량 보다 시간이 오래걸릴경우 남는 음식이 없으므로 -1이 됩니다.
    if (tot <= k)
    {
        answer = -1;
    }
    else
    {
        //순서대로 있는 음식량 중에서 이전 음식량의 차이 만큼과 cycle의 곱이 k보다 작은 동안 반복합니다.
        while ((food_times_index[pivot].first - before) * cycle <= k)
        {
            //음식량 * 사이클 = 경과 시간 이므로 k에서 그만큼 빼줍니다.
            k -= (food_times_index[pivot].first - before) * cycle;
            //이전 음식량 저장, 배열에서 확인위치, cycle을 각각 계산합니다.
            before = food_times_index[pivot].first;
            pivot++;
            cycle--;
        }
        //남은 시간 계산을 위해 cycle과 나머지연산을 합니다.
        k = k % cycle;
        //아직 남아있는 음식들끼리 index순으로 정렬을 한후 k만큼 더해줘서 다음에 먹을 음식을 계산합니다.
        sort(food_times_index.begin() + pivot, food_times_index.begin() + food_times_index.size(), cmp);
        answer = food_times_index[pivot + k].second;
    }

    cout << answer << "\n";

    clock_t end = clock();

    printf("실행시간: %lf초\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}
