/*
657. Robot Return to Origin
https://leetcode.com/problems/robot-return-to-origin/
*/

#include <string>

using namespace std;

class Solution
{
public:
  bool judgeCircle(string moves)
  {
    int vertical = 0;
    int horizontal = 0;
    for (char ch : moves)
    {
      if (ch == 'L')
      {
        horizontal--;
      }
      else if (ch == 'R')
      {
        horizontal++;
      }
      else if (ch == 'U')
      {
        vertical++;
      }
      else
      {
        vertical--;
      }
    }
    return vertical == 0 && horizontal == 0;
  }
};