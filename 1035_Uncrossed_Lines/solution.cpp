/*
1035. Uncrossed Lines

https://leetcode.com/problems/uncrossed-lines/
*/
#include <vector>
#include <string>
#include <unordered_set>

#include <algorithm>
using namespace std;
/*
  Solution: 
*/

class Solution {
public:
  int maxUncrossedLines(vector<int>& A, vector<int>& B) {
    const int m = A.size();
    const int n = B.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    dp[0][0] = 0;
    for (int i = 1; i <= m; ++i)
      for (int j = 1; j <= n; ++j) {        
        if (A[i - 1] == B[j - 1]) 
          dp[i][j] = dp[i-1][j-1] + 1;
        else
          dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
      }
    return dp[m][n];
  }
};