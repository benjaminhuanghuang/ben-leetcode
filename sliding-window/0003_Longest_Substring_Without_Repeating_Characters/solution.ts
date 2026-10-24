/*
3. Longest Substring Without Repeating Characters

https://leetcode.com/problems/longest-substring-without-repeating-characters/
*/

/*
    Sliding Window + Hash Map
    Time complexity: O(n)
    https://www.youtube.com/watch?v=fBiiKy8kwaY
*/
function lengthOfLongestSubstring(s: string): number {
  let maxLength = 0;
  let left = 0; // left is the next index of repeating char.
  // Keep track of each character’s last seen position.
  let lastCharPos = new Map<string, number>(); // char -> index

  for (let right = 0; right < s.length; right++) {
    if (lastCharPos.has(s[right])) {
      // if the char is repeating, we need to move left pointer to the next index of repeating char,
      // it is lastCharPos.get(s[right])! + 1
      // But, for case: "tmmzuxt", when right points to the second 't', current left is 2
      // left should not move back to the first 't',
      // left should keep moving forward.
      left = Math.max(left, lastCharPos.get(s[right])! + 1);
    }
    lastCharPos.set(s[right], right);
    maxLength = Math.max(maxLength, right - left + 1);
  }
  return maxLength;
}
