#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector <int> v;

const int INF = 987654321;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    v.push_back(-INF);
    int N ,num;
    vector<int>::iterator it;
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> num;
        if(num > v.back()){
            v.push_back(num);
        }
        else{
            it = lower_bound(v.begin(), v.end(), num);
            *it = num;
        }
    }

    cout << v.size() - 1;
    return 0;

}