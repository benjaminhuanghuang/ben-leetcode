/*
453. Minimum Moves to Equal Array Elements

Level: Easy

https://leetcode.com/problems/minimum-moves-to-equal-array-elements
*/
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

#include <limits>
#include <numeric>

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

/*
  Solution: 
*/

class Solution
{
public:
  int minMoves(vector<int> &nums)
  {
    int min = INT_MAX;
    long sum = 0;
    for (int i : nums)
    {
      if (i < min)
        min = i;
      sum += i;
    }
    return (int)(sum - min * nums.size());
  }

  /*
   Same idea as v3
  */
  int minMoves_v2(vector<int> &nums)
  {
    int n = nums.size();
    if (n <= 1)
    {
      return 0;
    }

    long mi = nums[0];
    long sum = 0;
    for (int i = 0; i < n; ++i)
    {
      if (nums[i] < mi)
      {
        mi = nums[i];
      }
      sum += nums[i];
    }

    return sum - mi * n;
  }

  /*
    Assuming the sum of array is S, the minimum element of the array is min and minimum number of moves is m.

    Each move will increase the sum of array by n – 1. Finally, every element becomes x. So we have:

        S + (n – 1) * m = x * n
        min + m = x
        m = S – n * min


    Time complexity: O(n)
    Space complexity: O(1)
  */
  int minMoves_v3(const vector<int>& a) {
    return accumulate(a.begin(), a.end(), 0L) - a.size() * *min_element(a.begin(), a.end());
  }
};