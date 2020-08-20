/*
316. Remove Duplicate Letters

Level: Hard

https://leetcode.com/problems/remove-duplicate-letters
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
  Solution: Monotonic Stacks

  Always make the element in the stack top as small as possible
  Everytime you push the element, if the top element is larger than the current 
  element and the top element can be found in the future, pop it.
*/

class Solution
{
public:
  string removeDuplicateLetters(string s)
  {
    int counter[26] = {0};
    for (int i = 0; i < s.size(); i++)
      counter[s[i] - 'a']++;

    unordered_set<char> uset;
    stack<char> stk;

    for (int i = 0; i < s.size(); i++)
    {
      char c = s[i];
      counter[c - 'a']--;
      if (uset.count(c))
        continue;
      uset.insert(c);
      if (stk.size() == 0)
        stk.push(c);
      else
      {
        //if the top element is larger than the current element and the top element can be found in the future
        while (stk.size() && stk.top() > c && counter[stk.top() - 'a'])
        {
          uset.erase(uset.find(stk.top()));
          stk.pop();
        }
        stk.push(c);
      }
    }

    string ans = "";
    while (stk.size())
    {
      ans = stk.top() + ans;
      stk.pop();
    }
    return ans;
  }
};