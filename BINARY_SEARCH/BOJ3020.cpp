#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, H;
const int INF = 987654321;
vector <int> top;
vector <int> bottom;

void Input(){
    cin >> N >> H;
    for(int i=0; i<N; i++){
        int temp;
        cin >> temp;
        if(i%2 == 0)
            top.push_back(temp);
        else
            bottom.push_back(temp);
    }
}

void Solve(){
    sort(top.begin(), top.end());
    sort(bottom.begin(), bottom.end());

    int result = INF;
    int cnt = 1;

    for(int i=1; i<=H; i++){
        int brk = (top.size() - (lower_bound(top.begin(), top.end(), i) - top.begin()));
        brk += (bottom.size() - (upper_bound(bottom.begin(), bottom.end(), H-i) - bottom.begin())); 

        if(brk < result){
            result = brk;
            cnt = 1;
        }
        else if(brk == result){
            cnt++;
        }       
    }

    cout << result << " " << cnt;
}

int main(){
    Input();
    Solve();
}