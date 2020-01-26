/*
1019. Next Greater Node In Linked List [Medium]

https://leetcode.com/problems/next-greater-node-in-linked-list/
*/

#include <vector>
#include <stack>
#include <algorithm>

#include "common/ListNode.h"

using namespace std;
/*
Solution: Reverse + Monotonic Stack
https://zxi.mytechroad.com/blog/uncategorized/leetcode-weekly-contest-130/

Time complexity: O(n)
Space complexity: O(n)
*/
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> nums;
    while (head) {
      nums.push_back(head->val);
      head = head->next;      
    }
    stack<int> s;
    vector<int> ans(nums.size());
    for (int i = nums.size() - 1; i >= 0; --i) {
      while (!s.empty() && s.top() <= nums[i]) s.pop();
      ans[i] = s.empty() ? 0 : s.top();
      s.push(nums[i]);
    }
    return ans;
    }
};