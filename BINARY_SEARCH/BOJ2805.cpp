#include <iostream>
#include <vector>
using namespace std;

vector<int> tree;
long long N, M;
       
long long binarySearch(long long left, long long right, long long target){
    long long result;
    while(left <= right){
        long long middle = (left + right) / 2;
        long long div = 0;
        for(int i=0; i<N; i++){
            if(middle > tree[i]){ // 자르려는 나무보다 더 큰 길이만큼 잘라야할때
                div += 0;
            }
            else
            {
                div += tree[i] - middle;
            }
        }
        if(div < target){
            right = middle - 1;
        }
        else{
            result = middle;
            left = middle + 1;
        }
    }

    return result;
}

int main(){
    cin.tie(0);
	ios_base::sync_with_stdio(false);

    cin >> N >> M;
    int maxlen = 0;
    for(int i=0; i<N; i++){
        int temp;
        cin >> temp;
        tree.push_back(temp);
        if(maxlen < temp)
            maxlen = temp;
    }

    cout << binarySearch(1, maxlen, M);
}