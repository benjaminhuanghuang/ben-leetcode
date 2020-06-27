/*
953. Verifying an Alien Dictionary

Level: Easy

https://leetcode.com/problems/verifying-an-alien-dictionary
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
  https://zxi.mytechroad.com/blog/hashtable/leetcode-953-verifying-an-alien-dictionary/
*/

class Solution
{
public:
  bool isAlienSorted(vector<string> &words, string order)
  {
    vector<char> m(26);
    for (int i = 0; i < 26; ++i)
      m[order[i] - 'a'] = 'a' + i;
      
    for (int i = 0; i < words.size(); ++i)
    {
      for (int j = 0; j < words[i].length(); ++j)
        words[i][j] = m[words[i][j] - 'a'];
      if (i > 0 && words[i] < words[i - 1])
        return false;
    }
    return true;
  }
};