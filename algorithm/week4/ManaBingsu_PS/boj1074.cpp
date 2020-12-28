// Z
// https://www.acmicpc.net/problem/1074
// Memory	:	2200 KB
// Time		:	0 ms

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int N, R, C;
long long counter = 0;

void recursion(int N, int r, int c)  {
	if (N == 0) {
		cout << counter << "\n";
		return;
	}
	
	if (R < pow(2, N - 1) + r  && C < pow(2, N - 1) + c) {
		counter += 0;
	}
	else if (R < pow(2, N - 1) + r && C >= pow(2, N - 1) + c) {
		counter += pow(pow(2, N - 1), 2);
		c += pow(2, N - 1);
	}
	else if (R >= pow(2, N - 1) + r && C < pow(2, N - 1) + c) {
		counter += pow(pow(2, N - 1), 2) * 2;
		r += pow(2, N - 1);
	}
	else {
		counter += pow(pow(2, N - 1), 2) * 3;
		c += pow(2, N - 1);
		r += pow(2, N - 1);
	}
	recursion(N - 1, r, c);
}

int main(){
	cin >> N >> R >> C;
	recursion(N, 0, 0); 
	return 0;
}
