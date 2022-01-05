#include <iostream>
#include <vector>

using namespace std;

vector <pair <int, int> > dpmap(41);

void dp(){
    dpmap[0] = make_pair(1,0);
    dpmap[1] = make_pair(0,1);
    for(int i=2; i<=40; i++){
        dpmap[i] = make_pair(dpmap[i-1].first + dpmap[i-2].first, dpmap[i-1].second + dpmap[i-2].second);
    }
}

int main(){
    int T;
    cin >> T;
    int N;

    dp();

    for(int i=0; i<T; i++){
        cin >> N;
        cout << dpmap[N].first << " " << dpmap[N].second << '\n';
    }

    return 0;
}