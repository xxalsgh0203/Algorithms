#include <cmath>
#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int result = pow(2, N);
    result = pow(result + 1, 2);

    cout << result;

    // 점의 개수 : 4 9 25 81
    // 상자의 개수 : 1 4 16 64
    // 2 3 5 9 의 제곱
    // 1 2 4 8 의 제곱
}