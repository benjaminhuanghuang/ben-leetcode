/*
1331. Rank Transform of an Array

Level: Easy

https://leetcode.com/problems/rank-transform-of-an-array
*/
#include <vector>
#include <string>
#include <set>
#include <unordered_map>

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
  vector<int> arrayRankTransform(vector<int> &arr)
  {
    set<int> numSet(begin(arr), end(arr));  // ordered
    unordered_map<int, int> numRanks;   // number, rank
    int rank = 0;
    for (const int v : numSet)    // num in the set is ordered
      numRanks[v] = ++rank;

    vector<int> ans(arr.size());
    for (int i = 0; i < arr.size(); ++i)
      ans[i] = numRanks[arr[i]];
    return ans;
  }
};