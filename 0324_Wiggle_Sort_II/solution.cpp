/*
324. Wiggle Sort II

Level: Medium

https://leetcode.com/problems/wiggle-sort-ii
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

  摆动数组满足nums[0] < nums[1] > nums[2] < nums[3]...，
  
  先给数组排序，然后在做调整。调整的方法是找到数组的中间的数，相当于把有序数组从中间分成两部分，
  然后从前半段的末尾取一个，在从后半的末尾去一个，这样保证了第一个数小于第二个数，然后从前半段取倒数第二个，从后半段取倒数第二个，这保证了第二个数大于第三个数，且第三个数小于第四个数，以此类推直至都取完
*/

class Solution
{
public:
  void wiggleSort(vector<int> &nums)
  {
    vector<int> tmp = nums;
    int n = nums.size(), mid = (n + 1) / 2, j = n;
    sort(tmp.begin(), tmp.end());
    for (int i = 0; i < n; ++i)
    {
      nums[i] = i & 1 ? tmp[--j] : tmp[--mid];
    }
  }
};

// O(1) space
class Solution
{
public:
  void wiggleSort(vector<int> &nums)
  {
#define A(i) nums[(1 + 2 * i) % (n | 1)]
    int n = nums.size(), i = 0, j = 0, k = n - 1;
    auto midptr = nums.begin() + n / 2;
    nth_element(nums.begin(), midptr, nums.end());
    int mid = *midptr;
    while (j <= k)
    {
      if (A(j) > mid)
        swap(A(i++), A(j++));
      else if (A(j) < mid)
        swap(A(j), A(k--));
      else
        ++j;
    }
  }
};