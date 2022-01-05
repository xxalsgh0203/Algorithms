#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int A, B, C, V, E;
vector <pair<int, pair<int, int> > > tree;
int parent[10001];

void Input(){
    cin >> V >> E;
    int vertex1, vertex2, cost;
    for(int i=0; i<E; i++){
        cin >> vertex1 >> vertex2 >> cost;
        tree.push_back(make_pair(cost, make_pair(vertex1, vertex2)));
    }
    sort(tree.begin(), tree.end());
}

void Init(){
    for(int i=1; i<=V; i++){
        parent[i] = i;
    }
}

int findParent(int x){
    if(parent[x] == x)
        return x;
    else
        return parent[x] = findParent(parent[x]);
}

bool sameParent(int x, int y){
    if(findParent(x) == findParent(y))
        return true;
    else
        return false;
}

void Union(int x, int y){
    x = findParent(x);
    y = findParent(y);

    if(x<y)
        parent[y] = x;
    else
        parent[x] = y;
}

void Solve(){
    Init();
    int result = 0;

    for(int i=0; i<E; i++){
        int vtx1 = tree[i].second.first;
        int vtx2 = tree[i].second.second;
        int cost = tree[i].first;
        if(findParent(vtx1) != findParent(vtx2)){   // 연결되어 있지 않으면
            Union(vtx1, vtx2);
            result += cost;
        }
    }

    cout << result;
}

int main(){
    Input();
    Solve();
}