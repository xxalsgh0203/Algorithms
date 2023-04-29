#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n;
long long k;
vector<int> a, f;

bool possible(long long x) {
    long long cnt = 0;
    for (int i = 0; i < n; i++) {
        long long c = (long long)a[i] * f[i];
        if (c > x) {
            cnt += (c - x + f[i] - 1) / f[i];
        }
    }
    return cnt <= k;
}

int main() {
    int t;
    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        cin >> n >> k;
        a.resize(n), f.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> f[i];
        }
        sort(a.begin(), a.end());
        sort(f.begin(), f.end(), greater<int>());

        long long l = 0, r = 1e18;
        while (l < r) {
            long long mid = (l + r) / 2;
            if (possible(mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        cout << "#" << tc << " ";
        cout << l << endl;
    }
    return 0;
}
