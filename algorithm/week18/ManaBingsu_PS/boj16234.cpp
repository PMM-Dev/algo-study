// 인구 이동
// https://www.acmicpc.net/problem/16234
// Memory	:   2072    KB
// Time		:   148     ms

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int N, L, R;
int dr[4] = { 1, 0, -1, 0 };
int dc[4] = { 0, 1, 0, -1 };
bool visited[50][50];
int board[50][50];

int sum = 0;
int result = 0;

void input() {
    cin >> N >> L >> R;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> board[i][j];
}

void dfs(vector<pair<int, int>>& track, int pr, int pc, int r, int c, int depth) {
    if (visited[r][c])
        return;
    if (r < 0 || r >= N || c < 0 || c >= N)
        return;
    auto calc = abs(board[r][c] - board[pr][pc]);
    if (depth != 0 && calc < L || calc > R)
        return;

    track.push_back(make_pair(r, c));
    visited[r][c] = true;
    sum += board[r][c];

    for (int i = 0; i < 4; ++i) 
        dfs(track, r, c, r + dr[i], c + dc[i], depth + 1);
}

void solve() {
    vector<pair<int, int>> track = vector<pair<int, int>>();

    auto isMoved = true;
    while (isMoved) {
        isMoved = false;

        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                visited[i][j] = false;

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                track.clear();
                sum = 0;
                if (!visited[i][j]) {
                    dfs(track, i, j, i, j, 0);
                    if (sum > board[i][j])
                        isMoved = true;
                    for (auto it = track.begin(); it != track.end(); ++it)
                        board[(*it).first][(*it).second] = sum / track.size();
                }
            }
        }
        if (isMoved)
            ++result;
    }
    cout << result << "\n";
}

int main() {
    input();
    solve();
    return 0;
}
