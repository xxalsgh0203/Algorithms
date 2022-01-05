#include <iostream>

using namespace std;
int dpmap[1001][1001];

int main(){
    int N, K;
    cin >> N >> K;

    for(int i=1; i<=N; i++){
        for(int j=0; j<=i; j++){
            if(i==j || j==0)
                dpmap[i][j] = 1;
            else
            {
                dpmap[i][j] = (dpmap[i-1][j] + dpmap[i-1][j-1]) % 10007;
            }
            
        }
    }

    cout << dpmap[N][K];
    
    return 0;
}
