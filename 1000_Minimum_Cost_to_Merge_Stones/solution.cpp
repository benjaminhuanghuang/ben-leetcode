/*
1000. Minimum Cost to Merge Stones

https://leetcode.com/problems/minimum-cost-to-merge-stones/
*/

#include <vector>
#include <string>
#include <unordered_set>

#include <algorithm>

using namespace std;


/*
https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-1000-minimum-cost-to-merge-stones/

https://xingxingpark.com/Leetcode-1000-Minimum-Cost-to-Merge-Stones/
动态规划：
dp[i][j][k] := 将i到j合并成k堆的最小cost
初始状态：
dp[i][j][k] = 0 if i==j and k == 1 else inf
最终返回：
dp[0][n-1][1]

[#312]
  Solution: 
*/

class Solution {
public:
    int mergeStones(vector<int>& stones, int K) {
         const int n = stones.size();
        if ((n - K) % (K - 1))
            return -1;
        // calculate the sum from 0 to i        
        vector<int> sumStones(n + 1, 0);
        for (auto i = 0; i < n; ++i) {
            sumStones[i + 1] = sumStones[i] + stones[i]; 
        }
        // initialize the 3d vector dp
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(K + 1, 1e9)));
        for (int i = 0; i < n; ++i) {
            dp[i][i][1] = 0;
        }
        // compute the transition functions
        for (auto stepLen = 2; stepLen <= n; ++stepLen) {
            for (auto i = 0; i <= n - stepLen; ++i) {
                int j = i + stepLen - 1;
                for (auto k = 2; k <= K; k++) {
                    for ( auto m = i; m < j; m += K - 1) {
                        dp[i][j][k] = min(dp[i][j][k], dp[i][m][1] + dp[m + 1][j][k - 1]);
                    }
                }
                dp[i][j][1] = dp[i][j][K] + sumStones[j + 1] - sumStones[i];
            }
        }
        return dp[0][n - 1][1];
    }
};