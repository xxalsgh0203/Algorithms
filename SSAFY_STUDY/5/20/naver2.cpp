#include <iostream>
#include <string>
#include <vector>

using namespace std;

int findGroup(string s) {
    int i = 0;
    while (i < s.length()) {
        int asciiCode = s[i];
        if (asciiCode <= 57 && asciiCode >= 48) {
            break;
        } else {
            i++;
        }
    }
    int j = i + 1;
    while (j < s.length()) {
        int asciiCode = s[j];
        if (asciiCode <= 57 && asciiCode >= 48) {
            j++;
        } else {
            break;
        }
    }
    j = j - 1;
    string group = s.substr(i, j - i + 1);
    int groupNumber = stoi(group);
    return groupNumber;
}

int solution(vector<string> &T, vector<string> &R) {
    vector<int> test_group(301, -1);

    int total_test_cases = T.size();
    for (int i = 0; i < total_test_cases; i++) {
        int testcase_group = findGroup(T[i]);
        if (R[i] == "OK" && test_group[testcase_group] != 0) {
            test_group[testcase_group] = 1;
        } else {
            test_group[testcase_group] = 0;
        }
    }

    int scored = 0, total = 0;
    for (int i = 1; i < 301; i++) {
        if (test_group[i] == -1) {
            break;
        }
        total++;
        if (test_group[i] == 1) {
            scored++;
        }
    }
    int result = (scored * 100) / total;
    return result;
}

// https://www.chegg.com/homework-help/questions-and-answers/nathan-completed-first-programming-test-wondering-score-received-email-containing-final-re-q99063957