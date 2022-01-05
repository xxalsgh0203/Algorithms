#include <iostream>
using namespace std;

int N, M;
const int INF = 10000;
int map[503][503];
char tetromino[19][4][5] = {
    {
        "1111",
        "0000",
        "0000",
        "0000",
    },
    {
        "1000",
        "1000",
        "1000",
        "1000",
    },
    {
        "1100",
        "1100",
        "0000",
        "0000",
    },
    {
        "1000",
        "1000",
        "1100",
        "0000",
    },
        {
        "1110",
        "1000",
        "0000",
        "0000",
    },
    {
        "1100",
        "0100",
        "0100",
        "0000",
    },
    {
        "0010",
        "1110",
        "0000",
        "0000",
    },
    {
        "0100",
        "0100",
        "1100",
        "0000",
    },
    {
        "1000",
        "1110",
        "0000",
        "0000",
    },
    {
        "1100",
        "1000",
        "1000",
        "0000",
    },
    {
        "1110",
        "0010",
        "0000",
        "0000",
    },
    {
        "1000",
        "1100",
        "0100",
        "0000",
    },
    {
        "0110",
        "1100",
        "0000",
        "0000",
    },
        {
        "0100",
        "1100",
        "1000",
        "0000",
    },
    {
        "1100",
        "0110",
        "0000",
        "0000",
    },
    {
        "1110",
        "0100",
        "0000",
        "0000",
    },
    {
        "0100",
        "1100",
        "0100",
        "0000",
    },
    {
        "0100",
        "1110",
        "0000",
        "0000",
    },
        {
        "1000",
        "1100",
        "1000",
        "0000",
    }
};

void Input(){
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> map[i][j];
        }
    }
}

void Init(){    // 범위 넘어가는 부분 최솟값으로 만들어두기
    for(int i=N; i<N+3; i++){
        for(int j=0; j<M+3; j++){
            map[i][j] = -INF;
        }
    }

    for(int i=0; i<N+3; i++){
        for(int j=M; j<M+3; j++){
            map[i][j] = -INF;
        }
    }
}

int countBlocks(int x, int y, int block){
    int ret = 0;
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            ret += (tetromino[block][i][j] - '0') * map[x+i][y+j];
        }
    }
    return ret;
}

void Solve(){
    Init();

    int cnt = 0;

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            for(int k=0; k<19; k++){
                int result = countBlocks(i, j, k);
                if(cnt < result)
                    cnt = result;
            }
        }
    }

    cout << cnt;
}

int main(){
    Input();
    Solve();
}