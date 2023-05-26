#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> burgurs;

int highest_score = 0;
int N, L;

int main() {
    int TC;
    cin >> TC;
    for (int testcase = 1; testcase <= TC; testcase++) {

        cin >> N >> L;
        for (int i = 0; i < N; i++) {
            int point, cal;
            cin >> point >> cal;
            burgurs.push_back(make_pair(cal, point));
        }

        sort(burgurs.begin(), burgurs.end());

        for (int i = 0; i < N; i++) {
        }
    }

    return 0;
}