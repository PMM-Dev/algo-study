// 무지의 먹방 라이브
// https://programmers.co.kr/learn/courses/30/lessons/42891
// Memory	:     KB
// Time		:       ms

#include <iostream>
#include <vector>
#include <string>
#include <utility>

using namespace std;

int solution(vector<int> food_times, long long k) {
    int answer = 0;
    vector<pair<int, int>> pairs = vector<pair<int, int>>();

    if (food_times.size() == 1)
        pairs.push_back(make_pair(0, 0));
    else
        pairs.push_back(make_pair(food_times.size() - 1, 1));
    for (int i = 1; i < food_times.size(); ++i)
        pairs.push_back(make_pair(i - 1, (i + 1) % food_times.size()));

    int index = 0;
    for (long long i = 0; i < k; ++i) {
        if (pairs[index].first == pairs[index].second)
            return -1;

        if (food_times[index] == 0) {
            int count = 0;
            while (food_times[index] == 0) {
                pairs[pairs[index].first].second = pairs[index].second;
                pairs[pairs[index].second].first = pairs[index].first;
                index = pairs[index].second;
                ++count;
                if (count == food_times.size())
                    return -1;
            }
        }
        --food_times[index];
        index = pairs[index].second;
    }
    answer = index;
    return answer + 1;
}

int main() {
    int a;
    vector<int> foods = vector<int>();
    for (int i = 0; i < 1; ++i) {
        cin >> a;
        foods.push_back(a);
    }
    long long k;
    cin >> k;
    cout << solution(foods, k) << "\n";
    return 0;
}
