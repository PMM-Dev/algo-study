// 중앙값 구하기
// https://www.acmicpc.net/problem/2696
// Memory	: 2156  KB
// Time		: 4     ms

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int N;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int M;
        cin >> M;
        priority_queue<int, vector<int>, less<int>> smallQ;
        priority_queue<int, vector<int>, greater<int>> bigQ;
        queue<int> resultQ;
        int num = 0;
        cin >> num;
        int mid = num;
        resultQ.push(num);

        for (int i = 1; i < M; i++) {
            cin >> num;
            if (num < mid)
                smallQ.push(num);
            else
                bigQ.push(num);
            if (i % 2 == 0) {
                if (smallQ.size() < bigQ.size()) {
                    smallQ.push(mid);
                    mid = bigQ.top();
                    bigQ.pop();
                }
                else if (smallQ.size() > bigQ.size()) {
                    bigQ.push(mid);
                    mid = smallQ.top();
                    smallQ.pop();
                }
                resultQ.push(mid);
            }
        }

        cout << M / 2 + 1 << "\n";
        int cut = 0;
        while (!resultQ.empty()) {
            cout << resultQ.front() << " ";
            resultQ.pop();
            if (++cut == 10)
                cout << "\n";
        }
        cout << "\n";
    }
    return 0;
}