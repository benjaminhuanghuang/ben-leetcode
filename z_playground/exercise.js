/**
 * @param {string} s
 * @return {number}
 */
function numDecodings(s) {
  const n = s.length;

  const dp = new Array(n + 1).fill(0);

  // Base case
  dp[0] = 1;

  for (let i = 1; i <= n; i++) {
    let way = 0;
    // Case 1: last digit decoded alone (invalid if it's '0')
    const lastDigit = s[i - 1];
    const canDecodeSingle = lastDigit !== "0";
    if (canDecodeSingle) {
      way = dp[i - 1];
    }

    // Case 2: last two digits decoded together (valid if it's 10-26)
    if (i >= 2) {
      const twoDigits = Number(s.slice(i - 2, i));
      const canDecodeDouble = twoDigits >= 10 && twoDigits <= 26;
      if (canDecodeDouble) {
        way += dp[i - 2];
      }
    }
    dp[i] = way;
  }

  return dp[n];
}
