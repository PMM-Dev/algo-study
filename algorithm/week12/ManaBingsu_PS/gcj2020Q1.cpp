// GCJ 2020 Qualification 1
// https://codingcompetitions.withgoogle.com/codejam
// Memory	: 	KB
// Time		: 	ms

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    bool m1[101][101];
    bool m2[101][101];
    bool memo[101][101];

    int T;
    cin >> T;
    int index = 0;
    while (index++ < T) {
        int N, k = 0, r = 0, c = 0;
        cin >> N;
        fill(&m1[0][0], &m1[0][0] + sizeof(m1), false);
        fill(&m2[0][0], &m2[0][0] + sizeof(m2), false);
        fill(&memo[0][0], &memo[0][0] + sizeof(memo), false);
        for (int i = 1; i <= N; ++i) {
            auto num = 0;
            for (int j = 1; j <= N; ++j) {
                cin >> num;
                if (i == j)
                    k += num;
                if (m1[i][num] != false && memo[i][0] != true) {
                    memo[i][0] = true;
                    ++r;
                }
                if (m2[num][j] != false && memo[0][j] != true) {
                    memo[0][j] = true;
                    ++c;
                }
                m1[i][num] = true;
                m2[num][j] = true;
            }
        }
        cout << "Case #" << index << ": " << k << " " << r << " " << c << "\n";
    }
    return 0;
}