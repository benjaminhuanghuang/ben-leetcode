/*
1081. Smallest Subsequence of Distinct Characters

Level: Medium

https://leetcode.com/problems/smallest-subsequence-of-distinct-characters

# 316
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
  https://www.youtube.com/watch?v=uXwmONIABlA

  维护一个stack，底为最小值，顶为最大值, a to z
  如果以前出现过，skip
  如果没出现过，如果比栈顶字符字典序小，并且栈定字符以后还出现过，pop


  https://www.youtube.com/watch?v=4ZSpA68CbR4
*/

class Solution
{
public:
  string smallestSubsequence(string text)
  {
    string str;   // stack

    unordered_map<char, int> Map;

    for (auto ch : text)
    {
      Map[ch]++;
    }

    unordered_set<char> Set; // visited

    for (auto ch : text)
    {
      if(Set.find(ch) != Set.end()){
        // visited
        Map[ch]--;
      }
      else
      {
        while(str.size()> 0 && str.back()> ch && Map[str.back()] >0)
        {
          Set.erase(str.back());
          str.pop_back();

        }
        str.push_back(ch);
        Map[ch] --;
        Set.insert(ch);
      }
    }
    return str;
  }
};