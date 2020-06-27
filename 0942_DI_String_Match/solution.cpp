/*
942. DI String Match

Level: Easy

https://leetcode.com/problems/di-string-match
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

https://zxi.mytechroad.com/blog/greedy/leetcode-942-di-string-match/

Solution: Greedy

“I” -> use the smallest possible number

“D” -> use the largest possible number

Time complexity: O(n)

Space complexity: O(n)
*/

class Solution
{
public:
  vector<int> diStringMatch(string S)
  {
    const int n = S.length();
    vector<int> ans;
    int lo = 0;
    int hi = n;
    for (char c : S)
    {
      if (c == 'I')
        ans.push_back(lo++);
      else
        ans.push_back(hi--);
    }
    ans.push_back(lo);
    return ans;
  }
};