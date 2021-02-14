// º¸¼® µµµÏ
// https://www.acmicpc.net/problem/1202
// Memory	:			KB
// Time		:			ms

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

typedef pair<int, int> pi;

int main()
{
	vector<pi> jewelries;
	vector<int> packs;
	vector<int> jewelryPacks;

	int N, K, firstInput, secondInput;
	cin >> N >> K;
	while (N--) {
		cin >> firstInput >> secondInput;
		jewelries.push_back(make_pair(firstInput, secondInput));
	}
	while (K--) {
		cin >> firstInput;
		packs.push_back(firstInput);
	}

	sort(jewelries.begin(), jewelries.end(), greater<>());
	sort(packs.begin(), packs.end(), greater<>());
	auto jewelriesIt = jewelries.begin();
	auto packsIt = packs.begin();
	while (jewelriesIt != jewelries.end() && packsIt != packs.end()) {
		if ((*jewelriesIt).first <= *packsIt) {
			jewelryPacks.push_back((*jewelriesIt++).second);
			packsIt++;
		}
		else {
			jewelriesIt++;
		}
	}

	sort(jewelryPacks.begin(), jewelryPacks.end(), greater<>());
	auto jewelryPacksIt = jewelryPacks.begin();
	while (jewelriesIt != jewelries.end() && jewelryPacksIt != jewelryPacks.end()) {
		if ((*jewelriesIt).second > *jewelryPacksIt) {
			(*jewelryPacksIt++) = (*jewelriesIt++).second;
		}
		else {
			jewelryPacksIt++;
		}
	}

	jewelryPacksIt = jewelryPacks.begin();
	int result = 0;
	while (jewelryPacksIt != jewelryPacks.end())
		result += (*jewelryPacksIt++);
	cout << result << "\n";
	return 0;
}
