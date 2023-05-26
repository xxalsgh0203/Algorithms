#include <iostream>
#include <vector>
using namespace std;

int main() {
    int TC;
    cin >> TC;

    for (int testcase = 1; testcase <= TC; testcase++) {
        int N;
        cin >> N;
        vector<pair<int, int>> v;
        for (int i = 0; i < N; i++) {
            int buy_sell, price;
            cin >> buy_sell >> price; // buy 가 1인 경우 팔려고온 경우, -1 인 경우 사러 온 경우
            v.push_back(make_pair(buy_sell, price));
        }

        int today = 0;
        int max_amount = 0;

        while (today != N) {
            int cur_carprice = 0;
            int profit = 0;
            for (int i = today; i < N; i++) {

                if (v[i].first == 1) { // 팔려고 온 경우
                    cur_carprice = v[i].second;
                }

                for (int j = i + 1; j < N; j++) {
                    if (v[j].first == -1 && cur_carprice == v[j].second) {
                        profit += v[j].second;
                        i = j;
                        break;
                    }
                }
            }
            max_amount = max(max_amount, profit);
            today++;
        }

        cout << "#" << testcase << " " << max_amount << '\n';
    }
}

// sample input
