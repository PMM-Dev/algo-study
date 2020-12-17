// Memory : 2016 KB
// Time : 0 ms

#include <bits/stdc++.h>

#define endl "\n"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string ipt;
    cin >> ipt;
    bool isLeft = true;
    int left = 0, right = 0;
    for (int i = 0; i < (int)ipt.length(); i++) {
        if (ipt[i] == '@') {
            if (isLeft)
                left++;
            else
                right++;

        } else if (ipt[i] == '(') {
            isLeft = false;
        }
    }
    cout << left << " " << right;
    return 0;
}
