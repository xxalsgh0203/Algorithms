#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int N, M;
    int temp = 1;

    int arr1[101];
    int arr2[101];
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        int len, limit;
        cin >> len >> limit;
        for (int j = temp; j <= temp + len; j++) {
            arr1[j] = limit;
        }
        temp = temp + len;
    }

    int result = 0;
    int temp2 = 1;

    for (int i = 0; i < M; i++) {
        int len, speed;
        cin >> len >> speed;
        for (int j = temp2; j <= temp2 + len; j++) {
            arr2[j] = speed;
        }
        temp2 = temp2 + len;
    }

    for (int i = 1; i <= 100; i++) {
        result = max(result, arr2[i] - arr1[i]);
    }

    cout << result;
}