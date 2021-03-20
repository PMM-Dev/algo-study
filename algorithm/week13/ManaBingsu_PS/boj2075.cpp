// N번째 큰 수
// https://www.acmicpc.net/problem/2075
// Memory	: 	2152    KB
// Time		: 	324     ms

#include <iostream>
#include <queue>

using namespace std;

int N;

void solve() {
    int result = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    int num = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> num;
            if (pq.size() == N && num > pq.top()) {
                pq.pop();
                pq.push(num);
            }
            else if (pq.size() < N)
                pq.push(num);
        }
    }
    cout << pq.top();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(); cout.tie();
    cin >> N;
    solve();
    return 0;
}