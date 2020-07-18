/*
318. Maximum Product of Word Lengths

Level: Medium

https://leetcode.com/problems/maximum-product-of-word-lengths
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
  Solution:  bitwise

*/

class Solution
{
public:
  int maxProduct(vector<string> &words)
  {
    int count = words.size();
    // 每个word对应一个int
    vector<int> words_bytes(count);

    for (int i = 0; i < count; i++)
    {
      for (auto c : words[i])
      {
        // 
        words_bytes[i] |= 1 << (c - 'a');
      }
    }
    int ans = 0;
    for (int i = 0; i < count; i++)
    {
      for (int j = i + 1; j < count; j++)
      {
        if ((words_bytes[i] & words_bytes[j]) == 0) // two words do not have common letter
        {
          ans = max(ans, (int)(words[i].size() * words[j].size()));
        }
      }
    }
    return ans;
  }
};