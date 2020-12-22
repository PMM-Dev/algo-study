#include <iostream>
#include <vector>
#include <utility>
#define endl "\n"
using namespace std;

int n, m, size;
int maxSecurity = -1;
vector<vector<int> > lab(9, vector<int>(9, -1));

pair<int, int> getCoor(int idx) {
	return make_pair(idx / m == 0 ? idx / m - 1 : idx / m, idx % m == 0 ? m : idx % m - 1 );
}

int findEmpty(int idx) {
	while (idx <= size) {
		idx++;
		pair<int, int> coor = getCoor(idx);
		if (lab[coor.first][coor.second] == 0) break; 
	}
	return idx;
}

void simulate() {
	int spread = -1;
	while (spread == 0) {
		spread = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (lab[i][j] == 2) {
					if (lab[i + 1][j] == 0) {
						lab[i + 1][j] = 2;
						spread++;
					}
					if (lab[i - 1][j] == 0) {
						lab[i - 1][j] = 2;
						spread++;
					}
					if (lab[i][j + 1] == 0){
						lab[i][j + 1] = 2;
						spread++;
					}
					if (lab[i][j - 1] == 0){
						lab[i][j - 1] = 2;
						spread++;
					}
				}
			}
		}
	}


	// check security
	int security = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (lab[i][j] == 0) {
				security++;
			}
		}
	}	
	maxSecurity = max(maxSecurity, security);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> lab[i][j];
		}
	}

	int first, second, third = 0;
	int size = n * m;
	while (true) {
		first = findEmpty(first);	
		if (first > size - 2) break;

		pair<int, int> firstCoor = getCoor(first);
		lab[firstCoor.first][firstCoor.second] = 1;

		while (true) {
			second = findEmpty(second);
			if (second > size - 1) break;

			pair<int, int> secondCoor = getCoor(second);
			lab[secondCoor.first][secondCoor.second] = 1;


			lab[secondCoor.first][secondCoor.second] = 1;
			while (true) {
				third = findEmpty(third);
				if (third > size) break;

				pair<int, int> thirdCoor = getCoor(third);

				simulate();

				lab[thirdCoor.first][thirdCoor.second] = 0;
			}

			lab[secondCoor.first][secondCoor.second] = 0;
		}

		lab[firstCoor.first][firstCoor.second] = 0;
	}

	cout << maxSecurity << endl;
	return 0;
}
