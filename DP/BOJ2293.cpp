#include <iostream>
using namespace std;
int n, k;
int dpmap[10001];
int money[101];

void dp(){
    dpmap[0] = 1; // 나 자신의 경우를 1로 채우기 위해서
    for(int i=1; i<=n; i++){
        for(int j=money[i]; j<=k; j++){
            dpmap[j] = dpmap[j] + dpmap[j-money[i]];
        }
    }

    cout << dpmap[k] << endl;
}

int main(){
    cin >> n >> k;
    for(int i=1; i<=n; i++){
        cin >> money[i];
    }

    dp();
}