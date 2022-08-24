#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        string answer = "";

        sort(strs.begin(), strs.end());

        string tmp1 = strs[0];
        string tmp2 = strs[strs.size() - 1];

        for(int i=0; i<tmp1.length(); i++){
            if(tmp1[i] == tmp2[i])
                answer += tmp1[i];
            else
                break;
        }

        return answer;
    }
};

int main(){
    Solution A;
    vector<string> strs;
    strs.push_back("flower");
    strs.push_back("flow");
    strs.push_back("flight");
    cout << A.longestCommonPrefix(strs);
}