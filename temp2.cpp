#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> A;
vector<int> B;

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        A.push_back(temp);
    }
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        B.push_back(temp);
    }

    sort(A.begin(), A.end(), greater<>());
    sort(B.begin(), B.end());

    int answer = 0;

    for (int i = 0; i < N; i++) {
        answer += A[i] * B[i];
    }

    cout << answer;
}