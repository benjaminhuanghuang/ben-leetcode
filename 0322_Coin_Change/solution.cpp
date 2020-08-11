/*
322. Coin Change

Level: Medium

https://leetcode.com/problems/coin-change
*/
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

#include <algorithm>

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;


/*
  https://www.cnblogs.com/grandyang/p/5138186.html

  一维动态数组dp[i] 表示钱数为i时的最小硬币数的找零，
  注意由于数组是从0开始的，所以要多申请一位，数组大小为 amount+1，这样最终结果就可以保存在 dp[amount] 中了。
  初始化 dp[0] = 0，因为目标值若为0时，需要0枚硬币。
  其他值可以初始化是 amount+1，为啥呢？因为最小的硬币是1，所以 amount 最多需要 amount 个硬币，amount+1 也就相当于当前的最大值了，
  注意这里不能用整型最大值来初始化，因为在后面的状态转移方程有加1的操作，有可能会溢出，除非你先减个1，这样还不如直接用 amount+1。


  假设我取了一个值为5的硬币，那么由于目标值是 11，所以是不是假如我们知道 dp[6]，那么dp[11]=dp[6]+1
  所以更新 dp[i] 的方法就是遍历每个硬币，如果遍历到的硬币值小于i值（比如不能用值为5的硬币去更新 dp[3]）时，
  用 dp[i - coins[j]] + 1 来更新 dp[i]，所以状态转移方程为：
      dp[i] = min(dp[i], dp[i - coins[j]] + 1);
  其中 coins[j] 为第j个硬币，而 i - coins[j] 为钱数i减去其中一个硬币的值，剩余的钱数在 dp 数组中找到值，
  然后加1和当前 dp 数组中的值做比较，取较小的那个更新 dp 数组。先来看迭代的写法如下所示：
  */
class Solution
{
public:
  int coinChange(vector<int> &coins, int amount)
  {
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;

    for (int i = 1; i <= amount; ++i)
    {
      // 遍历每个硬币
      for (int j = 0; j < coins.size(); ++j)
      {
        // 如果遍历到的硬币值小于i值, try to find dp[i - coins[j]]
        if (coins[j] <= i)
        {
          dp[i] = min(dp[i], dp[i - coins[j]] + 1);
        }
      }
    }
    return (dp[amount] > amount) ? -1 : dp[amount];
  }
};
/*
  Solution: 

  http://zxi.mytechroad.com/blog/dynamic-programming/leetcode-322-coin-change/

*/

class Solution
{
public:
  int coinChange(vector<int> &coins, int amount)
  {
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;
    for (auto coin : coins)
    {
      for (int i = amount - coin; i >= 0; --i)
        if (dp[i] != INT_MAX)
          for (int k = 1; k * coin + i <= amount; ++k)
            dp[i + k * coin] = min(dp[i + k * coin], dp[i] + k);
    }

    return dp[amount] == INT_MAX ? -1 : dp[amount];
  }
};