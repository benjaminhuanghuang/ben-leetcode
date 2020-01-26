/*
  1033. Moving Stones Until Consecutive

  https://leetcode.com/problemset/all/?status=Todo
*/

#include <vector>
#include <string>
#include <unordered_set>

#include <algorithm>

using namespace std;

/*
  https://zxi.mytechroad.com/blog/leetcode/leetcode-weekly-contest-134/
  Solution: 
*/

class Solution
{
public:
  vector<int> numMovesStones(int a, int b, int c)
  {
    if (a > c)
      swap(a, c);
    if (a > b)
      swap(a, b);
    if (b > c)
      swap(b, c);
    int u = c - b - 1 + (b - a - 1);
    int l = 0;
    if (a + 1 == b && b + 1 == c)
      l = 0;
    else if (a + 2 >= b || b + 2 >= c)
      l = 1;
    else
      l = 2;
    return {l, u};
  }
};