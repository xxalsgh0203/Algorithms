#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
int arr[1050];
vector<int> result[10];

void BinaryTree(int left, int right, int depth) {
    if (left == right) {
        result[depth].push_back(arr[left]);
        return;
    }
    int middle = (left + right) / 2;
    result[depth].push_back(arr[middle]);
    BinaryTree(left, middle - 1, depth + 1);
    BinaryTree(middle + 1, right, depth + 1);
}

int main() {
    int K;
    cin >> K;
    int num = pow(2, K) - 1;

    for (int i = 0; i < num; i++) {
        cin >> arr[i];
    }

    BinaryTree(0, num - 1, 0);

    for (int i = 0; i < K; i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}