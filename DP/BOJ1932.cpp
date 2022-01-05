#include <iostream>
#include <algorithm> // max
using namespace std;

int n; // n: 계단의 개수
int triangle[500][500] = {0};

void dp(){
    for(int i=1; i<n; i++){
        for(int j=0; j<=i; j++){
            if(j==0)
                triangle[i][j] = triangle[i-1][0] + triangle[i][j];
            else if(j==i)
                triangle[i][j] = triangle[i-1][j-1] + triangle[i][j];
            else
            {
                triangle[i][j] = max(triangle[i-1][j] + triangle[i][j], triangle[i-1][j-1] + triangle[i][j]);
            }
        }
    }
    int max = 0;
    for(int i=0; i<=n; i++){
        if(triangle[n-1][i] > max)
            max = triangle[n-1][i];
    }

    cout << max;
}

int main(){
    cin >> n;
    int arraysize = 1;
    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
            cin >> triangle[i][j];
        }
    }

    dp();

    return 0;
}