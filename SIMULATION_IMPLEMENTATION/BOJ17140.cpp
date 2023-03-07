#include <algorithm>
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
int A[101][101];
int r, c, k;
int cnt = 0;
int Hang = 3, Yul = 3;

void R();
void C();

// 가로 : 행 , 세로 : 열

// 한 행 또는 열에 있는 수를 정렬하려면, 각각의 수가 몇 번 나왔는지 알아야 한다.
// 그 다음, 수의 등장 횟수가 커지는 순으로, 그러한 것이 여러가지면 수가 커지는 순으로 정렬한다.
// 다음에는 배열 A에 정렬된 결과를 다시 넣어야 한다. 정렬된 결과를 배열에 넣을 때는,
// 수와 등장 횟수를 모두 넣으며, 순서는 수가 먼저이다.

void Debugg(string function) {

    cout << '\n';
    cout << function << " 연산 적용 : ";
    cout << '\n';

    cout << '\n';
    for (int i = 0; i < Yul; i++) {
        cout << '*';
    }
    cout << '\n';
    for (int i = 1; i <= Hang; i++) {
        for (int j = 1; j <= Yul; j++) {
            cout << A[i][j] << " ";
        }
        cout << '\n';
    }
    for (int i = 0; i < Yul; i++) {
        cout << '*';
    }
    cout << '\n';
}

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second < b.second;
}

// R 연산: 배열 A의 모든 행에 대해서 정렬을 수행한다. 행의 개수 ≥ 열의 개수인 경우에 적용된다.
void R() {

    if (A[r][c] == k) {
        return;
    }

    cnt++;

    if (cnt > 100)
        return;

    int numberCount[101];
    vector<pair<int, int>> result;

    // 배열 A 의 모든 행에 대해서 정렬을 수행...
    for (int i = 1; i <= Hang; i++) {
        // A[i][j] 에 있는 숫자들 카운트해서 numberCount 에 저장

        memset(numberCount, 0, sizeof(numberCount));

        for (int j = 1; j <= Yul; j++) {
            numberCount[A[i][j]]++;
        }

        // 정렬하기 위해 0 이 아닌 숫자들을 result 에 몇번 나왔는지 정보와 함께 저장
        for (int j = 1; j < 101; j++) {
            if (numberCount[j] == 0) // 한번도 나오지 않은 숫자는 저장하지 않음
                continue;
            result.push_back(make_pair(j, numberCount[j])); // 한번 이상 나온 숫자들 저장
        }

        sort(result.begin(), result.end(), cmp); // 정렬

        for (int j = 1; j <= Yul; j++) { // 0 으로 싹 초기화 시켜준후
            A[i][j] = 0;
        }

        // A 최신화
        int index = 1;
        for (int j = 0; j < result.size(); j++) {
            A[i][index] = result[j].first;
            index++;
            A[i][index] = result[j].second;
            index++;
        }

        // 열 개수 최댓값 최신화
        if (result.size() * 2 > Yul) {
            Yul = result.size() * 2;
        }

        result.clear();
    }

    // Debugg("R");

    if (Hang >= Yul) {
        R();
    } else {
        C();
    }
}

// C 연산: 배열 A의 모든 열에 대해서 정렬을 수행한다. 행의 개수 < 열의 개수인 경우에 적용된다.
void C() {

    if (A[r][c] == k) {
        return;
    }

    cnt++;

    if (cnt > 100)
        return;

    // 배열 A 의 모든 열에 대해서 정렬을 수행...
    int numberCount[101];
    vector<pair<int, int>> result;

    // 배열 A 의 모든 행에 대해서 정렬을 수행...
    for (int i = 1; i <= Yul; i++) {
        // A[i][j] 에 있는 숫자들 카운트해서 numberCount 에 저장

        memset(numberCount, 0, sizeof(numberCount));

        for (int j = 1; j <= Hang; j++) {
            numberCount[A[j][i]]++;
        }

        // 정렬하기 위해 0 이 아닌 숫자들을 result 에 몇번 나왔는지 정보와 함께 저장
        for (int j = 1; j < 101; j++) {
            if (numberCount[j] == 0) // 한번도 나오지 않은 숫자는 저장하지 않음
                continue;
            result.push_back(make_pair(j, numberCount[j])); // 한번 이상 나온 숫자들 저장
        }

        sort(result.begin(), result.end(), cmp); // 정렬

        for (int j = 1; j <= Yul; j++) { // 0 으로 싹 초기화 시켜준후
            A[j][i] = 0;
        }

        // A 최신화
        int index = 1;
        for (int j = 0; j < result.size(); j++) {
            A[index][i] = result[j].first;
            index++;
            A[index][i] = result[j].second;
            index++;
        }

        // 열 개수 최댓값 최신화
        if (result.size() * 2 > Hang) {
            Hang = result.size() * 2;
        }

        result.clear();
    }

    // Debugg("C");

    if (Hang >= Yul) {
        R();
    } else {
        C();
    }
}

void Calculate() {

    if (A[r][c] == k) {
        return;
    }

    R();
}

void Input() {
    cin >> r >> c >> k;
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            cin >> A[i][j];
        }
    }
}

void Solve() {
    Input();
    Calculate();

    if (cnt > 100) {
        cout << "-1";
        return;
    } else {
        cout << cnt;
    }
}

int main() {
    Solve();
    return 0;
}