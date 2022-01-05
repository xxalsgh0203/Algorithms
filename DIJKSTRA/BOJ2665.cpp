#include<algorithm>
#include<iostream>
#include<queue>
using namespace std;

const int INF = 987654321;
int n; 
int dx[4] = {-1,0,0,1};
int dy[4] = {0,1,-1,0};

int graph[51][51];
int record[51][51];

void Input()
{
    cin >> n;
    for (int i = 0; i < n; i++) // 입력예시가 띄어쓰기 없는 입력이므로 char 로 입력을받아 int 로 바꿔줘야한다
    {
        string S; cin >> S;
        for (int j = 0; j < S.length(); j++)
        {
            graph[i][j] = S[j] - '0';
        }
    }
}

void setting() {	// 몇번 방을 바꿨는지 기록하는 record 배열을 INF 로 초기화
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			record[i][j] = INF;
		}
	}
}

bool inRange(int nx,int ny){	// 범위를 벗어나지 않았는지 확인
	if(nx>=0 && nx<n && ny>=0 && ny <n)
		return true;
	else
		return false;
}

void dijkstra(){
	priority_queue <pair<int, pair<int, int> > > pq; // <벽뚫은횟수, x좌표, y좌표>
	pq.push(make_pair(0,make_pair(0,0))); // (0,0)에서 시작
	record[0][0] = 0;
	int result;
	while(!pq.empty()){
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		pq.pop();

		for(int i=0; i<4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(graph[nx][ny]==1 && inRange(nx,ny) && record[nx][ny] > record[x][y]){ // 흰방일때
				record[nx][ny] = record[x][y]; // 벽뚫기 안함
				pq.push(make_pair(record[nx][ny],make_pair(nx,ny)));
			}
			else if(graph[nx][ny]==0 && inRange(nx,ny) && record[nx][ny] > record[x][y] + 1){ // 검은방일때
				record[nx][ny] = record[x][y] + 1; // 벽뚫기 + 1
				pq.push(make_pair(record[nx][ny],make_pair(nx,ny)));
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	Input();

	setting();

	dijkstra();

	cout << record[n-1][n-1];

}