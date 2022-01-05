#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int N;
    int numberarray[1000000]; 
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> numberarray[i];
    }

    sort(numberarray, numberarray+N);

    for(int i=0; i<N; i++){
        if(numberarray[i-1]!=numberarray[i])
            cout << numberarray[i] << '\n'; // endl 하면 시간초과
    }

    return 0;
}