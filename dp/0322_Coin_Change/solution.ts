/*
322. Coin Change

https://leetcode.com/problems/coin-change/
*/

/*
LaiOffer: Naive dynamic programming

https://www.youtube.com/watch?v=htdBJul3xoc

n = number of types of coins
m = desired amount

If [1][j] represents min number of coins needed to make up amount j with only coins(i..n-1]


*/

/*
huahua
https://www.youtube.com/watch?v=uUETHdijzkA

dp[i][j] = min number of coins needed to make up amount j with only first types of coins [0..i-1]
Init: dp[-1][0] = 0, dp[-1][j] = Infinity
Transition: dp[i][j] = min(dp[i-1][j], dp[i][j- k*coins[i]] + k)  // user k coins[i] and the dp[i][j- k*coins[i]]
Time complexity: O(n*amount^2)
Space complexity: O(n*amount)

Transition2: dp[i][j] = min(dp[i-1][j], dp[i][j-coins[i]] + 1)
Time complexity: O(n*amount)
Space complexity: O(amount)

Answer: dp[n-1][amount]
*/
function coinChange_huahua(coins: number[], amount: number): number {
  const dp: number[] = new Array(amount + 1).fill(Infinity);
  dp[0] = 0;

  for (const coin of coins) {
    for (let i = amount - coin; i >= 0; --i) {
      if (dp[i] !== Infinity) {
        for (let k = 1; k * coin + i <= amount; ++k) {
          dp[i + k * coin] = Math.min(dp[i + k * coin], dp[i] + k);
        }
      }
    }
  }

  return dp[amount] === Infinity ? -1 : dp[amount];
}

/*

*/
function coinChange2(coins: number[], amount: number): number {
  // dp[i] = min number of coins needed to make up amount i
  const dp = Array(amount + 1).fill(amount + 1);
  dp[0] = 0;
  for (const coin of coins) {
    // 遍历所有可以用当前硬币产生的金额i
    for (let i = coin; i <= amount; i++) {
      // 如果我想用 coin 凑出金额 i, 可以从 i - coin 这个金额加一枚 coin 来得到
      dp[i] = Math.min(dp[i], dp[i - coin] + 1);
    }
  }
  return dp[amount] > amount ? -1 : dp[amount];
}
