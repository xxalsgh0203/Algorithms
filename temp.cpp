#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool isValid(int y, int x, int width, int height)
{
  if (y >= 0 && x >= 0 && y < height && x < width)
    return true;
  else
    return false;
}

int solution(vector<vector<int>> maps)
{
  int answer = 0;

  int width = maps[0].size();
  int height = maps.size();

  queue<pair<int, int>> q;
  q.push(make_pair(0, 0));

  while (!q.empty())
  {
    int cur_y = q.front().first;
    int cur_x = q.front().second;
    q.pop();
    maps[0][0] = 2; // 방문처리

    for (int i = 0; i < 4; i++)
    {
      int next_y = cur_y + dy[i];
      int next_x = cur_x + dx[i];

      if (isValid(next_y, next_x, width, height) && maps[next_y][next_x] == 1)
      {
        q.push(make_pair(next_y, next_x));
        maps[next_y][next_x] = maps[cur_y][cur_x] + 1;
      }

      if (next_y == height - 1 && next_x == width - 1)
      {
        answer = maps[next_y][next_x] - 1;
        return answer;
      }
    }
  }

  return -1;
}

int main()
{
  vector<vector<int>> maps = {{1, 0, 1, 1, 1}, {1, 0, 1, 0, 1}, {1, 0, 1, 1, 1}, {1, 1, 1, 0, 1}, {0, 0, 0, 0, 1}};
  cout << solution(maps);
}