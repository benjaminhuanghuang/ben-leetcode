/*
96. Unique Binary Search Trees
https://leetcode.com/problems/unique-binary-search-trees/
 */

/*
    https://www.youtube.com/watch?v=HWJEMKWzy-Q
    1 to n , every number x can be the root of the tree
    left sub tree can have x - 1 nodes, right sub tree can have n - x nodes

     */

#include <vector>
using namespace std;

class Solution
{
public:
  int numTrees(int n)
  {
    vector<int>dp (n + 1);
    dp[0] = 1;                   // array is []
    dp[1] = 1;                   // array has 1 element
    for (int i = 2; i <= n; i++) // total nodes moves
    {
      for (int j = 0; j < i; j++) // j =  node of left sub tree
      {
        //i - j - 1 is the nodes of right sub tree
        dp[i] += dp[j] * dp[i - j - 1];
      }
    }

    return dp[n];
  }
};