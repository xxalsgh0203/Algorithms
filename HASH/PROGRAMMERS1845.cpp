#include <vector>
#include <set>
using namespace std;

int solution(vector<int> nums)
{
    set<int> pocketmon;
    int answer = 0;
    int size = nums.size() / 2;

    for (int i = 0; i < nums.size(); i++)
    {
        pocketmon.insert(nums[i]);
    }

    for (auto i : pocketmon)
    {
        answer++;
    }

    if (answer > size)
        return size;
    else
        return answer;
}