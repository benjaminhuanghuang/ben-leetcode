/*
31. Next Permutation

https://leetcode.com/problems/next-permutation/
*/
#include <vector>
#include <algorithm>

using namespace std;
/*
Solution: 
Find the last acceding element x: find nums[i] < nums[i+1]
swap with the smallest number y, y is after x and y is greater than x.
Reverse the elements after x.
Sample:
1 2 7 4 3 1
  ^
1 2 7 4 3 1
        ^
1 3 7 4 2 1
  ^      ^
1 3 1 2 4 7
    ^ ^ ^ ^

Time complexity: O(n)
Space complexity: O(1)
*/

class Solution
{
public:
  void nextPermutation(vector<int> &nums)
  {
    int i = nums.size() - 2;
    // 找到从递减到递增的转折点
    while (i >= 0 && nums[i + 1] <= nums[i])
      --i;

    if (i >= 0)
    {
      int j = nums.size() - 1;
      while (j >= 0 && nums[j] <= nums[i])
        --j;
      swap(nums[i], nums[j]);
    }
    reverse(begin(nums) + i + 1, end(nums));
  }
};