#include <iostream>
#include <algorithm>
using namespace std;

int A[1001], n;
int dpmap[1001];

void dp(){
    for(int i=0; i<n; i++){
       for(int j=0; j<i; j++){
           if(A[j] < A[i]){
               dpmap[i] = max(dpmap[i], dpmap[j]+1);
           }
       }
    }
}

int main(){
    int result = 0;
    cin >> n;
    
    for(int i=0; i<n; i++){
        cin >> A[i];
    }

    for(int i=0; i<n; i++){
        dpmap[i] = 1;
    }

    dp();

    for(int i=0; i<n; i++){
        result = max(result, dpmap[i]);
    }

    cout << result;
    
}