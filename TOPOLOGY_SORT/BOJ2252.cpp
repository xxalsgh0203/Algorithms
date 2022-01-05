#include <iostream>
#include <vector>
#include <queue>
#define MAX 100010
using namespace std;
int N, M;
vector <int> students[MAX];
int inDegree[MAX];
int result[MAX];

void Input(){
    cin >> N >> M;
    int student1, student2;
    for(int i=0; i<M; i++){
        cin >> student1 >> student2;
        students[student1].push_back(student2);
        inDegree[student2]++;
    }
}

void topologySort(){
    queue <int> q;
    for(int i=1; i<=N; i++){
        if(inDegree[i] == 0)
            q.push(i);
    }

    while(!q.empty()){
        int cur = q.front();
        q.pop();
        cout << cur << " ";
        for(int i=0; i<students[cur].size(); i++){
            int next = students[cur][i];
            inDegree[next]--;
            if(inDegree[next] == 0)
                q.push(next);
        }
    }
}

int main(){
    Input();
    topologySort();
}