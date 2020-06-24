/*
682. Baseball Game

Level: Easy

https://leetcode.com/problems/baseball-game
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
  int calPoints(vector<string> &ops)
  {
    stack<int> stack;

    for (int i = 0; i < ops.size(); i++)
    {
      string op = ops[i];
      if (op == "C")
      {
        stack.pop();
      }
      else if (op == "+")
      {
        int score1 = stack.top();
        stack.pop();
        // sum of the last two valid round's points
        int sum = score1 + stack.top();
        stack.push(score1);
        stack.push(sum);
      }
      else if (op == "D")
      {
        // score is the doubled data of the last valid round's points.
        stack.push(2 * stack.top());
      }
      else
      {
        stack.push(stoi(op));
      }
    }
    int sum = 0;

    while (!stack.empty())
    {
      sum += stack.top();
      stack.pop();
    }
    return sum;
  }
};