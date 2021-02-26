// 별 찍기 11
// https://www.acmicpc.net/problem/2448
// Memory	: 	41080	KB
// Time		: 	648		ms

/*
	https://ssu-gongdoli.tistory.com/79?category=928309 참고
*/

#include <iostream>
#include <algorithm>
using namespace std;

int N;


char shape[3][6] =
{
	"  *  ",
	" * * ",
	"*****"
};

char board[5000][8000];

void process(int num, int r, int c)
{
	if (num <= 1)
	{
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 5; j++)
				board[r + i][c + j] = shape[i][j];
		return;
	}
	// 3 x 2^N
	process(num / 2, r, c + 3 * num / 2);
	process(num / 2, r + 3 * num / 2, c);
	process(num / 2, r + 3 * num / 2, c + 3 * num);
}

int main() {
	cin >> N;

	// 3 x 2^N
	process(N / 3, 0, 0);

	// for (int i = 0; i < N; i++, cout << "\n")
	// 아래 for문과 동일하면서 더 짧게 작성 가능

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N * 2; j++) {
			char out = board[i][j] == '*' ? '*' : ' ';
			cout << out;
		}
		cout << "\n";
	}
	return 0;
}