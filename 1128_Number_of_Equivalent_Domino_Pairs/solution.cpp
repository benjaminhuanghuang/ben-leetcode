/*
1128. Number of Equivalent Domino Pairs

Level: Easy

https://leetcode.com/problems/number-of-equivalent-domino-pairs
*/
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

/*
  Solution: 
*/

class Solution
{
public:
  int numEquivDominoPairs(vector<vector<int>> &dominoes)
  {
    unordered_map<pair<int, int>, int> dimensions;
    int count = 0;
    for (auto d : dominoes)
    {
      std::pair<int, int> dimension{max(d[1], d[0]), min(d[1], d[0])};
      if (dimensions.count(dimension))
      {
        count += dimensions[dimension];
        dimensions[dimension]++;
      }
      else
      {
        dimensions[dimension] = 1;
      }
    }

    return count;
  }

  int numEquivDominoPairs_v2(vector<vector<int>> &dominoes)
  {
    unordered_map<int, int> m;
    int count = 0;
    for (auto d : dominoes)
    {
      //  1 <= dominoes[i][j] <= 9
      int key = max(d[1], d[0]) * 10 + min(d[1], d[0]);
      count += m[key]++;
    }

    return count;
  }
};