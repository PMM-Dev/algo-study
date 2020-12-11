#include <iostream>
#include <algorithm>
#define MAXSIZE 700

int M, N;
int sizeArr[MAXSIZE * 2 - 1] = { 0, };
int nest[MAXSIZE][MAXSIZE];
int grow_store[MAXSIZE][MAXSIZE];

using namespace std;

void growFirst() {
	int index = 0;
	for (int i = M - 1; i >= 0; i--) {
		nest[i][0] += sizeArr[index];
		grow_store[i][0] = sizeArr[index++];
	}
	for (int i = 1; i < M; i++) {
		nest[0][i] += sizeArr[index];
		grow_store[0][i] = sizeArr[index++];
	}
}

void grow(int x, int y) {
	int amount = max({ grow_store[y - 1][x], grow_store[y][x - 1] , grow_store[y - 1][x - 1] });
	nest[y][x] += amount;
	grow_store[y][x] = amount;
}

void manage()
{
	for (int i = 1; i < M; i++)
	{
		for (int j = 1; j < M; j++)
		{
			grow(j, i);
		}
	}
}

int main() {
	cin >> M >> N;

	for (int i = 0; i < M; i++)
		for (int j = 0; j < M; j++)
			nest[i][j] = 1;

	for (int i = 0; i < N; i++) {
		int zero, one, two;
		cin >> zero >> one >> two;
		for (int j = 0; j < one; j++)
			sizeArr[zero + j] += 1;
		for (int j = 0; j < two; j++)
			sizeArr[zero + one + j] += 2;
	}

	growFirst();
	manage();

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M; j++) {
			cout << nest[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}
