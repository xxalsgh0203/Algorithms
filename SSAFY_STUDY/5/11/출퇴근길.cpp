#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m, S, T;
vector<int> map[100001];
bool visited[1000001];

vector<int> start_dir;
vector<int> end_dir;

void dfs_s(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    if (start == T) {
        return;
    }

    if (start != S) {
        start_dir.push_back(start);
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < map[cur].size(); i++) {
            int next = map[cur][i];
            if (!visited[next]) {
                dfs_s(next);
            }
        }
    }
}

void dfs_e(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    if (start == S) {
        return;
    }

    if (start != T) {
        end_dir.push_back(start);
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < map[cur].size(); i++) {
            int next = map[cur][i];
            if (!visited[next]) {
                dfs_e(next);
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int start, end;
        cin >> start >> end;
        map[start].push_back(end);
    }
    cin >> S >> T;

    dfs_s(S);

    memset(visited, false, sizeof(visited));

    dfs_e(T);

    int cnt = 0;

    for (int i = 0; i < start_dir.size(); i++) {
        for (int j = 0; j < end_dir.size(); j++) {
            if (start_dir[i] == end_dir[j]) {
                cnt++;
                break;
            }
        }
    }

    cout << cnt;
}