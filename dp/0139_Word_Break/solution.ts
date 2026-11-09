/*
Use dp[i] as the sub string s[0:i] can be segmented into a space-separated sequence of one or more dictionary words.
put dp[0] as empty string and it is true.

如果s[j:i]在dict中 && dp[j]为True（即字符串s[:j]能够拆分成符合要求的子字符串），那么此时dp[i]为True
*/
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
      // if s[j:i] is in the wordDict and dp[j] is true, then dp[i] is true
      if (wordSet.has(word) && dp[j]) {
        dp[i] = true;
        break;
      }
    }
  }

  return dp[len];
}
