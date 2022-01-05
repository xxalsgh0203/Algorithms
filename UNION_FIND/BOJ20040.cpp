#include <iostream>
#include <queue>
using namespace std;
int n, m;
queue <pair<int, int> >q;
int parent[500001];

void Init(){
    for(int i=0; i<n; i++){
        parent[i] = i;
    }
}

void Input(){
    cin >> n >> m;
    Init();
    int a, b;
    for(int i=0; i<m; i++){
        cin >> a >> b;
        q.push(make_pair(a,b));
    }
}

int FindParent(int dot){
    if(parent[dot] == dot)
        return dot;
    return parent[dot] = FindParent(parent[dot]);
}

void UnionParent(int a, int b){
    a = FindParent(a);
    b = FindParent(b);
    if(a<b)
        parent[b] = a;
    else
        parent[a] = b;
}

void Solve(){

    int cnt = 1;

    for(int i=1; i<=m; i++){
        int dot1 = q.front().first;
        int dot2 = q.front().second;
        q.pop();

        if(FindParent(dot1) == FindParent(dot2)){
            cout << cnt;
            return;
        }
        else{
            cnt++;
            UnionParent(dot1, dot2);
        }
    }

    cout << '0';
}

int main(){
    Input();
    Solve();
}