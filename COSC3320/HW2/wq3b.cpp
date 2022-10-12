#include <iostream>
#include <vector>
using namespace std;

vector<int> coins = {365,91,52,28,13,7,4,1};

int Recursion(int target, int cnt){
    if(target - coins[cnt] == 0)
        return 0;

}

int main(){
    int N;
    cin >> N;

    Resursion(N, 0);

    return 0;
}