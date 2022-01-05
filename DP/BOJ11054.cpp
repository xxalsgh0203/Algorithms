#include <iostream>
#include <algorithm>
using namespace std;

int A[1001], n;
int incdpmap[1001]; // 증가하는 부분수열
int decdpmap[1001]; // 감소하는 부분수열

void dpinc(){ // incdpmap 에 증가하는부분수열의 최대길이 입력

    for(int i=0; i<n; i++){
        incdpmap[i] = 1;
    }

    for(int i=0; i<n; i++){
       for(int j=0; j<i; j++){
           if(A[j] < A[i]){
               incdpmap[i] = max(incdpmap[i], incdpmap[j]+1);
           }
       }
    }
}

void dpdec(){ // decdpmap 에 감소하는 부분수열의 최대길이 입력
    for(int i=0; i<n; i++){
        decdpmap[i] = 1;
    }

    for(int i=n-1; i>=0; i--){
       for(int j=n-1; j>i; j--){
           if(A[j] < A[i]){
               decdpmap[i] = max(decdpmap[i], decdpmap[j]+1);
           }
       }
    }
}

int main(){
    int result = 0;
    cin >> n;
    
    for(int i=0; i<n; i++){ // 수열 정보 입력
        cin >> A[i];
    }

    dpinc();
    dpdec();

    for(int i=0; i<n; i++){ // 바이토닉 부분수열의 최대길이 계산. 
        result = max(result, incdpmap[i] + decdpmap[i]);
    }

    cout << result-1;
    
}