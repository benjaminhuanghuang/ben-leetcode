/*
76. Minimum Window Substring

https://leetcode.com/problems/minimum-window-substring/

[Facebook][Meta][LinkedIn][Twitter]
*/

/* 
Approach: Sliding Window

尾指针不断往后扫，当扫到有一个窗口包含了所有T的字符，然后再收缩头指针，直到不能再收缩为止。
最后记录所有可能的情况中窗口最小的。
用dict来表示滑窗， 字符加入滑窗，从dict[c] - 1，从滑窗中删去字符，dict[c] +1
Time complexity: O(n)
Space complexity: O(n)
*/
function minWindow(s: string, t: string): string {
  // Create a map to store the frequency of characters in t.
  const charFreq: Map<string, number> = new Map();
  for (let i = 0; i < t.length; i++) {
    charFreq.set(t[i], (charFreq.get(t[i]) ?? 0) + 1);
  }

  let res = "";
  let minWinSize = s.length + 1; // Initialize resLength to a value greater than the length of s
  let start = 0;
  let leftCharCount = t.length; // Number of characters in t to be found in s

  for (let right = 0; right < s.length; right++) {
    // DO NOT use if(charFreq[s[right]]), when  charFreq[s[right]] === 0, it will be false
    if (charFreq.has(s[right])) {
      // If s[right] is in t
      if (charFreq.get(s[right])! > 0) {
        leftCharCount--;
      }
      charFreq.set(s[right], charFreq.get(s[right])! - 1);
    }

    // When leftCharCount == 0, substring s[start : right] contains all characters in t, try to shrink the window by moving first char in the window
    while (leftCharCount === 0) {
      if (minWinSize > right - start + 1) {
        // find answer sild window shorter than last res or find res firstly
        minWinSize = right - start + 1;
        res = s.substring(start, start + minWinSize);
      }

      if (charFreq.has(s[start])) {
        if (charFreq.get(s[start])! >= 0) {
          // 假设 freq == 0, 说明这个字符是必须的，移除后 leftCharCount + 1
          // remove first char from the sub string
          leftCharCount++;
        }
        charFreq.set(s[start], charFreq.get(s[start])! + 1);
      }
      start++;
    }
  }

  return res;
}
