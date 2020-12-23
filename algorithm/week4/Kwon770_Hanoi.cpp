#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
#include <string>
#include <queue>
#include <stack>
#include <cstring>
using namespace std;

int N;


void hanoi(int n, int from, int by, int to) 
{
    if (n == 1)
    {
        cout << from << " " << to << "\n";
        return;
    }
    else
    {
        hanoi(n - 1, from, to, by);
        cout << from << " " << to << "\n";
        hanoi(n- 1, by, from, to);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    string s = to_string(pow(2, N));
    int idx = s.find('.');
    s = s.substr(0, idx);
    s[s.length() - 1] -= 1;
    cout << s<<"\n";


    if(N<=20)
        hanoi(N, 1, 2, 3);


    return 0;
}
