#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int N, M;
    int result = 80;
    cin >> N >> M;
    
    char** board = new char*[N]; // 보드 동적할당
    for(int i=0; i<N; i++){
        board[i] = new char[M];
    }

    for(int i=0; i<N; i++){ // 보드 색깔입력
        for(int j=0; j<M; j++){
            cin >> board[i][j];
        }
    }

    for(int i=0; i<N-7; i++){ 
        for(int j=0; j<M-7; j++){
            int cntW = 0;
            int cntB = 0;
            for(int a=i; a<i+8; a++){
                    for(int b=j; b<j+8; b++){
                        if((a+b)%2==0 && board[a][b] == 'W')
                            cntB++;
                        if((a+b)%2==1 && board[a][b] == 'B')
                            cntB++;
                        if((a+b)%2==0 && board[a][b] == 'B')
                            cntW++;
                        if((a+b)%2==1 && board[a][b] == 'W')
                            cntW++;
                    }
            }
            result = min(result, min(cntW, cntB));
        }
    }
    cout << result << endl;
    return 0;
}