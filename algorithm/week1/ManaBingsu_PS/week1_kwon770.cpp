#include <iostream>

using namespace std;

int T, A, B;

int *table[9];
int size_array[9];

int main(){
	int a[] = { 1, -1 };
	int b[] = { 2, 4, 8, 6, -1 };
	int c[] = { 3, 9, 7, 1, -1 };
	int d[] = { 4, 6, -1 };
	int e[] = { 5, -1 };
	int f[] = { 6, -1 };
	int g[] = { 7, 9, 3, 1, -1 };
	int h[] = { 8, 4, 2, 6, -1 };
	int i[] = { 9, 1, -1 };
	table[0] = a;
	table[1] = b;
	table[2] = c;
	table[3] = d;
	table[4] = e;
	table[5] = f;
	table[6] = g;
	table[7] = h;
	table[8] = i;
	for (int i = 0; i < 9; i++){
		int index = 0;
		while (table[i][index++] != -1);
		size_array[i] = index - 1;
	}
	cin >> T;
	for (int i = 0; i < T; i++){
		cin >> A >> B;
		if (A % 10 == 0)
			cout << "10\n";
		else
			cout << table[A % 10 - 1][(B - 1) % size_array[A % 10 - 1]] << "\n";
	}
	return 0;
}
