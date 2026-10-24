/*
763. Partition Labels

Level: Medium

https://leetcode.com/problems/partition-labels
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
  Solution: Brute Force

    Time complexity: O(n^2)

    Space complexity: O(1)
*/

class Solution_BruteForce
{
public:
  vector<int> partitionLabels(string S)
  {
    vector<int> ans;
    size_t start = 0;
    size_t end = 0;

    for (size_t i = 0; i < S.size(); ++i)
    {
      end = max(end, S.find_last_of(S[i]));
      if (i == end)
      {
        ans.push_back(end - start + 1);
        start = end + 1;
      }
    }
    return ans;
  }
};
/*
  Solution 1: Greedy

    Time complexity: O(n)

    Space complexity: O(26/128)
*/

class Solution {
public:
    vector<int> partitionLabels(string S) {
      vector<int> last_index(128, 0);
      for (int i = 0; i < S.size(); ++i)
        last_index[S[i]] = i;
        
      vector<int> ans;
      int start = 0;
      int end = 0;
      for (int i = 0; i < S.size(); ++i) {
        end = max(end, last_index[S[i]]);
        if (i == end) {
          ans.push_back(end - start + 1);
          start = end + 1;
        }
      }
      return ans;
    }
};