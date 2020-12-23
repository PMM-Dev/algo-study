// Memory : 2016 KB
// Time : 0 ms

#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int a, b, n, m;
// direction, (x, y)
vector<pair<int, pair<int, int> > > robots;

bool checkCollision(int idx, int x, int y) {
    for (int i = 0; i < n; i++) {
        if (i == idx) continue;

        if (robots[i].second.first == x &&
            robots[i].second.second == y) {
            cout << "Robot " << idx + 1 << " crashes into robot " << i + 1 << endl;
            return false;
        }
    }

    if (x < 1 || y < 1 || x > a || y > b) {
        cout << "Robot " << idx + 1 << " crashes into the wall" << endl;
        return false;
    }

    return true;
}

int moveX(int x, int dir) {
    if (dir == 1)
        return ++x;
    else if (dir == 3)
        return --x;
    return x;
}

int moveY(int y, int dir) {
    if (dir == 0)
        return ++y;
    else if (dir == 2)
        return --y;
    return y;
}

bool run(int idx, char command, int repeat) {
    int tmpDir = robots[idx].first;
    int tmpX = robots[idx].second.first;
    int tmpY = robots[idx].second.second;

    if (command == 'F') {
        for (int i = 0; i < repeat; i++) {
            tmpX = moveX(tmpX, tmpDir);
            tmpY = moveY(tmpY, tmpDir);

            if (!checkCollision(idx, tmpX, tmpY)) return false;
        }
    } else {
        if (command == 'L') {
            tmpDir -= repeat;
            tmpDir = tmpDir < 0 ? tmpDir % 4 + 4 : tmpDir;
        } else {
            tmpDir += repeat;
            tmpDir = tmpDir > 3 ? tmpDir % 4 : tmpDir;
        }

        robots[idx] = make_pair(tmpDir, robots[idx].second);
    }

    robots[idx] = make_pair(tmpDir, make_pair(tmpX, tmpY));
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> a >> b >> n >> m;
    for (int i = 0; i < n; i++) {
        int x, y, direction;
        char dir;
        cin >> x >> y >> dir;

        switch (dir) {
            case 'N':
                direction = 0;
                break;
            case 'E':
                direction = 1;
                break;
            case 'S':
                direction = 2;
                break;
            case 'W':
                direction = 3;
        }

        robots.push_back(make_pair(direction, make_pair(x, y)));
    }

    for (int i = 0; i < m; i++) {
        int idx, repeat;
        char command;
        cin >> idx >> command >> repeat;
        if (!run(idx - 1, command, repeat)) return 0;
    }

    cout << "OK" << endl;
    return 0;
}
