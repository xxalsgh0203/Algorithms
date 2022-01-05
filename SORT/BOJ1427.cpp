#include <iostream>
#include <algorithm>
using namespace std;

int arr[10];

int main(){
    int N, cnt = 0;
    cin >> N;

    while(N!=0){
        arr[cnt] = N % 10;
        cnt++;
        N /= 10;
    }

    sort(arr, arr+10, greater<int>());
    for(int i=0; i<cnt; i++){
        cout << arr[i];
    }
}