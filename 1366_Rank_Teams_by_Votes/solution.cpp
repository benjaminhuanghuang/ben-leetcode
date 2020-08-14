/*
1366. Rank Teams by Votes [Google]

Level: Medium

https://leetcode.com/problems/rank-teams-by-votes
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
  Solution: Sort by rank
*/

class Solution
{
public:
  string rankTeams(vector<string> &votes)
  {
    const int n = votes[0].length();
    string ans(votes[0]);
    // char: {position: votes}
    vector<vector<int>> rank(26, vector<int>(n));

    for (const auto &vote : votes)
      for (int i = 0; i < n; ++i)
        ++rank[vote[i] - 'A'][i];

    sort(begin(ans), end(ans), [&](const char i, const char j) {
      if (rank[i - 'A'] != rank[j - 'A'])
        return rank[i - 'A'] > rank[j - 'A'];
      return i < j;
    });

    return ans;
  }
};