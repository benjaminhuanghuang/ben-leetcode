/*
150. Evaluate Reverse Polish Notation

Level: Medium

https://leetcode.com/problems/evaluate-reverse-polish-notation
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
  Time complexity: O(n)
  Space complexity: O(n)
*/

class Solution
{
public:
  int evalRPN(vector<string> &tokens)
  {
    stack<int> s;
    for (const string &token : tokens)
    {
      if (isdigit(token.back()))   // check last in the token
      {
        s.push(stoi(token));
      }
      else
      {
        int n2 = s.top();
        s.pop();
        int n1 = s.top();
        s.pop();
        int n = 0;
        switch (token[0])
        {
        case '+':
          n = n1 + n2;
          break;
        case '-':
          n = n1 - n2;
          break;
        case '*':
          n = n1 * n2;
          break;
        case '/':
          n = n1 / n2;
          break;
        }
        s.push(n);
      }
    }
    return s.top();
  }
};