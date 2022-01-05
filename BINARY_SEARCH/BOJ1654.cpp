#include <iostream>
#include <vector>
using namespace std;

vector<int> len;
long long K, N;

long long binarySearch(long long left, long long  right, long long target){
    long long result;
    while(left<=right){
        long long  sum = 0;
        long long middle = (left + right) / 2;
        for(int i=0; i<K; i++){
            sum += len[i] / middle;
        }
        if(sum < target){
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
    
    cin >> K >> N;
    long long maxlen = 0;
    for(int i=0; i<K; i++){
        int temp;
        cin >> temp;
        if(temp > maxlen)
            maxlen = temp;
        len.push_back(temp);
    }

    cout << binarySearch(1, maxlen, N);
}