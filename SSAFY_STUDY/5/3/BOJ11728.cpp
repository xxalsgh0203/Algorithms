#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    int v1[1000001];
    int v2[1000001];
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> v1[i];
    }

    for (int i = 0; i < M; i++) {
        cin >> v2[i];
    }

    int v1_index = 0;
    int v2_index = 0;

    while (v1_index < N && v2_index < M) {
        if (v1[v1_index] < v2[v2_index]) {
            cout << v1[v1_index] << " ";
            v1_index++;
        } else if (v1[v1_index] > v2[v2_index]) {
            cout << v2[v2_index] << " ";
            v2_index++;
        } else {
            cout << v1[v1_index] << " ";
            v1_index++;
            cout << v2[v2_index] << " ";
            v2_index++;
        }
    }

    while (v1_index < N) {
        cout << v1[v1_index] << " ";
        v1_index++;
    }

    while (v2_index < M) {
        cout << v2[v2_index] << " ";
        v2_index++;
    }

    return 0;
}