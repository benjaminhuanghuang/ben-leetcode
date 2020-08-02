/*
540. Single Element in a Sorted Array

Level: Medium

https://leetcode.com/problems/single-element-in-a-sorted-array
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
  Solution 1: 

  Time complexity: O(N)

  Space complexity: O(1)

  index of single number is even

  compare nums[i] and nums[i+1] if nums[i] != nums[i+1] returns nums[i], i += 2
  
*/

/*
  Solution: 
    Time complexity: O(logn)

    Space complexity: O(1)
    
    index of single number is even

    Find the first i that nums[i] != nums[i+1 or i-1], returns nums[i]

*/

class Solution
{
public:
  int singleNonDuplicate(vector<int> &nums)
  {
    if (nums.size() == 1)
      return nums[0];
    int l = 0;
    int r = nums.size();
    while (l < r)
    {
      const int i = l + (r - l) / 2;
      // j =  i % 2 == 0 ?  i + 1 : i - 1;
      const int j = i ^ 1;
      if (nums[i] == nums[j]) // 如果相同，说明前面所有的数都是配对好的
        l = i + 1;
      else
        r = i;
    }
    return nums[l];
  }
};