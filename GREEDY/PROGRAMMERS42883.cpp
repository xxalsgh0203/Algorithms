#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string number, int k)
{
    string answer = "";
    int answer_size = number.length() - k;

    int max_num = 0;
    int max_index = 0;

    for (int i = 0; i < answer_size; i++)
    {
        max_num = 0;
        for (int j = max_index; j <= k + i; j++)
        {
            if (max_num < number[j] - '0')
            {
                max_num = number[j] - '0';
                max_index = j + 1;
            }
        }
        answer += to_string(max_num);
    }

    return answer;
}

int main()
{
    string number = "4177252841";
    cout << solution(number, 4);
}