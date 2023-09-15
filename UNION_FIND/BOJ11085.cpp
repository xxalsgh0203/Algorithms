#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int N, M;
int parent[100002];
vector<pair<int, pair<int, int>>> edges;
vector<int> mst;

void Debugg() {
    for (int i = 1; i <= N; i++) {
        cout << parent[i] << " ";
    }
    cout << '\n';
}

int findParent(int node) {
    if (parent[node] == node)
        return node;

    return parent[node] = findParent(parent[node]);
}

void Union(int node1, int node2) {
    int node1_parent = findParent(node1);
    int node2_parent = findParent(node2);

    if (node1_parent < node2_parent) {
        parent[node2_parent] = node1_parent;
    } else {
        parent[node1_parent] = node2_parent;
    }
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int node1, node2, distance;
        cin >> node1 >> node2 >> distance;
        edges.push_back(make_pair(distance, make_pair(node1, node2)));
    }

    sort(edges.begin(), edges.end());

    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < edges.size(); i++) {
        int node1 = edges[i].second.first;
        int node2 = edges[i].second.second;

        if (findParent(node1) != findParent(node2)) {
            Union(node1, node2);
            mst.push_back(edges[i].first);

            Debugg();
        }
    }

    int result = 0;
    for (int i = 0; i < mst.size() - 1; i++) {
        result += mst[i];
    }

    cout << result;
}