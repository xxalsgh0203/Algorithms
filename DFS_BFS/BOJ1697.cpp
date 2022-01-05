#include <iostream>
#include <queue>
#include <stdio.h>
using namespace std;
#define MAX 100001

int N, K;
bool visited[MAX];
queue<pair<int, int> > q;

int bfs(){
    visited[N] = true;
    int time;

    while(!q.empty()){
        int currentPos = q.front().first;
        int currentTime = q.front().second;
        q.pop();

        if(currentPos == K){
            time = currentTime;
            break;
        } 

        if(currentPos-1>=0 && !visited[currentPos-1]){
            q.push(make_pair(currentPos-1,currentTime+1));
            visited[currentPos-1] = true;
        }
        if(currentPos+1<MAX && !visited[currentPos+1]){
            q.push(make_pair(currentPos+1,currentTime+1));
            visited[currentPos+1] = true;
        }
        if(currentPos*2<MAX && !visited[currentPos*2]){
            q.push(make_pair(currentPos*2,currentTime+1));
            visited[currentPos*2] = true;
        } 
    }

    return time;
}

int main(){
    cin >> N >> K;
    q.push(make_pair(N,0));

    cout << bfs() << endl;

    return 0;
}