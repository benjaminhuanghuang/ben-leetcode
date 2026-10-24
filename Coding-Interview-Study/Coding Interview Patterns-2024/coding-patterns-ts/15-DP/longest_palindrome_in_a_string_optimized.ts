function longestPalindromeInAStringExpanding(s: string): string {
  const n = s.length;
  if (n === 0) return "";

  let start = 0;
  let maxLen = 0;

  for (let center = 0; center < n; center++) {
    // Check for odd-length palindromes
    const [oddStart, oddLength] = expandPalindrome(center, center, s);
    if (oddLength > maxLen) {
      start = oddStart;
      maxLen = oddLength;
    }

    // Check for even-length palindromes
    if (center < n - 1 && s[center] === s[center + 1]) {
      const [evenStart, evenLength] = expandPalindrome(center, center + 1, s);
      if (evenLength > maxLen) {
        start = evenStart;
        maxLen = evenLength;
      }
    }
  }

  return s.slice(start, start + maxLen);
}

// Expands outward from left and right indices to find the longest palindrome
function expandPalindrome(
  left: number,
  right: number,
  s: string
): [number, number] {
  while (left > 0 && right < s.length - 1 && s[left - 1] === s[right + 1]) {
    left--;
    right++;
  }
  return [left, right - left + 1];
}
/*
Time complexity: The time complexity of longestPalindromeInAString ... expanding is O(n^2)
because expanding from the center to a base case takes up to O(n) time. Doing this for each base
case takes O(n^2) time.

Space complexity: The space complexity is O(1) since we aren't maintaining any auxiliary data
structures. The output string is not considered in the space complexity.
*/
