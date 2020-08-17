/*
948. Bag of Tokens

Level: Medium

https://leetcode.com/problems/bag-of-tokens
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
*/

class Solution
{
public:
  int bagOfTokensScore(vector<int> &tokens, int P)
  {
    sort(begin(tokens), end(tokens));
    int points = 0;
    int ans = 0;
    int i = 0;
    int j = tokens.size() - 1;

    while (i <= j)
      if (P >= tokens[i])
      {
        P -= tokens[i++];
        ans = max(ans, ++points);
      }
      else if (points > 0)
      {
        P += tokens[j--];
        --points;
      }
      else
      {
        break;
      }
    return ans;
  }
};