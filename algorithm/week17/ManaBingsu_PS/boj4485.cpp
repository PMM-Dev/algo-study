// ³ì»ö ¿Ê ÀÔÀº ¾Ö°¡ Á©´ÙÁö?
// https://www.acmicpc.net/problem/4485
// Memory	:   3348    KB
// Time		:   16      ms

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>

#define MAX 125

using namespace std;

class Node{
public:
    int value;
    int y, x;
    vector<Node*> nodes;

    Node() {
    }

    Node(int y, int x) {
        value = 0;
        nodes = vector<Node*>();
        this->y = y;
        this->x = x;
    }
    void Initialize(){
        value = 0;
        nodes = vector<Node*>();
    }
};

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int dist[MAX][MAX];
Node cave[MAX][MAX];

void solve(int index, int size) {
    for (auto i = 0; i < size; ++i) {
        for (auto j = 0; j < size; ++j) {
            cin >> cave[i][j].value;
            for (auto k = 0; k < 4; ++k) {
                auto x = j + dx[k];
                auto y = i + dy[k];
                if (x > -1 && x < size && y > -1 && y < size) {
                    cave[i][j].nodes.push_back(&cave[y][x]);
                }
            }
        }
    }

    for (auto i = 0; i < size; ++i)
        for (auto j = 0; j < size; ++j)
            dist[i][j] = 99999;

    priority_queue<pair<int, pair<int, int>>> pq = priority_queue<pair<int, pair<int, int>>>();

    pq.push(make_pair(-cave[0][0].value, make_pair(0, 0)));
    dist[0][0] = cave[0][0].value;

    while (!pq.empty()) {
        auto node =  cave[pq.top().second.first][pq.top().second.second];
        auto cost = -pq.top().first;
        pq.pop();

        if (cost > dist[node.y][node.x])
            continue;

        for (int i = 0; i < node.nodes.size(); ++i) {
            auto nextNode = node.nodes[i];
            auto nextCost = cost + nextNode->value;

            if (nextCost < dist[nextNode->y][nextNode->x]) {
                dist[nextNode->y][nextNode->x] = nextCost;
                pq.push(make_pair(-nextCost, make_pair(nextNode->y, nextNode->x)));
            }
        }
    }

    cout << "Problem " << index + 1 << ": " << dist[size - 1][size - 1] << "\n";

    for (auto i = 0; i < MAX; ++i)
        for (auto j = 0; j < MAX; ++j)
            cave[i][j].Initialize();
}

int main() {
    for (auto i = 0; i < MAX; ++i)
        for (auto j = 0; j < MAX; ++j)
            cave[i][j] = Node(i, j);

    int size = 9999, index = 0;
    cin >> size;
    while (size > 0) {
        solve(index, size);
        index++;
        cin >> size;
    }

    return 0;
}
