#include <iostream>
using namespace std;
const int MAX = 1000001;
int n, m;
int parent[MAX];

void Solve();
void Init();
void unionParent(int a, int b);
int findParent(int node);
void checkParent(int a, int b);

void Solve(){
    
    int calculation, a, b;
    for(int i=0; i<m; i++){
        cin >> calculation >> a >> b;
        if(calculation == 0)
            unionParent(a, b);
        else{
            checkParent(a,b);
        }
    }
}

void Init(){
    for(int i=1; i<=n; i++){
        parent[i] = i;
    }
}

void unionParent(int a, int b){
    int na = findParent(a);
    int nb = findParent(b);
    if(na<nb)
        parent[nb] = na;
    else
        parent[na] = nb;
}

int findParent(int node){
    if(node == parent[node])
        return node;
    return parent[node] = findParent(parent[node]);
}

void checkParent(int a, int b){
    if(findParent(a) == findParent(b))
        cout << "YES" << '\n';
    else
        cout << "NO" << '\n';
}

int main(){
    ios_base::sync_with_stdio(false); 
    cout.tie(NULL); 
    cin.tie(NULL);
    cin >> n >> m;
    
    Init();
    Solve();
}
