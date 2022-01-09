#include <string>
#include <vector>
using namespace std;

bool visited[201];

void dfs(vector<vector<int>> &computers, int start){
    if(!visited[start]){
        visited[start] = true;
    }

    for(int i=0; i<computers[start].size(); i++){
        if(!visited[i] && computers[start][i]==1){
            visited[i] = true;
            dfs(computers, i);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for(int i=0; i<n; i++){
        if(!visited[i]){
            dfs(computers, i);
            answer++;
        }
    }
    return answer;
}
