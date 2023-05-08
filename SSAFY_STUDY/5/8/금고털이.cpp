#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> jewl;
int result;

int main() {
    int W, N;
    cin >> W >> N;
    for (int i = 0; i < N; i++) {
        int weight, value;
        cin >> weight >> value;
        jewl.push_back(make_pair(value, weight));
    }

    sort(jewl.begin(), jewl.end(), greater<>());

    for (int i = 0; i < jewl.size(); i++) {
        int min_weight = min(W, jewl[i].second);
        result += (min_weight * jewl[i].first);
        W -= min_weight;

        if (W == 0)
            break;
    }

    cout << result;

    return 0;
}