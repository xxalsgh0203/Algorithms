#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#define MAX 1001

using namespace std;

int T; // 테스트케이스
int N, K; // 건물의 개수 N 건설순서 규칙 K
int D; // 건물당 건설시간
int X, Y;   // 건설순서
int W; // 건설해야하는 건물
int construct_time[MAX]; // 건설시간
int inDegree[MAX]; // 진입 차수
vector <int> v[MAX];    // 건설 순서
int result[MAX];    // 결과

void Construct(){
    queue <int> q;
    for(int i=1; i<=N; i++){
        if(inDegree[i] == 0){
            q.push(i);
            result[i] = construct_time[i];
        }
    }
    
    while(!q.empty()){
        int cur = q.front();
        q.pop();

        for(int i=0; i<v[cur].size(); i++){
            int next = v[cur][i];
            result[next] = max(result[next], result[cur] + construct_time[next]);
            inDegree[next]--;

            if(inDegree[next] == 0)
                q.push(next);
        }
    }

    cout << result[W] << '\n';

    memset(construct_time, 0, sizeof(construct_time));
    memset(inDegree, 0, sizeof(inDegree));
    memset(result, 0, sizeof(result));
    for(int i=0; i<=N; i++)
        v[i].clear();
}

int main(){
    cin >> T;

    for(int j=0; j<T; j++){
        cin >> N >> K;
        for(int i=1; i<=N; i++){
            cin >> D;
            construct_time[i] = D;
        }
        
        for(int i=0; i<K; i++){
            cin >> X >> Y;
            v[X].push_back(Y);
            inDegree[Y]++;
        }

        cin >> W;

        Construct();
    }
}