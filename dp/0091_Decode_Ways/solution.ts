/*
91. Decode Ways

https://leetcode.com/problems/decode-ways/

一个加密的数字字符串，一共有多少种不同的解密方式。
12 -> AB or L

*/

/*
  The easiest solution to understand.
  
  dp[i] 表示i个字符可以有几个解 
  dp[0] 表示 empty string """

  对于s[i], 有几种可能：
  如果s[i]=='0' s[i]不能单独作为一个字符，只能s[i-1,i] 放在一起才合法，此时s[i] = s[i-2]
  如果s[i]!='0' s[i]可以单独作为一个字符，此时s[i] = s[i-1]
  如果s[i-1]=='0' s[i-1...i]不合法，此时s[i] = s[i-1]
  如果s[i-1...i] 是一个合法的两位数字即10 to 26 此时 s[i] = s[i-1] + s[i-2] 
  
*/
function numDecodings(s: string): number {
  if (s.length === 0 || s[0] === "0") {
    return 0;
  }

  const dp: number[] = new Array(s.length + 1).fill(0);
  dp[0] = 1;

  for (let i = 1; i < dp.length; ++i) {
    let way = 0;

    if (s[i - 1] !== "0") {
      // treat s[i] as a single number, need check s[i-1]
      way += dp[i - 1];
    }

    if (i > 1 && (s[i - 2] === "1" || (s[i - 2] === "2" && s[i - 1] <= "6"))) {
      way += dp[i - 2];
    }

    dp[i] = way;
  }

  return dp[dp.length - 1];
}
/*
Hauhua
https://www.youtube.com/watch?v=OjEHST4SXfE

Recursion + Memorization
Time complexity: O(n^2) -> O(n)
Space complexity: O(n^2) -> O(n)



Solution 2: DP
    Time complexity O(n)
    Space complexity O(n) -> 0(1)
    
    dp[i] : ways to decode s[0] .. s[i]
    dp (-1] = 1
    dp [i] =
    1: ans = 0, if s[i], s[i-1]s[i] are invalid
    2: dp[i -1]+dp[1-2], if s[i], s[i-1]s[i] are valid
    3: dp [i-1], if s[i] is valid
    4: dp [i-2], if s[i-1]s(i] is valid
    
    s[i] is valid       if s[i] != '0'
    s[i-1]s[i] is valid if '10'<= s[i - 1][s[i] <= '26'
*/

function numDecodings2(s: string): number {
  if (s.length === 0) {
    return 0;
  }

  const memo: { [key: string]: number } = { "": 1 };

  function ways(subs: string): number {
    if (subs in memo) {
      return memo[subs];
    }

    if (subs[0] === "0") {
      return 0;
    }

    let totalWays = ways(subs.slice(1)); // Decode as a single character

    if (
      subs.length >= 2 &&
      (subs[0] === "1" || (subs[0] === "2" && subs[1] <= "6"))
    ) {
      totalWays += ways(subs.slice(2)); // Decode as a double character
    }

    memo[subs] = totalWays;
    return totalWays;
  }

  return ways(s);
}
