#include <string>
#include <iostream>

using namespace std;

// 최초 원점을 기준으로 오른쪽 문자 중 하나의 index 를 x 라고 하고, 그 다음 'A' 가 아닌 문자의 index 를 y 라고 할때

// 1. 원점을 기준으로 x까지 탐색하고 다시 역방향으로 y 를 탐색했을때 이동거리
// 2. 원점을 기준으로 역방향으로 y까지 탐색하고 다시 정방향으로 x를 탐색했을때 이동거리

int solution(string name)
{
    int alphaMove[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int answer = 0;

    int len = name.length();
    int min_dist = len * 2;

    for (int x = 0; x < len; x++)
    {
        answer += alphaMove[name[x] - 'A'];

        int y = x + 1;
        while (y < len && name[y] == 'A')
        {
            y++;
        }
        min_dist = min(min_dist, min(2 * x + (len - y), 2 * (len - y) + x));
    }

    answer += min_dist;

    return answer;
}

int main()
{
    string name = "JAN";
    cout << solution(name);
}

// JJJJAAJKLAKAJ

// len = 13
// x = 3
// y = 6