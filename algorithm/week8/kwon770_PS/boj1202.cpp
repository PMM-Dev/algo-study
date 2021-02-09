// https://www.acmicpc.net/problem/1202
// 1202 보석 도둑
//
// 그리디 성향의 문제이며 그 과정에서는 이분 탐색을 활용해야 한다.
// 또한 다양한 자료형을 활용해야 풀이가 수월해진다.
//
// 가방 하나에 보석 하나만 들어간다는 조건이 문제를 그리디임을 알 수 있게
// 해준다. 무조건 고가치 보석을 먼저 확인하며, 못들고가는 보석이면 패스하고 그
// 다음 고가치 보석을 확인하는 식이다. 여기서 적절한 가방을 찾는 것에서 한 번
// 막히는데, 가방마저 그리디식으로 풀면 생기는 예외가 바로 보일 것이다. 무조건
// 큰 가방부터 채워넣으면 문제가 발생한다.
//
// 문제에 주어지는 값들의 범위가 매우 크므로, 단순히 완탐으로 가방을 찾으면
// 무조건 TLE이므로 Log(N) 인 이분 탐색, lower_bound를 쓴다. 가방은 mutliset으로
// 관리하는게 편한데 set 계열안에 자체 이분탐색 함수가 있다.
//
// 보석을 담는 방법엔 priority_queue를 통해 넣는 순간부터 정렬하거나, vector에
// 넣고 sort하는 방법이 있다. priority_queue 풀이:
// https://www.acmicpc.net/source/26013912 priority_queue의 insert와 sort 모두
// Nlog(N) 이지만, 큐는 insert가 N 이므로 vector가 방식이 나아 보이며 실제
// 체점도 시간이 약간 더 빠르다.
//
// 조심할 점
// 1. 정렬과 이분탐색에 빠져서 가방을 set에 넣었는데, 가방의 무게는 중복이 있을
// 수 있으므로 multiset 사용
// 2. 변수의 범위가 꽤 크므로, 답은 long long 에 계산
//
#include <algorithm>
#include <iostream>
#include <set>
#include <utility>
#include <vector>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define F first
#define S second

bool cmp(pair<int, int> a, pair<int, int> b) { return a.S > b.S; }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, k;
  cin >> n >> k;
  vector<pair<int, int>> jewelry;
  rep(i, n) {
    int m, v;
    cin >> m >> v;
    jewelry.push_back(make_pair(m, v));
  }
  sort(jewelry.begin(), jewelry.end(), cmp);
  multiset<int> bags;
  rep(i, k) {
    int inp;
    cin >> inp;
    bags.insert(inp);
  }

  long long ans = 0;
  for (auto iter = jewelry.begin(); iter != jewelry.end(); iter++) {
    auto search = bags.lower_bound((*iter).F);
    if (search != bags.end()) {
      bags.erase(search);
      ans += (*iter).S;
    }
  }

  cout << ans;
  return 0;
}
