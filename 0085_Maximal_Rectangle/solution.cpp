/*
85. Maximal Rectangle

https://leetcode.com/problems/maximal-rectangle/
*/
#include <vector>
#include <stack>

using namespace std;

/*
https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-85-maximal-rectangle/
Solution: DP

Time complexity: O(m^2*n)
Space complexity: O(mn)

dp[i][j] := max length of all 1 sequence ends with col j, at the i-th row.
transition:
dp[i][j] = 0 if matrix[i][j] == ‘0’
= dp[i][j-1] + 1 if matrix[i][j] == ‘1’ 
*/

class Solution {
public:
  int maximalRectangle(vector<vector<char> > &matrix) {
    int r = matrix.size();
    if (r == 0) return 0;
    int c = matrix[0].size();
  
    // dp[i][j] := max len of all 1s ends with col j at row i.
    vector<vector<int>> dp(r, vector<int>(c));
 
    for (int i = 0; i < r; ++i)
      for (int j = 0; j < c; ++j)
        dp[i][j] = (matrix[i][j] == '1') ? (j == 0 ? 1 : dp[i][j - 1] + 1) : 0;
 
    int ans = 0;
 
    for (int i = 0; i < r; ++i)
      for (int j = 0; j < c; ++j) {
        int len = INT_MAX;
        for (int k = i; k < r; k++) {
          len = min(len, dp[k][j]);
          if (len == 0) break;
          ans = max(len * (k - i + 1), ans);
        }
    }
 
    return ans;
  }
};