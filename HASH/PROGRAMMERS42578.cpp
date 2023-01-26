#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes)
{
    map<string, int> cloth_combination;

    for (int i = 0; i < clothes.size(); i++)
    {
        cloth_combination[clothes[i][1]]++;
    }

    int answer = 1;

    for (const auto c : cloth_combination)
    {
        answer *= (c.second + 1);
    }
    return answer - 1;
}