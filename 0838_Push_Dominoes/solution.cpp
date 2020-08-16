/*
838. Push Dominoes

Level: Medium

https://leetcode.com/problems/push-dominoes
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
  string pushDominoes(string dominoes)
  {
    const int n = static_cast<int>(dominoes.size());
    vector<int> L(n, INT_MAX), R(n, INT_MAX);

    for (int i = 0; i < n; ++i)
      if (dominoes[i] == 'L')
      {
        L[i] = 0;
        for (int j = i - 1; j >= 0 && dominoes[j] == '.'; --j)
          L[j] = L[j + 1] + 1;
      }
      else if (dominoes[i] == 'R')
      {
        R[i] = 0;
        for (int j = i + 1; j < n && dominoes[j] == '.'; ++j)
          R[j] = R[j - 1] + 1;
      }

    for (int i = 0; i < n; ++i)
      if (L[i] < R[i])
        dominoes[i] = 'L';
      else if (L[i] > R[i])
        dominoes[i] = 'R';

    return dominoes;
  }
};