// GCJ 2020 Qualification 3
// https://codingcompetitions.withgoogle.com/codejam
// Memory	: 	KB
// Time		: 	ms

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

typedef struct _Human {
    char name;
    int src = 0;
    int dest = 0;
} Human;

int main() {
    int T, index = 0;
    cin >> T;
    while (index++ < T) {
        int memo[1440];     fill(memo, memo + 1440, 0);
        string result = "";
        int N;
        Human humans[2];
        humans[0] = Human();
        humans[0].name = 'C';
        humans[1] = Human();
        humans[1].name = 'J';
        cin >> N;
        for (int i = 0; i < N; i++) {
            int src, dest;
            bool isValid = true;
            cin >> src >> dest;
            for (int j = src; j < dest; ++j) {
                memo[j] += 1;
                if (memo[j] > 2)
                {
                    i = N;
                    result = "IMPOSSIBLE";
                    isValid = false;
                    break;
                }
            }
            if (isValid) {
                for (int j = 0; j < 2; j++) {
                    if (humans[j].src >= dest || humans[j].dest <= src) {
                        result += humans[j].name;
                        humans[j].src = src;
                        humans[j].dest = dest;
                        break;
                    }
                }
            }
        }
        cout << "Case #" << index << ": " << result << "\n";
    }
    return 0;
}