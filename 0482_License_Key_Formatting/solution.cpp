/*
482. License Key Formatting

Level: Easy

https://leetcode.com/problems/license-key-formatting
*/
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

#include <algorithm>

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

/*
  Input: S = "2-5g-3-J", K = 2

  Output: "2-5G-3J"

  Solution: 
*/

class Solution
{
public:
  string licenseKeyFormatting(string S, int K)
  {
    string ans;
    int groupLen = 0;
    for (int i = S.size() - 1; i >= 0; i--)
    {
      if (S[i] != '-')
      {
        ans += toupper(S[i]);
        groupLen++;
        if (groupLen == K)
        {
          ans += '-';
          groupLen = 0;
        }
      }
    }
    // if string is empty, string.back() cause error
    if(ans.size() && ans.back() == '-')
        return string(ans.rbegin()+1, ans.rend());
    return string(ans.rbegin(), ans.rend());
  }
};