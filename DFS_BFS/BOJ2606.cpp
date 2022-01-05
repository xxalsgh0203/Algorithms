#include <stdio.h>
#include <stdlib.h>

int graph[1001][1001] = {0};
int DFSvisit[1001]={0};

void dfs(int first, int length){
	DFSvisit[first] = 1; // 방문처리
	for(int i=1; i<=length; i++){
		if(graph[first][i] == 1 && DFSvisit[i] == 0){
			dfs(i, length);
		}
	}
}

int main(){
	int N, M, i, x, y;
	scanf("%d %d", &N, &M);

	for(i=1; i<=M; i++){
		scanf("%d %d", &x, &y);
		graph[x][y] = 1;
		graph[y][x] = 1;
	}
	
	dfs(1, N);
	
	int count = 0;
	for(i=2; i<=N; i++){
		if(DFSvisit[i] == 1)
			count++;
	}
	
	printf("%d", count); // 1번을 제외하고 감염된 컴퓨터수 
}
