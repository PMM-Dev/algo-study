// 괄호의 값
// https://www.acmicpc.net/problem/2504
// Memory	:	KB
// Time		:	ms

// 못 푼 이유
// 스택을 이용한다는 말을 오해했습니다
// 재귀를 사용하여 함수를 스택처럼 호출할 수 있는 것에서 착안하여
// 변수 또한 이렇게 호출하면 스택 저장을 구현할 수 있지않을까? 라는
// 헛생각에 이틀을 소모하였습니다

#include <iostream>
#include <string>
#include <stack>

using namespace std;

string str;
stack<int> indexes;
int memo[50];
int counter = 0;
int result = 0;

void recursion(int depth) {
	if (depth == str.size()) {
		return;
	}
	recursion(depth + 1);
	if (str[depth] == '(') {
		int index = depth + 1;
		int check = counter;
		int sum = 0;
		while (check >= 0) {
			if (memo[index] != 0) {
				index += 2 + (memo[index]);
			}
			if (str[index] == ')') {
				check--;
			}
			else {
				sum++;
			}
		}
		memo[depth - 1] = str[depth - 1] * sum;
		counter++;
	}
}

int main(){
	cin >> str;
	recursion(0);
	int index = 0;
	while (memo[index] != 0) {
		index++;
	}
	cout << memo[index] << "\n";
	return 0;
}
