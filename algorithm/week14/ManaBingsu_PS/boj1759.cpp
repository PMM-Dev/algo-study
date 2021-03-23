// 암호 만들기
// https://www.acmicpc.net/problem/1759
// Memory	:  2016     KB
// Time		:  0        ms

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int L, C;
vector<char> inputs;
bool memos[15];
char pw[15];

void input() {
    cin >> L >> C;
    auto idx = 0;
    while (idx < C) {
        auto ch = '\0';
        cin >> ch;
        inputs.push_back(ch);
        idx++;
    }
    sort(inputs.begin(), inputs.end());
    pw[C] = '\0';
}

bool isValid(char* str) {
    auto idx = 0, cons = 0, vow = 0;
    auto vows = { 'a', 'e', 'i', 'o', 'u' };
    while (idx < C) {
        auto it = vows.begin();
        while (it != vows.end()) {
            if (str[idx] == *it)
                ++vow;
            ++it;
        }
        ++idx;
    }
    cons = L - vow;
    if (cons >= 2 && vow >= 1)
        return true;
    else
        return false;
}

void solve(int val, int depth) {
    if (depth >= L) {
        if (isValid(pw))
            cout << pw << "\n";
        return;
    }
    for (auto i = val; i < C; ++i) {
        if (!memos[i]) {
            memos[i] = true;
            pw[depth] = inputs[i];
            solve(i, depth + 1);
            memos[i] = false;
        }
    }
}

int main() {
    input();
    solve(0, 0);
    return 0;
}