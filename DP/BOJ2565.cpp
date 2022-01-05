#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector <pair<int, int> > v;
int dpmap[101] = {0};
int N;

void dp(){
    for(int i=0; i<N; i++){
        for(int j=0; j<i; j++){
            if(v[i].second > v[j].second){
                dpmap[i] = max(dpmap[i], dpmap[j] + 1);
            }
        }
    }
}

int main(){
    cin >> N;
    for(int i=0; i<N; i++){
        int a,b;
        cin >> a >> b;
        v.push_back(make_pair(a, b));
    }

    sort(v.begin(), v.end()); // first 기준으로 정렬

    dp();

    int max = 0;
    int min = 0;

    for(int i=0; i<N; i++){

        if(max < dpmap[i])
            max = dpmap[i];
    }

    cout << N - max - 1;

}