#include <iostream>
#include <algorithm>
using namespace std;
string A, B;
int dpmap[1001][1001];

void Input(){
    cin >> A >> B;
}

void getAnswer(int lengthofA, int lengthofB){
    cout << dpmap[lengthofA][lengthofB];
}

void dp(string a, string b){
    for(int i=1; i<=a.length(); i++){
        for(int j=1; j<=b.length(); j++){
            if(a[i-1] == b[j-1]){ // if has same alph
                dpmap[i][j] = dpmap[i-1][j-1] + 1;
            }
            else
                dpmap[i][j] = max(dpmap[i-1][j], dpmap[i][j-1]);
        }
    }
}

int main(){
    Input();
    dp(A, B);
    int A_size= A.length();
    int B_size = B.length();
    getAnswer(A_size, B_size);
}
