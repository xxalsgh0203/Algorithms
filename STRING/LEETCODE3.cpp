#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

class Solution {
  public:
    int lengthOfLongestSubstring(string s) {
        map<char, bool> substr;
        int result = 0;
        int len = 0;
        for (int i = 0; i < s.length(); i++) {
            for (int j = i; j < s.length(); j++) {
                char temp = s[j];
                if (substr.find(temp) == substr.end()) { // map 에 없을때
                    substr.insert({temp, true});
                    len++;
                    result = max(result, len);
                } else {
                    break;
                }
            }
            len = 0;
            substr.clear();
        }
        return result;
    }
};

int main() {
    Solution A;
    string s = "pwwkew";
    cout << A.lengthOfLongestSubstring(s);
}