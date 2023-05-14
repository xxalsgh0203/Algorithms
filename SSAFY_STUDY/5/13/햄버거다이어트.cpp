#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> burgurs;

int highest_score = 0;
int N, L;

void MakeComb(int index, int totalpoint, int totalcal) {
    if (totalcal >= L)
        return;

    if (totalpoint > highest_score) {
        highest_score = totalpoint;
    }

    if (index == N)
        return;

    for (int i = index; i < N; i++) {
        MakeComb(i + 1, totalpoint + burgurs[i].second, totalcal + burgurs[i].first);
    }
}

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

        MakeComb(0, 0, 0);

        cout << "#" << testcase << " " << highest_score << '\n';
        highest_score = 0;
        burgurs.clear();
    }

    return 0;
}