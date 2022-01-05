#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int N, M;
int order[101][1001];
vector <int> v[1001];
int inDegree[1001];

void Input(){
    int singer;
    cin >> N >> M;
    for(int i=0; i<M; i++){
        cin >> singer;
        for(int j=0; j<singer; j++){
            cin >> order[i][j];
        }
    }

    for(int i=0; i<M; i++){
        for(int j=1; j<sizeof(order[i])/sizeof(int); j++){
            v[order[i][j-1]].push_back(order[i][j]);
            inDegree[order[i][j]]++;
        }
    }
}

void Solve(){
    queue <int> q;
    vector <int> answer;

    for(int i=1; i<=N; i++){
        if(inDegree[i] == 0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        answer.push_back(cur);

        for(int i=0; i<v[cur].size(); i++){
            int next = v[cur][i];
            inDegree[next]--;

            if(inDegree[next] == 0)
                q.push(next);
        }
    }

    if(answer.size() != N){
        cout << 0;
        return;
    }
    else{
        for(int i=0; i<answer.size(); i++){
            cout << answer[i] << '\n';
        }
    }
}

int main(){
    Input();
    Solve();
}