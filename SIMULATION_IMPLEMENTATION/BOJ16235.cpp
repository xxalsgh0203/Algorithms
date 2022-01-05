#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, M, K;
int x, y, z;
int A[12][12];
int land[12][12];
int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
vector <int> tree[12][12];

// 봄에는 나무가 자신의 나이만큼 양분을 먹고 나이가 1 증가. 못먹으면 죽음
// 여름에는 봄에 죽은 나무가 양분으로 변함. 죽은나무의 나이/2 = 양분
// 가을에는 나무가 번식. 나무 나이가 5의 배수여야 번식 가능. 인접한 8개의 칸에 나이가 1인 나무 생성
// 겨울에는 S2D2 가 돌아다니면서 땅에 양분 추가

void Input(){
    cin >> N >> M >> K;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            land[i][j] = 5; // 처음에 양분이 5만큼씩 들어있음
            cin >> A[i][j];
        }
    }
    for(int i=0; i<M; i++){
        cin >> x >> y >> z;
        tree[x][y].push_back(z);
    }
}

void SpringAndSummer(){
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(tree[i][j].size() == 0)  continue;

            sort(tree[i][j].begin(), tree[i][j].end()); // 하나의 칸에 여러 나무가 있으면 나이 어린 나무부터 양분섭취하기 위해
            vector <int> temp;
            int Die_Tree_Energy = 0;

            for(int k=0; k<tree[i][j].size(); k++){
                if(tree[i][j][k] > land[i][j]){ // 양분을 못먹으면
                    Die_Tree_Energy += (tree[i][j][k] / 2);
                }else{
                    land[i][j] -= tree[i][j][k];
                    temp.push_back(tree[i][j][k] + 1);
                }
            }

            tree[i][j].clear();
            for(int k=0; k<temp.size(); k++){
                tree[i][j].push_back(temp[k]);
            }

            land[i][j] += Die_Tree_Energy;
        }
    }
}

void Fall(){
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            for(int k=0; k<tree[i][j].size(); k++){
                if(tree[i][j][k] % 5 == 0){
                    for (int a = 0; a < 8; a++){
                        int nx = i + dx[a];
                        int ny = j + dy[a];
                        if (nx >= 1 && ny >= 1 && nx <= N && ny <= N)
                        {
                            tree[nx][ny].push_back(1);
                        }
                    }
                }
            }
        }
    }
}

void Winter(){
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            land[i][j] += A[i][j];
        }
    }
}

void afterOneYear(){
    SpringAndSummer();
    Fall();
    Winter();
}

int countSurvivedTree(){
    int result = 0;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            result += tree[i][j].size();
        }
    }
    return result;
}

void Solve(){
    for(int i=0; i<K; i++){
        afterOneYear();
    }

    cout << countSurvivedTree();
}

int main(){
    Input();
    Solve();
}