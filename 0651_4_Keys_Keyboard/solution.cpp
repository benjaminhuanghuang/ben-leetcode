
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

class Solution {
public:
    int maxA(int N) {
        int res = N;
        for (int i = 1; i < N - 2; ++i) {
            res = max(res, maxA(i) * (N - 1 - i));
        }
        return res;
    }
};

class Solution {
public:
    int maxA(int N) {
        vector<int> dp(N + 1, 0);
        for (int i = 0; i <= N; ++i) {
            dp[i] = i;
            for (int j = 1; j < i - 2; ++j) {
                dp[i] = max(dp[i], dp[j] * (i - j - 1));
            }
        }
        return dp[N];
    }
};
