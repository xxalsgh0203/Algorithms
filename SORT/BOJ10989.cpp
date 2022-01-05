#include <iostream>
#include <algorithm>
using namespace std;

int N;

void countingArray(){
    int count[10001] = {0};
    int number;
    for(int i=0; i<N; i++){
        cin >> number;
        int value = number;
        count[value]++; // 개수 세기
    }

    for(int i=1; i<10001; i++){
        for(int j=0; j<count[i]; j++){
            if(count[i] != 0)
                cout << i << '\n';
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    
    countingArray();
    return 0;
}