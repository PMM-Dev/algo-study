// Memory : 2020 KB
// Time : 648 ms
//

#include <iostream>
#include <utility>
#include <vector>
#define endl "\n"
using namespace std;

vector<int> dx = {-1, +1, 0, 0};
vector<int> dy = {0, 0, -1, +1};

int n, m, size;
int maxSecurity = -1;
vector<vector<int> > lab(9, vector<int>(9, -1));

pair<int, int> getCoor(int idx) {
    return make_pair(idx % m == 0 ? idx / m - 1 : idx / m, idx % m == 0 ? m - 1 : idx % m - 1);
}

int findEmpty(int idx) {
    while (idx <= size) {
        idx++;
        pair<int, int> coor = getCoor(idx);

        if (lab[coor.first][coor.second] == 0) break;
    }
    return idx;
}

void simulate() {
    auto tmpLab = lab;
    int spread = -1;
    while (spread != 0) {
        spread = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (lab[i][j] == 2) {
                    int tx, ty;
                    for (int k = 0; k < 4; k++) {
                        tx = i + dx[k];
                        ty = j + dy[k];

                        if (tx < 0 || ty < 0 || tx >= n || ty >= m) continue;

                        if (lab[tx][ty] == 0) {
                            lab[tx][ty] = 2;
                            spread++;
                        }
                    }
                }
            }
        }
    }

    int security = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (lab[i][j] == 0) {
                security++;
            }
        }
    }

    lab = tmpLab;
    maxSecurity = max(maxSecurity, security);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> lab[i][j];
        }
    }

    int first = 0, second = 0, third = 0;
    size = n * m;
    while (true) {
        first = findEmpty(first);
        if (first > size - 2) break;

        pair<int, int> firstCoor = getCoor(first);
        lab[firstCoor.first][firstCoor.second] = 1;

        while (true) {
            second = findEmpty(second);
            if (second > size - 1) break;

            pair<int, int> secondCoor = getCoor(second);
            lab[secondCoor.first][secondCoor.second] = 1;

            while (true) {
                third = findEmpty(third);
                if (third > size) break;

                pair<int, int> thirdCoor = getCoor(third);
                lab[thirdCoor.first][thirdCoor.second] = 1;

                simulate();

                lab[thirdCoor.first][thirdCoor.second] = 0;
            }

            third = 0;
            lab[secondCoor.first][secondCoor.second] = 0;
        }

        second = 0;
        lab[firstCoor.first][firstCoor.second] = 0;
    }

    cout << maxSecurity << endl;
    return 0;
}

