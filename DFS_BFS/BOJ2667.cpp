#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, cnt;
int graph[25][25];
vector <int> group;

bool dfs(int x, int y){
    if(x<0 || x>=N || y<0 || y>=N)
        return false;
    if(graph[x][y] == 1){
        cnt++;
        graph[x][y] = 0;
        dfs(x-1,y);
        dfs(x+1,y);
        dfs(x,y-1);
        dfs(x,y+1);
        return true;
    }
    return false;
}
 
int main()
{
    int count = 0;
    cin >> N; 
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            scanf("%1d", &graph[i][j]);
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cnt = 0;
            if(dfs(i,j)){
                count += 1;
                group.push_back(cnt);
            }
        }
    }

    sort(group.begin(), group.end());

    cout << count << endl;
    for(int i=0; i<group.size(); i++){
        cout << group[i] << endl;
    }
}