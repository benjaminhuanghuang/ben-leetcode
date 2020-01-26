/*
1041. Robot Bounded In Circle
https://leetcode.com/problems/robot-bounded-in-circle/
*/
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
  bool isRobotBounded(string instructions)
  {
    int posX = 0, posY = 0;
    int dir = 0;
    vector<vector<int>> delta{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    for (int step = 0; step < 4; step++)
    {
      for (char c : instructions)
      {
        if (c == 'G')
        {
          posX += delta[dir][0];
          posY += delta[dir][1];
        }
        else if (c == 'R')
        {
          dir = (dir + 1) % 4;
        }
        else
        {
          dir = (dir - 1 + 4) % 4;
        }
      }
    }
    return posX == 0 && posY == 0 && dir == 0;
  }
};

int main()
{
  Solution s;

  s.isRobotBounded("GGLLGG");
}