/*
777. Swap Adjacent in LR String

Level: Medium

https://leetcode.com/problems/swap-adjacent-in-lr-string
*/
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <algorithm>

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

/*
  Solution: 
  把換的方式想成 L 只能往左移，R 只能往右移 (並且碰到 L or R 就不能再移動了)
  
  Idea is that L moves backwards (XL->LX) and R moves forwards (RX->XR) so L is decremented and R is incremented. 
  Parallely at the same position of end string, L will be incremented and R will be decremented. 
  At any point, if the count of L or R becomes -ve then return false.

  Note that L cannot move beyond R and R cannot move beyond L. Like mentioned in the HINT.

  For example:
  "XXXXXLXXXLXXXX"
  "XXLXXXXXXXXLXX"

  When start[i] has 'L' it means, we should have already encountered 'L' in end string somewhere before this. In this example, for the second L which comes before second L in end string. Hence 'L' count becomes -ve and answer is false.

  Similarly, when end[i] has 'R' it means, we should have already encountered 'R' in start string before this. If thats not the case then again 'R' count will become -ve and answer will be false.
*/

class Solution
{
public:
  bool canTransform(string start, string end)
  {
    int L = 0, R = 0;

    for (int i = 0; i < start.size(); i++)
    {
      if (start[i] == 'L')
        L--, R = 0; // Reset count of R to zero because previous 'R' characters cannot move beyond 'L' so reset it to zero.  If end[i] has 'R' character then R becomes -ve and returns false or if there is L then L is incremented;
      else if (start[i] == 'R')
        R++, L = 0; // Reset count of L to zero because previous 'L' characters cannot move beyond 'R' so reset it to zero. If end[i] 'R' then 'R' count is decremented and if there is 'L' then L is incremented;

      if (end[i] == 'L')
        L++;
      else if (end[i] == 'R')
        R--;

      if (L < 0 or R < 0)
        return false;
    }
    if (L > 0 or R > 0)
      return false;
    return true; // If both L and R are zero then return true else return false;
  }
};