#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

int main()
{
    clock_t start = clock();

    vector<int> food_times;
    long long k;
    int answer = -1;
    long long time = 0;
    int pivot = 0;
    int check = 0;
    int N;

    cin >> N;

    food_times.resize(N);
    for (int i = 0; i < N; i++)
    {
        cin >> food_times[i];
    }

    cin >> k;

    while (true)
    {
        int cur = pivot;

        while (true)
        {
            if (pivot == food_times.size())
                pivot = 0;
            if (food_times[pivot] != 0)
                break;
            pivot++;
            if (cur == pivot)
            {
                check = 1;
                break;
            }
        }
        if (check)
            break;

        if (time == k)
        {
            answer = pivot;
            break;
        }

        food_times[pivot]--;
        time++;
        pivot++;
    }

    if (answer != -1)
        answer++;
    
    cout << answer<<"\n";

    clock_t end = clock();
    printf("실행시간: %lf초\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}