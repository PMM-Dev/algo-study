// ∏ÌªÛ πÊ«ÿ≤€
// https://www.acmicpc.net/problem/15980
// Memory	:   17652   KB
// Time		:   48   ms

#include <iostream>
#include <algorithm>
#include <string.h>
#include <cmath>

using namespace std;

int N, M;
int inputs[2000][2000];
int colSums[2000];

void input() {
    cin >> N >> M;
    for (auto i = 0; i < N; ++i) {
        auto ch = '\0';
        cin >> ch;
        auto str = string();
        cin >> str;
        auto correct = ch == 'L' ? -1 : 1;
        for (auto j = 0; j < M; ++j) {
            auto val = (str[j] - '0') * correct;
            inputs[i][j] = val;
            colSums[j] += val;
        }
    }
    for (auto i = 1; i < M; ++i)
        colSums[i] += colSums[i - 1];
}

void solve() {
    auto min = 4000001, catchIdx = 0;
    for (auto i = 0; i < N; ++i) {
        auto max = 0;
        int copySums[2000];
        memcpy(copySums, colSums, sizeof(int) * 2000);
        for (auto j = 0; j < M; ++j) {
            if (inputs[i][j] != 0) {
                for (auto k = j; k < M; ++k)
                    copySums[k] += (inputs[i][j]) * -1;
            }
        }
        for (auto j = 0; j < M; ++j) {
            auto absSum = abs(copySums[j]);
            if (max < absSum)
                max = absSum;
        }
        if (max < min) {
            min = max;
            catchIdx = i;
        }
    }

    cout << catchIdx + 1 << "\n";
    cout << min << "\n";
}

int main() {
    fill_n(colSums, 2000, 0);
    input();
    solve();
    return 0;
}