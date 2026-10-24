/*
139. Word Break

https://leetcode.com/problems/word-break/
*/

// Use dp[i] as the sub string s[0:i] can be segmented into a space-separated sequence of one or more dictionary words.
// put dp[0] as empty string and it is true.
// dp[k] =  dp[0] + string(0 – k) in dict; dp[1] + string(1 – k) in dict
// 如果s[j:i]在给定的字符串组中 && dp[j]为True（即字符串s[:j]能够拆分成符合要求的子字符串），那么此时dp[i]也就为True了。

function wordBreak(s: string, wordDict: string[]): boolean {
  if (wordDict.length == 0) {
    return false;
  }
  const wordSet = new Set(wordDict);
  const len = s.length;
  const dp = new Array(len + 1).fill(false);
  dp[0] = true;

  for (let i = 1; i < dp.length; i++) {
    for (let j = 0; j < i; j++) {
      const word = s.substring(j, i);
      if (wordSet.has(word) && dp[j]) {
        dp[i] = true;
        break;
      }
    }
  }

  return dp[len];
}
