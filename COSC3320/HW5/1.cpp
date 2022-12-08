// C++ Code for Palindrome Partitioning
// Problem
#include <iostream>
#include <string.h>
#include <limits.h>
#include <vector>

using namespace std;
 
string str;

int findSmallestPal(){
    int n = str.length();
    vector<vector<int>> Pal(n, vector<int> (n, 0));

    for(int i = 0; i < n; i++){
        Pal[i][i] = 1;
    }

    for(int i = 0; i < n-1; i++){
        if(str[i] == str[i+1]){
            Pal[i][i+1] = 1;
        }
    }

    for(int length = 3; length < n+1; length++){
        for(int i=0; i<n-length+1; i++){
            int j = i + length - 1;
            if(str[i] == str[j] && Pal[i+1][j-1])
                Pal[i][j] = 1;
        }
    }

    vector<int> Splits(n, 0);

    for(int i = 0; i < n; i++){
        int minnum = str.length() - 1;
        if(Pal[0][i]){
            Splits[i] = 0;
        }
        else{
            for(int j = 0; j < i; j++){
                if(Pal[j+1][i] && Splits[j] + 1 < minnum){
                    minnum = Splits[j] + 1;
                }
            }
            Splits[i] = minnum;
        }
    }

    return Splits[n-1] + 1;
}

int main(){
    int size;
    cin >> size;
    cin >> str;

    cout << findSmallestPal();
}