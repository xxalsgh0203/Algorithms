#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N;
long A[1000000];
vector <int> v;

void Input(){
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> A[i];
    }
}

void Solve(){
    for(int i=0; i<N; i++){
        if(v.size()==0 || v[v.size()-1] < A[i]){
            v.push_back(A[i]);
        }
        else{
            int x = lower_bound(v.begin(), v.end(), A[i]) - v.begin();
            v[x] = A[i];
        }
    }
    cout << v.size() << endl;
}

int main(){
    Input();
    Solve();

    return 0;
}


