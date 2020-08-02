/*
567. Permutation in String

Level: Medium

https://leetcode.com/problems/permutation-in-string
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
  https://www.youtube.com/watch?v=wpq03MmEHIM

  Solution: 
  Sliding Window

  Time Complexity: O(l1 + l2 * 26) = O(l1 + l2)

  Space Complexity: O(26 * 2) = O(1)
*/

class Solution
{
public:
  bool checkInclusion(string s1, string s2)
  {
    int l1 = s1.length();
    int l2 = s2.length();

    vector<int> counter(26); // counter of chars in s1
    vector<int> window(26);

    for (const char c : s1)
      ++counter[c - 'a'];

    for (int i = 0; i < l2; ++i)
    {
      if (i >= l1)
        --window[s2[i - l1] - 'a'];
        
      ++window[s2[i] - 'a'];
      if (counter == window)
        return true;
    }
    return false;
  }
};