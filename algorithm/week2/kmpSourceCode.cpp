#include <iostream>
#include <vector>

#define endl "\n";
using namespace std;

vector<int> getPartialMatchBruteForce(string& search) {
    int m = search.size();
    vector<int> pi(m, 0);

    // 탐색 문자열의 처음부터 끝까지 모두 비교해 보면서 접두, 접미사의 길이를 계산한다
    for (int begin = 1; begin < m; begin++) {
        for (int i = 0; begin + i < m; i++) {
            if (search[begin + i] != begin[i]) break;
            pi[begin + i] = max(pi[begin + i], i + 1);
        }
    }

    return pi;
}

//

vector<int> getPartialMatch(string& search) {
    int m = search.size();
    vector<int> pi(m, 0);

    int begin = 1, matched = 0;

    while (begin + matched < m) {
        // 탐색 문자열과 탐색 문자열 자신을 매칭시킴!
        if (search[begin + matched] == search[matched]) {
            matched++;
            pi[begin + matched - 1] = matched;  // 매칭을 진행하면서, 접두 접미사 배열을 바로 갱신
        } else {
            if (matched == 0)
                begin++;
            else {
                // KMP 문자열 탐색 알고리즘 과 동일하게 불일치 발생 시
                // 매칭을 진행하면서 구했던 접두 접미사 길이 만큼 탐색을 건너뛸 수 있다
                begin += matched - pi[matched - 1];
                matched = pi[matched - 1];
            }
        }
    }

    return pi;
}

//

vector<int> kmpSearch(string& src, string& search) {
    int n = src.size(), m = search.size();
    vector<int> ret;
    // 탐색할 문자열의 접두사, 접미사 길이를 문자열의 처음부터 끝 까지 미리 계산
    vector<int> pi = getPartialMatch(search);
    int begin = 0, matched = 0;

    while (begin <= n - m) {
        // 탐색할 문자열과 원본 문자열에서 현재 위치의 문자가 동일한 경우
        if (matched < m && src[begin + matched] == search[matched]) {
            ++matched;

            // 문자열이 모두 일치하는 경우
            if (matched == m)
                ret.push_back(begin);
        } else {
            // 일치하는 부분이 없는 경우, 다음 위치의 문자 부터 탐색
            if (matched == 0)
                ++begin;

            // 문자열이 불일치 하므로 접두사, 접미사 의 길이 만큼 건너 뜀!
            else {
                // 현재 불일치가 발생한 위치는 begin + matched
                // 여기서 접두, 접미사의 길이인 pi[matched - 1] 을 빼주면 다음 탐색 시작 위치
                begin += matched - pi[matched - 1];
                matched = pi[matched - 1];
            }
        }
    }

    return ret;
}

// aabaabcd
// abc