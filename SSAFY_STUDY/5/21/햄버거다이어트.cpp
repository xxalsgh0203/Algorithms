#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int N, L;
int max_points = 0;

vector<pair<int, int>> v;

void Combinations(int index, int totalcal, int totalpoints) {
    if (totalcal > L)
        return;

    if (max_points < totalpoints)
        max_points = totalpoints;

    for (int i = index; i < N; i++) {
        Combinations(i + 1, totalcal + v[i].first, totalpoints + v[i].second);
    }
}

int main() {
    int TC;
    cin >> TC;
    for (int testcase = 1; testcase <= TC; testcase++) {

        cin >> N >> L;
        for (int i = 0; i < N; i++) {
            int points, cal;
            cin >> points >> cal;
            v.push_back(make_pair(cal, points));
        }

        sort(v.begin(), v.end());

        Combinations(0, 0, 0);

        cout << "#" << testcase << " " << max_points << '\n';
        v.clear();
        max_points = 0;
    }
}