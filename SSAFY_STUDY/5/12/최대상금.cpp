#include <algorithm>
#include <cstring>
#include <iostream>
#include <math.h>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;
int ans;
bool check[1000000][11];
int num = 1;
int change;

void sol(string s, int cnt) {
    if (cnt == 0) {
        int temp = stoi(s);
        ans = max(ans, temp);
        return;
    }

    for (int i = 0; i < s.length() - 1; i++) {
        for (int j = i + 1; j < s.length(); j++) {
            swap(s[i], s[j]);
            int Temp = stoi(s);
            if (check[Temp][cnt - 1] == false) {
                check[Temp][cnt - 1] = true;
                sol(s, cnt - 1);
            }
            swap(s[i], s[j]);
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string st;
        cin >> st;

        cin >> change;

        sol(st, change);

        cout << '#' << num << ' ' << ans << '\n';
        ans = 0;
        memset(check, false, sizeof(check));
        num++;
    }
    return 0;
}
