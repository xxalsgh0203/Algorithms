#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <pair<int, int> > v;

int main(){
    int a,b,N;
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> a >> b;
        v.push_back(make_pair(a, b));
    }
    
    sort(v.begin(), v.end());

    for(int i=0; i<N; i++){
        if(v[i-1].first == v[i].first){
            if(v[i-1].second > v[i].second){
                int temp;
                temp = v[i-1].second;
                v[i-1].second = v[i].second;
                v[i-1].second = temp;
            }
        }
    }

    for(int i=0; i<N; i++){
        cout << v[i].first << " " << v[i].second << '\n';
    }
}