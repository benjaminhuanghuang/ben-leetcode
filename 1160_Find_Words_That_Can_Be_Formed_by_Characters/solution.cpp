/*
1160. Find Words That Can Be Formed by Characters

Level: Easy

https://leetcode.com/problems/find-words-that-can-be-formed-by-characters
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
  Solution: 
*/

class Solution
{
public:
  int countCharacters(vector<string> &words, string chars)
  {
    vector<int> counts(26);
    for (char c : chars)
      ++counts[c - 'a'];
      
    int ans = 0;
    for (const string &word : words)
    {
      vector<int> cur(26);
      bool valid = true;
      for (char c : word)
        if (++cur[c - 'a'] > counts[c - 'a'])
        {
          valid = false;
          break;
        }
      if (valid)
        ans += word.length();
    }
    return ans;
  }
};