#include <iostream>
#include <vector>
using namespace std;

int main(){
    int target = 416;
    int cnt = 0;

    vector<int> coins = {365,91,52,28,13,7,4,1};

    for(int i=0; i<coins.size(); i++){
        while(target - coins[i] >= 0){
            cnt++;
            target = target - coins[i];
        }    
    }

    cout << cnt;
    return 0;
}