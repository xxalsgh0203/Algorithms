// https://leetcode.com/problems/palindromic-substrings/description/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        int countSubstrings(string str) {
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

            int result = 0;
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    result += Pal[i][j];
                }
            }

            return result;
        }
};

int main(){
    Solution A;
    string s = "aaa";
    cout << A.countSubstrings(s);
}