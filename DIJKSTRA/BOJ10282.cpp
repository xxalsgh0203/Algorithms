#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
const int INF = 987654321;
int t, n, d, c; // t: number of test cases, n: number of computer, d: num of paths, c: hacked computer #num
vector <pair<int,int> > computers[10001];
void Solve(int start){
    priority_queue <pair<int, int> > pq;
    pq.push(make_pair(0, start));
    vector <int> infect(n+1, INF);
    infect[start] = 0;
    int cnt = 0, maxtime = 0;
    while(!pq.empty()){
        int curNode = pq.top().second;
        int curTime = -pq.top().first;
        pq.pop();
        
        if(infect[curNode] < curTime)
            continue;
        for(int i=0; i<computers[curNode].size(); i++){
            int nextNode = computers[curNode][i].first;
            int totalTime = curTime + computers[curNode][i].second;
            if(infect[nextNode] > totalTime){
                infect[nextNode] = totalTime;
                pq.push(make_pair(-totalTime, nextNode));
            }
        }

    }

    for(int i=1; i<=n; i++){
        if(infect[i]!=INF){
            cnt++;
            maxtime = max(maxtime, infect[i]);
        }
    }
    cout << cnt << " " << maxtime << '\n';
    memset(computers, 0 ,sizeof(computers));
}
void Input(){
    cin >> t;
    for(int i=0; i<t; i++){
        cin >> n >> d >> c;
        for(int j=0; j<d; j++){
            int computer1, computer2, time;
            cin >> computer1 >> computer2 >> time;
            computers[computer2].push_back(make_pair(computer1, time));
        }
        Solve(c);
    }
}
int main(){
    Input();
}