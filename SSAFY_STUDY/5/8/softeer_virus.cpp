#include <iostream>
using namespace std;

int main() {
    int N;
    long long K, P;
    cin >> K >> P >> N;

    for (int time = 0; time < N; time++) {
        K = (K * P) % 1000000007;
    }

    cout << K;

    return 0;
}