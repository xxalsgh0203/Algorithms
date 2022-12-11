// https://leetcode.com/problems/split-a-string-into-the-max-number-of-unique-substrings/

#include <iostream>
#include <set>
using namespace std;

class Solution {
public:
    unordered_set <string> st;
    int answer = 0;

    void DFS(string &s, int idx){
        string temp = "";

        if(st.size() > answer)
            answer = st.size();
        
        if(idx >= s.length())
            return;
        
        for(int i=idx; i<s.length(); i++){
            temp += s[i];

            if(st.find(temp) == st.end()){  // if not found
                st.insert(temp);
                DFS(s, i + 1);
                st.erase(temp);
            }
        }
    }

    int maxUniqueSplit(string s) {
        DFS(s, 0);
        return answer;
    }
};

int main(){
    Solution A;
    string str; 
    cin >> str;
    cout << A.maxUniqueSplit(str);

    return 0;
}