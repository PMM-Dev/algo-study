// Memory : 2216 KB
// Time : 0 ms
#include <bits/stdc++.h>

#define endl "\n"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string str[50];
    char ans[50];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> str[i];
    }

    for (int i = 0; i < (int)str[0].length(); i++) {
        bool isSame = true;
        char chr = str[0][i];
        for (int j = 0; j < n; j++) {
            if (str[j][i] != chr) {
                isSame = false;
                break;
            }
        }

        if (isSame)
            ans[i] = str[0][i];
        else
            ans[i] = '?';
    }

    cout << ans << endl;

    return 0;
}
