#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N;
vector <long long> v;
vector <long long> cpy;


int main(){
    cin >> N;
    for(int i=0; i<N; i++){
        int temp;
        cin >> temp;
        v.push_back(temp);
        cpy.push_back(temp);
    }

    sort(cpy.begin(), cpy.end()); // 정렬
    cpy.erase(unique(cpy.begin(), cpy.end()), cpy.end());

    for(int i=0; i<N; i++){
        cout << lower_bound(cpy.begin(), cpy.end(), v[i]) - cpy.begin() << " ";
    }

    return 0;
}