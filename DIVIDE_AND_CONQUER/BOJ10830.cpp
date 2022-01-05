#include <iostream>
using namespace std;
int N;

long long int** multiple(long long int **array1, long long int**array2){
    long long int **result = new long long int*[N]; // 배열은 함수로 넘기면 포인터 붕괴가 일어나서 등가포인터로 받아야 하기때문에 동적할당으로 해결하였다
    for(int i=0; i<N; i++){
        result[i] = new long long int[N];
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            result[i][j] = 0;
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            for(int k=0; k<N; k++){
                result[i][j] += array1[i][k] * array2[k][j];
                result[i][j] %= 1000;
            }
        }
    }
    return result;
}

long long int** pow(long long int **array1, long long int times){
    if(times==1)
        return array1;
    if(times%2>0)
        return multiple(pow(array1, times-1),array1);

    long long int** makehalf = pow(array1, times/2);
    return multiple(makehalf,makehalf);
}

int main() {
    long long int B;
    cin >> N >> B;

    long long int **block = new long long int*[N]; // 배열은 함수로 넘기면 포인터 붕괴가 일어나서 등가포인터로 받아야 하기때문에 동적할당으로 해결하였다
    for(int i=0; i<N; i++){
        block[i] = new long long int[N];
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> block[i][j];
        }
    }

    long long int **final = new long long int*[N];
    for(int i=0; i<N; i++){
        final[i] = new long long int[N];
    }

    final = pow(block, B);

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout << final[i][j] % 1000 << " ";
        }
        cout << '\n';
    }

    return 0;
}