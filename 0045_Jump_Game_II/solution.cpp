/*
45. Jump Game II

https://leetcode.com/problems/jump-game-ii/

[#55]
*/
#include <vector>

using namespace std;
/*
https://zxi.mytechroad.com/blog/greedy/leetcode-45-jump-game-ii/

Solution: Greedy

Jump as far as possible but lazily.

[2, 3, 1, 1, 4]
i    nums[i]   steps   near   far
-      -         0       0     0
0      2         0       0     2
1      3         1       2     4
2      1         1       2     4
3      1         2       4     4
4      4         2       4     8

Time complexity: O(n)
Space complexity: O(1)
*/
class Solution
{
public:
  int jump(vector<int> &nums)
  {
    int steps = 0;
    int near = 0;
    int far = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
      if (i > near)
      {
        ++steps;
        near = far;
      }
      far = max(far, i + nums[i]);
    }
    return steps;
  }
};
/*
    https://www.youtube.com/watch?v=r3pZd9ghqxk
     */
class Solution
{
public:
  int jump(vector<int> &nums)
  {
    if(nums.size() <=1)
      return 0;
    int steps = 0;
    int currReach = 0; // 当前能跳到的最远位置
    int nextReach = 0; // 下次最远可以跳到的位置
    int i = 0;
    /*
        Take [2,1,3,1,1,1,1] as a sample. at position 0, the value is 2, 
        we can go to position 1 (nextReach is pos 2) OR go to position 2 (nextReach is position 5)
        */
    while (i <= currReach)
    {
      while (i <= currReach)
      {
        nextReach = max(nextReach, i + nums[i]);
        i++;
      }
      currReach = nextReach;
      steps++;
      if (currReach >= nums.size() - 1)
        return steps;
    }
    return steps;
  }
};