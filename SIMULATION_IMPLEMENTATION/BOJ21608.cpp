#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

int N;
int map[22][22];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, -1, 0, 1};
vector<vector<int>> students(441);

void Init() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            map[i][j] = 0;
        }
    }
}

bool inRange(int y, int x) {
    if (x >= 1 && y >= 1 && x <= N && y <= N)
        return true;

    return false;
}

pair<int, int> findStudent(int student) {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (map[i][j] == student) {
                return make_pair(i, j);
            }
        }
    }

    return make_pair(-1, -1);
}

vector<pair<int, int>> CheckFirstCond(int student) {
    int temp_map[22][22];
    int maxnum = 0;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            temp_map[i][j] = 0;
        }
    }

    vector<pair<int, int>> result;

    for (int i = 0; i < 4; i++) {
        int y = findStudent(students[student][i]).first;
        int x = findStudent(students[student][i]).second;
        if (x != -1 && y != -1) {         // 좋아하는 학생이 자리에 있으면
            for (int j = 0; j < 4; j++) { // 인접칸 서치
                int next_y = y + dy[j];
                int next_x = x + dx[j];
                if (inRange(next_y, next_x) && !map[next_y][next_x]) {
                    temp_map[next_y][next_x]++;
                    maxnum = max(maxnum, temp_map[next_y][next_x]);
                }
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (temp_map[i][j] == maxnum && !map[i][j]) {
                result.push_back(make_pair(i, j));
            }
        }
    }

    return result;
}

vector<pair<int, int>> CheckSecondCond(vector<pair<int, int>> firstCond) {
    int empty_seats[firstCond.size() + 1];
    int maxnum = 0;
    vector<pair<int, int>> result;

    for (int i = 0; i < firstCond.size(); i++) {
        int y = firstCond[i].first;
        int x = firstCond[i].second;
        int available_seats = 0;
        for (int j = 0; j < 4; j++) {
            int next_y = y + dy[j];
            int next_x = x + dx[j];
            if (inRange(next_y, next_x) && !map[next_y][next_x]) {
                available_seats++;
            }
        }
        empty_seats[i] = available_seats;
        maxnum = max(maxnum, empty_seats[i]);
    }

    for (int i = 0; i < firstCond.size(); i++) {
        if (empty_seats[i] == maxnum && !map[firstCond[i].first][firstCond[i].second]) {
            result.push_back(make_pair(firstCond[i].first, firstCond[i].second));
        }
    }

    return result;
}

pair<int, int> CheckThirdCond(vector<pair<int, int>> secondCond) {
    sort(secondCond.begin(), secondCond.end());

    if (secondCond.size() == 1) {
        int y = secondCond.front().first;
        int x = secondCond.front().second;

        return make_pair(y, x);
    }

    for (int i = 0; i < secondCond.size(); i++) {
        int y = secondCond[i].first;
        int x = secondCond[i].second;
        if (!map[y][x])
            return make_pair(y, x);
    }

    return make_pair(0, 0);
}

void Sit(int student) {
    int y, x;
    vector<pair<int, int>> firstCond = CheckFirstCond(student);
    if (firstCond.size() == 1) {
        y = firstCond.front().first;
        x = firstCond.front().second;
        map[y][x] = student; // 학생 자리배치
    } else {
        vector<pair<int, int>> secondCond = CheckSecondCond(firstCond);
        if (secondCond.size() == 1) {
            y = secondCond.front().first;
            x = secondCond.front().second;
            map[y][x] = student; // 학생 자리배치
        } else {
            pair<int, int> thirdCond = CheckThirdCond(secondCond);
            y = thirdCond.first;
            x = thirdCond.second;
            map[y][x] = student; // 학생 자리배치
        }
    }
}

int Calculate() {
    int result = 0;
    int points[5] = {0, 1, 10, 100, 1000};
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int cnt = 0;

            for (int k = 0; k < 4; k++) {
                int next_y = i + dy[k];
                int next_x = j + dx[k];
                if (inRange(next_y, next_x)) {
                    for (int s = 0; s < 4; s++) {
                        if (map[next_y][next_x] == students[map[i][j]][s])
                            cnt++;
                    }
                }
            }

            result += points[cnt];
        }
    }

    return result;
}

void Input_Solve() {
    cin >> N;
    Init();
    int student_no, prefered_student1, prefered_student2, prefered_student3, prefered_student4;
    for (int i = 0; i < N * N; i++) {
        cin >> student_no >> prefered_student1 >> prefered_student2 >> prefered_student3 >> prefered_student4;
        students[student_no].push_back(prefered_student1);
        students[student_no].push_back(prefered_student2);
        students[student_no].push_back(prefered_student3);
        students[student_no].push_back(prefered_student4);
        Sit(student_no);
    }
}

int main() {
    Input_Solve();
    cout << Calculate();
    return 0;
}