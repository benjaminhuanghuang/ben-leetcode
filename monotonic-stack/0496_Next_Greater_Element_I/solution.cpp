/*
496. Next Greater Element I

Level: Easy

https://leetcode.com/problems/next-greater-element-i
*/
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

#include <algorithm>
#include <stack>

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

/*
  Solution: 
*/

class Solution
{
public:
  /*
    Stack + HashTable (same as v1)
  
    Using a stack to store the nums whose next greater isn’t found yet.
  
    栈stack维护nums的递减子集，记nums的当前元素为n，栈顶元素为top

    重复弹出栈顶，直到stack为空，或者top大于n为止

    将所有被弹出元素的next greater element置为n

    时间复杂度O(n + m) 其中n为nums1的长度，m为nums2的长度

    http://bookshadow.com/weblog/2017/02/05/leetcode-next-greater-element-i/

    https://zxi.mytechroad.com/blog/algorithms/array/leetcode-496-next-greater-element-i/
  */
  vector<int> nextGreaterElement(vector<int> &findNums, vector<int> &nums)
  {
    stack<int> s;
    unordered_map<int, int> next;
    for (int num : nums)
    {
      while (!s.empty() && num > s.top())
      {
        next[s.top()] = num;
        s.pop();
      }
      s.push(num);
    }

    vector<int> ans;
    for (int num : findNums)
      ans.push_back(next.count(num) ? next[num] : -1);
    return ans;
  }
  /*
    时间复杂度O(n * m) 其中n为nums1的长度，m为nums2的长度
  */
  vector<int> nextGreaterElement_BruteForce(vector<int> &nums1, vector<int> &nums2)
  {
    vector<int> ans;
    for (int num : nums1)
    {
      ans.push_back(-1);
      int index = std::find(nums2.begin(), nums2.end(), num) - nums2.begin();
      for (int i = index; i < nums2.size(); ++i)
        if (nums2[i] > num)
        {
          ans.back() = nums2[i];
          break;
        }
    }
    return ans;
  }
};