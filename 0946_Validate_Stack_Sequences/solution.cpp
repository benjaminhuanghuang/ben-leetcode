/*
946. Validate Stack Sequences

Level: Medium

https://leetcode.com/problems/validate-stack-sequences
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
  Simulate the push/pop operation.

    Push element from |pushed sequence| onto stack s one by one and pop when 
    top of the stack s is equal the current element in the |popped sequence|.

    Time complexity: O(n)

    Space complexity: O(n)
*/

class Solution
{
public:
  bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
  {
    stack<int> s;
    auto it = begin(popped);
    for (int e : pushed)
    {
      s.push(e);
      while (!s.empty() && s.top() == *it)
      {
        s.pop();
        ++it;
      }
    }
    return it == end(popped);  // reach the end
  }
};