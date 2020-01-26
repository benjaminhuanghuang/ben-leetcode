/*
    1027. Longest Arithmetic Sequence
    
    https://leetcode.com/problems/longest-arithmetic-sequence/
*/

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

/*
  https://www.youtube.com/watch?v=mSplC7Q-Rm8&feature=youtu.be
  动态规划，dp[diff][idx]表示等差为diff，以系数idx结尾的最长子序列长度。
dp[diff][idx]最初都为0，但凡遍历到的最小则为2。
双重循环，外循环系数i，内循环系数j，每一次我们让j从0走到i-1，通过A[j]与A[i]组成等差数列(diff = A[i] - A[j])，更新dp[diff][i]的值为：max(dp[diff][j] + 1, dp[diff][i])，同时更新返回值res = max(res, dp[diff][i])
最后返回res即可。
*/
class Solution
{
public:
    int longestArithSeqLength(vector<int> &A)
    {
        unordered_map<int, unordered_map<int, int>> dp;
        if (A.size() <= 1)
        {
            return A.size();
        }
        int res = 2;
        for (int i = 0; i < A.size(); ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                int diff = A[i] - A[j];
                if (!dp[diff].count(i))
                {
                    dp[diff][i] = 2;
                }
                dp[diff][i] = max(dp[diff][j] + 1, dp[diff][i]);
                res = max(res, dp[diff][i]);
            }
        }
        return res;
    }
    /*
        https://www.youtube.com/watch?v=QRSDXF8ZrmE&t=577s
    */
    int longestArithSeqLength_huahua(vector<int> &A)
    {
        int n = A.size();
        unordered_set<int> h;
        int ans = 2;
        for (int a : A)
            h.insert(a);
        for (int i = 0; i < n - 1; ++i)
            for (int j = i + 1; j < n; ++j)
            {
                int d = (A[j] - A[i]);
                int t = A[j] + d;
                int l = 2;
                if (!h.count(t))
                    continue;
                int k = j + 1;
                for (int k = j + 1; k < n; ++k)
                    if (A[k] == t)
                    {
                        t += d;
                        ++l;
                    }
                ans = max(ans, l);
            }
        return ans;
    }
};