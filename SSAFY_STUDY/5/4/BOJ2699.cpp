#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> school;
vector<int> result[3];
int main() {
    int N;
    cin >> N;
    for (int i = 0; i < 3; i++) {
        int boy, girl;
        cin >> boy >> girl;
        school.push_back(make_pair(boy, girl));
    }

    for (int i = 0; i < school[0].first; i++) {
        int A_Boy_B_Girl = i;
        int A_Boy_C_Girl = school[0].first - A_Boy_B_Girl;
        int B_Boy_A_Girl = N - school[2].first - school[2].second - A_Boy_B_Girl;
        int B_Boy_C_Girl = school[1].first - B_Boy_A_Girl;
        int C_Boy_A_Girl = school[0].second - B_Boy_A_Girl;
        int C_Boy_B_Girl = school[2].first - C_Boy_A_Girl;

        if ((A_Boy_B_Girl >= 0) && (B_Boy_A_Girl >= 0) && (C_Boy_A_Girl >= 0) && (A_Boy_C_Girl >= 0) && (B_Boy_C_Girl >= 0) && (C_Boy_B_Girl >= 0)) {
            cout << "1" << '\n';
            cout << A_Boy_B_Girl << " " << A_Boy_C_Girl << '\n';
            cout << B_Boy_A_Girl << " " << B_Boy_C_Girl << '\n';
            cout << C_Boy_A_Girl << " " << C_Boy_B_Girl;

            return 0;
        }
    }

    cout << "0";

    return 0;
}