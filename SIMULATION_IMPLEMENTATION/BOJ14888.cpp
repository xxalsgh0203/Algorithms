#include <iostream>
#include <cmath>
using namespace std;
int N;
int A[105];
int op[4];
int max_n = -987654321;
int min_n = 987654321;

void Solve(int result, int cnt){
    if(cnt == N){
        if(result > max_n)
            max_n = result;
        if(result < min_n)
            min_n = result;

        return;
    }

    for(int i=0; i<4; i++){
        if(op[i] > 0){
            op[i]--;
            if(i == 0)
                Solve(result + A[cnt], cnt + 1);
            else if(i == 1)
                Solve(result - A[cnt], cnt + 1);
            else if(i == 2)
                Solve(result * A[cnt], cnt + 1);
            else
                Solve(result / A[cnt], cnt + 1);

            op[i]++;
        }
    }

    return;
}

int main(){
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> A[i];
    }
    for(int i=0; i<4; i++){
        cin >> op[i];
    }

    Solve(A[0], 1);

    cout << max_n << '\n';
    cout << min_n;
}