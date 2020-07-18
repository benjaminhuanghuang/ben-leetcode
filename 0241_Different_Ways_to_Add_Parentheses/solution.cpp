/*
241. Different Ways to Add Parentheses

Level: Medium

https://leetcode.com/problems/different-ways-to-add-parentheses
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
  Solution: memorize
  Huahua
  http://zxi.mytechroad.com/blog/leetcode/leetcode-241-different-ways-to-add-parentheses/
*/

class Solution
{
public:
  vector<int> diffWaysToCompute(string input)
  {
    return ways(input);
  }

private:
  unordered_map<char, function<int(int, int)>> operators {
    {'+', [](int a, int b){return a + b;}},
    {'-', [](int a, int b){return a - b;}},
    {'*', [](int a, int b){return a * b;}}
  };

  const vector<int> &ways(const string &input)
  {
    // Already solved, return the answer
    if (m_.count(input))
      return m_[input];

    // Array for answer of input
    vector<int> ans;

    // Break the expression at every operator
    for (int i = 0; i < input.length(); ++i)
    {
      char op = input[i];
      // Split the input by an op
      if (op == '+' || op == '-' || op == '*')
      {
        const string left = input.substr(0, i);
        const string right = input.substr(i + 1);
        // Get the solution of left/right sub-expressions
        const vector<int> &l = ways(left);
        const vector<int> &r = ways(right);

        auto f = operators[op];

        // Combine the solution
        for (int a : l)
          for (int b : r)
            ans.push_back(f(a, b));
      }
    }

    // Single number, e.g. s = "3"
    if (ans.empty())
      ans.push_back(stoi(input));

    // memorize the answer for input
    m_[input]=ans; //m_[input].swap(ans);
    return m_[input];
  }

  unordered_map<string, vector<int>> m_;
};