#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int N;
int A[101][101];
int divided_map[101][101];

bool inRange(int y, int x, int d1, int d2) {

    // 1. (x, y), (x+1, y-1), ..., (x+d1, y-d1)
    // 2. (x, y), (x+1, y+1), ..., (x+d2, y+d2)
    // 3. (x+d1, y-d1), (x+d1+1, y-d1+1), ... (x+d1+d2, y-d1+d2)
    // 4. (x+d2, y+d2), (x+d2+1, y+d2-1), ..., (x+d2+d1, y+d2-d1)

    // 1번 조건
    if (y + d1 > N || x - d1 < 1)
        return false;
    // 2번 조건
    if (y + d2 > N || x + d2 > N)
        return false;
    // 3번 조건
    if (y + d1 + d2 > N || x - d1 + d2 < 1 || x - d1 + d2 > N)
        return false;
    // 4번 조건
    if (y + d2 + d1 > N || x + d2 - d1 < 1 || x + d2 - d1 > N)
        return false;

    return true;
}

int Calculate() {
    vector<int> result(6, 0);

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            result[divided_map[i][j]] += A[i][j];
        }
    }

    sort(result.begin() + 1, result.end());

    int min_num = result[5] - result[1];

    return min_num;
}

void Label(int y, int x, int d1, int d2) {
    // 5번 선거구의 4 꼭지점
    pair<int, int> main_point = make_pair(y, x);                 // 메인
    pair<int, int> point1 = make_pair(y + d1, x - d1);           // 왼쪽
    pair<int, int> point2 = make_pair(y + d2, x + d2);           // 오른쪽
    pair<int, int> point3 = make_pair(y + d1 + d2, x - d1 + d2); // 아래

    // 5번 선거구 라벨 -> 전체 맵을 5로 해놓은 뒤 1,2,3,4 번을 라벨링한다. 그럼 5를 따로 라벨링할필요 x
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            divided_map[i][j] = 5;
        }
    }
    // 1번 선거구 라벨
    int subArea = 0;
    for (int i = 1; i < point1.first; i++) {
        if (i >= main_point.first)
            subArea++;

        for (int j = 1; j <= main_point.second - subArea; j++) {
            divided_map[i][j] = 1;
        }
    }

    // 2번 선거구 라벨
    int plusArea = 0;
    for (int i = 1; i <= point2.first; i++) {
        if (i > main_point.first)
            plusArea++;

        for (int j = main_point.second + 1 + plusArea; j <= N; j++) {
            divided_map[i][j] = 2;
        }
    }
    // 3번 선거구 라벨
    subArea = 0;
    for (int i = N; i >= point1.first; i--) {
        if (i < point3.first)
            subArea++;

        for (int j = 0; j < point3.second - subArea; j++) {
            divided_map[i][j] = 3;
        }
    }

    // 4번 선거구 라벨
    plusArea = 0;
    for (int i = N; i > point2.first; i--) {
        if (i <= point3.first)
            plusArea++;

        for (int j = point3.second + plusArea; j <= N; j++) {
            divided_map[i][j] = 4;
        }
    }
}

int Divide() {
    int result = 987654321;
    // 완전탐색으로 조합
    for (int y = 1; y <= N - 2; y++) {
        for (int x = 1; x <= N - 1; x++) {
            for (int d1 = 1; d1 <= x - 1; d1++) {
                for (int d2 = 1; d2 <= N - x; d2++) {
                    if (inRange(y, x, d1, d2)) {
                        Label(y, x, d1, d2);
                        int temp_result = Calculate();
                        result = min(result, temp_result);
                    }
                }
            }
        }
    }

    return result;
}

void Input() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> A[i][j];
        }
    }
}

void Debugg(int y, int x, int d1, int d2) {
    Label(y, x, d1, d2);
    cout << '\n';
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cout << divided_map[i][j] << " ";
        }
        cout << '\n';
    }
}

void Solve() {
    Input();
    int result = Divide();

    cout << result;
}

int main() {
    Solve();
    return 0;
}