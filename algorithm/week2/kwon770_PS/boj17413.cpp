// Memory : 2296 KB
// Time : 0 ms

#include <bits/stdc++.h>

#define endl "\n"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string input;
    getline(cin, input);

    int wordStartIdx = 0;
    bool tagStart = false;
    for (int i = 0; i < (int)input.length(); i++) {
        if (i == (int)input.length() - 1 && input[i] != '>')
            reverse(input.begin() + wordStartIdx, input.begin() + i + 1);

        if (input[i] == '<') {
            tagStart = true;

            if (wordStartIdx != i) {
                reverse(input.begin() + wordStartIdx, input.begin() + i);
            }
        } else if (input[i] == '>') {
            tagStart = false;
            wordStartIdx = i + 1;
        } else if (input[i] == ' ') {
            if (input[wordStartIdx] != ' ' && !tagStart) {
                reverse(input.begin() + wordStartIdx, input.begin() + i);
            }

            wordStartIdx = i + 1;
        }
    }

    cout << input << endl;
    return 0;
}
