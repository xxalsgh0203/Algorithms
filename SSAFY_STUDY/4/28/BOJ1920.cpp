#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int Binary_Search(int number, vector<int> arr) {
    int left = 0;
    int right = arr.size() - 1;
    while (left <= right) {
        int middle = (left + right) / 2;
        if (arr[middle] == number)
            return 1;
        if (arr[middle] > number) {
            right = middle - 1;
        } else if (arr[middle] < number) {
            left = middle + 1;
        }
    }

    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    vector<int> arr;

    for (int i = 0; i < N; i++) {
        int A;
        cin >> A;
        arr.push_back(A);
    }
    sort(arr.begin(), arr.end());
    int cnt;
    cin >> cnt;
    for (int i = 0; i < cnt; i++) {
        int number;
        cin >> number;
        cout << Binary_Search(number, arr) << '\n';
    }
}
