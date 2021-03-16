// 카드 정렬하기 
// https://www.acmicpc.net/problem/1715
// Memory	: 	2796    KB
// Time		: 	40      ms

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int N;

int solve() {
    int result = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    while (N--) {
        int num = 0;
        cin >> num;
        pq.push(num);
    }
    while (pq.size() > 1) {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        pq.push(a + b);
        result += a + b;
    }
    return result;
}

int main() {
    cin >> N;
    cout << solve() << "\n";
    return 0;
}