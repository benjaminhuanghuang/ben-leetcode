/*
1347. Minimum Number of Steps to Make Two Strings Anagram

https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/
*/

function minSteps(s: string, t: string): number {
  const charCount = new Array(26).fill(0);

  for (const char of s) {
    const index = char.charCodeAt(0) - "a".charCodeAt(0);
    charCount[index]++;
  }

  let steps = 0;
  for (const char of t) {
    const index = char.charCodeAt(0) - "a".charCodeAt(0);
    // Increment steps if character count falls below zero, which indicates a character in stringTwo not present in stringOne
    steps += --charCount[index] < 0 ? 1 : 0;
  }

  return steps;
}
