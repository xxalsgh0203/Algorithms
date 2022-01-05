#include <iostream>
#include <queue>
#include <vector>
#define MAX 32002
using namespace std;
int N, M;
int A, B;
vector <int> book[MAX];
int inDegree[MAX];
int result[MAX];

void Input(){
    cin >> N >> M;
    for(int i=0; i<M; i++){
        cin >> A >> B;
        book[A].push_back(B);
        inDegree[B]++;
    }
}

void topologySort(){
    priority_queue <int> q;
    for(int i=1; i<=N; i++){
        if(inDegree[i] == 0)
            q.push(-i);
    }

    while(!q.empty()){
        int cur = -q.top();
        q.pop();

        cout << cur << " ";

        for(int i=0; i<book[cur].size(); i++){
            int next = book[cur][i];
            inDegree[next]--;

            if(inDegree[next] == 0){
                q.push(-next);
            }
        }
    }
}

int main(){
    Input();
    topologySort();
}
