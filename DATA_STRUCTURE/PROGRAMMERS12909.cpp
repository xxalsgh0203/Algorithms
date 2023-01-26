#include <string>
#include <iostream>
#include <vector>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    char opening_bracket = '(';
    char closing_bracket = ')';

    vector<char> open;

    if (s[0] == closing_bracket)
        return false;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == opening_bracket)
        {
            open.push_back(s[i]);
        }
        else if (s[i] == closing_bracket)
        {
            if (open.back() == opening_bracket)
            {
                open.pop_back();
            }
        }
    }

    if (open.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}