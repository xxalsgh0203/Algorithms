// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(string &S) {
    // Implement your solution here
    int max_cnt = 0;
    int cnt = 1;

    for (int i = 1; i < S.length(); i++) {
        if (S[i] != S[i - 1]) {
            max_cnt = max(max_cnt, cnt);
            cnt = 1;
        } else {
            cnt++;
        }
    }

    max_cnt = max(max_cnt, cnt);

    cnt = 1;
    int res = 0;

    for (int i = 1; i < S.length(); i++) {
        if (S[i] != S[i - 1]) {
            res = res + max_cnt - cnt;
            cnt = 1;
        } else {
            cnt++;
        }
    }
    res = res + max_cnt - cnt;
    return res;
}
