/*
70. Climbing Stairs

https://leetcode.com/problems/climbing-stairs/

*/
#include <vector>

using namespace std;

class Solution
{
public:
  int climbStairs(int n)
  {
    if (n <= 2)
    {
      return n;
    }
    int dp[n];
    dp[0] = 1;
    dp[1] = 2;
    for (int i = 2; i < n; i++)
      dp[i] = dp[i - 1] + dp[i - 2];
    return dp[n - 1];
  }

  int climbStairs_DP2(int n)
  {
    if (n <= 2)
      return n;
    vector<int> dp(n + 1, 0);

    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; i++)
      dp[i] = dp[i - 1] + dp[i - 2];

    return dp[n];
  }

  int climbStairs_DP3(int n)
  {
    if (n <= 2)
      return n;
    int one_step_before = 2;
    int two_step_before =1;
    int all_ways = 0;

    for (int i= 2; i < n ;i++){
      all_ways = one_step_before + two_step_before;
      two_step_before = one_step_before;
      one_step_before = all_ways;
    }

    return all_ways;
  }

  int climbStairs_v2(int n)
  {
    //Answers to the question form the Fibonacci squence.
    //We only have to find the corresponding number to n.
    int number = 1;
    int adittion = 1;
    for (int i = 0; i < n - 1; i++)
    {
      number = number + adittion;
      adittion = number - adittion;
    }
    return number;
  }
};