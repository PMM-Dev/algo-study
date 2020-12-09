// https://www.acmicpc.net/problem/17281
// ⚾

// 몰라 못품 ㅅㄱ
// 가능한 모든 경우의 수를 확인해보는 brute force 식 알고리즘
// 주석되어 있는 출력문으로 확인했지만 첫 번째 테스트 케이스 조차에서도
// 한번도 홈런이 확인되지 않음.

#include <bits/stdc++.h>

#define endl "\n"

using namespace std;

int t, maxScore = 0;
int sequence[9] = {2, 3, 4, 1, 5, 6, 7, 8, 9};
vector<vector<int> > scores(50, vector<int>(9, 0));

bool runThrough(int idx, int kind) {
    if (idx + kind > 3)
        return true;
    else
        return false;
}

int compareScore() {
    int score = 0;
    int hitterIdx = -1;

    for (int e = 0; e < t; e++) {
        int out = 0;
        bool base[4];
        fill_n(base, 4, false);

        while (true) {
            hitterIdx = hitterIdx == 8 ? 0 : hitterIdx + 1;

            base[0] = true;
            int kind = scores[e][sequence[hitterIdx]];
            if (kind == 0) {
                out++;
                if (out == 3)
                    break;
            } else if (kind == 4) {
                // cout << "h " << endl;
                for (int j = 0; j <= 3; j++) {
                    if (base[j]) {
                        score++;
                    }
                }
            } else {
                for (int j = 3; j >= 0; j--) {
                    if (base[j]) {
                        if (runThrough(j, kind))
                            score++;
                        else
                            base[j + kind] = true;
                    }
                }
            }
        }
    }
    // cout << score << endl;
    return score;
}

void permuationRecursion(int idx) {
    if (idx == 8) {
        // for (int i = 0; i < 9; i++) {
        //     cout << sequence[i] << " ";
        // }
        // cout << endl;

        maxScore = max(compareScore(), maxScore);
    }

    for (int i = idx; i < 9; i++) {
        if (i == 3) continue;

        swap(sequence[idx], sequence[i]);
        permuationRecursion(idx + 1 == 3 ? 4 : idx + 1);
        swap(sequence[idx], sequence[i]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> t;
    for (int i = 0; i < t; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> scores[i][j];
        }
    }

    permuationRecursion(0);
    cout << maxScore << endl;
    return 0;
}


