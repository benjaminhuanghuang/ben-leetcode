/*
982. Triples with Bitwise AND Equal To Zero

Level: Hard

https://leetcode.com/problems/triples-with-bitwise-and-equal-to-zero
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
  https://zxi.mytechroad.com/blog/bit/leetcode-982-triples-with-bitwise-and-equal-to-zero/
*/

class Solution
{
public:
  int countTriplets(vector<int> &A)
  {
    const int n = *max_element(begin(A), end(A));
    vector<int> count(n + 1);
    for (int a : A)
      for (int b : A)
        ++count[a & b];
    int ans = 0;
    for (int a : A)
      for (int i = 0; i <= n; ++i)
        if ((a & i) == 0)
          ans += count[i];
    return ans;
  }
};