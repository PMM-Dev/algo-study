// WA 
// Wrong case : (()[])[] => expected output : 12 / output : 0
// 올바른 형식인지 판단을 위해 도입한 mul 값이, 재귀로 나눠지는 단계간에 원할한
// 전달, 할당, 판단이 안되고 있음. 
#include <iostream>
#include <utility>
#define endl "\n"
using namespace std;

string str;
bool isError = false;

// {sum,idx}
// 1 : nothing, 2 : open by ( , 3 : open by [
pair<int, int> recursion(int idx, int mul) {
	int sum = 0;
	while (idx < (int)str.length()) {
		if (isError) return {0, 0};

		// cout << idx << " : " << str[idx] << " << " << mul << endl;
		if (str[idx] == '(' || str[idx] == '[') {
			int tempMul;
			if (str[idx] == '(')
				tempMul = 2;
			else
				tempMul = 3;

			if ((str[idx] == '(' && str[idx + 1] == ')') ||
					(str[idx] == '[' && str[idx + 1] == ']')) {
				sum += tempMul;
				idx += 2;
			} else {
				mul = tempMul;
				pair<int, int> innerPair = recursion(idx + 1, mul);
				sum += innerPair.first;
				idx = innerPair.second;
			}

			// cout << "opened : " << innerPair.first << " / " << innerPair.second << endl;
		} else {
			// cout << "close : " << str[idx] << " / " << mul << endl;
			//
			if ((str[idx] == ')' && mul != 2) ||
					(str[idx] == ']' && mul != 3)) {
				isError = true;
				return {0, 0};
			}

			sum = sum == 0 ? 1 : sum;
			int calculation = sum * mul;
			mul = 1;
			return {calculation, idx + 1};
		}
	}

	idx++;

	if (mul == 1) {
		return {sum, idx};
	} else {
		isError = true;
		return {0, 0};
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> str;
	cout << recursion(0, 1).first;
	return 0;
}
