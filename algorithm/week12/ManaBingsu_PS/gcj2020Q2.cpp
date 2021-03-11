// GCJ 2020 Qualification 2
// https://codingcompetitions.withgoogle.com/codejam
// Memory	: 	KB
// Time		: 	ms

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    int T, index = 0;
    cin >> T;
    while (index++ < T) {
        int arr[101];
        fill(arr, arr + 101, 0);
        string str, result = "";
        cin >> str;
        for (int i = 1; i <= str.length(); ++i) {
            arr[i] = str[i - 1] - '0';
            auto gap = arr[i] - arr[i - 1];
            if (gap != 0) {
                while (gap) {
                    result = gap > 0 ? result + '(' : result + ')';
                    gap = gap > 0 ? gap - 1 : gap + 1;
                }
            }
            result += str[i - 1];
        }
        for (int i = 0; i < str[str.length() - 1] -'0'; result += ')', ++i);
        cout << "Case #" << index << ": " << result << "\n";
    }
    return 0;
}