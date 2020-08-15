/*
820. Short Encoding of Words

Level: Medium

https://leetcode.com/problems/short-encoding-of-words
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
  Remove all the words that are suffix of other words.
*/

class Solution
{
public:
  int minimumLengthEncoding(vector<string> &words)
  {
    unordered_set<string> s(words.begin(), words.end());
    for (const string &w : words)
    {
      for (int i = w.length() - 1; i > 0; --i)
        s.erase(w.substr(i));
    }
    int ans = 0;
    for (const string &w : s)
      ans += w.length() + 1;
    return ans;
  }
};