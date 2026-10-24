/*
28. Find the Index of the First Occurrence in a String

https://leetcode.com/problems/implement-strstr/
*/

function strStr(haystack: string, needle: string): number {
  if (!needle) {
    return 0;
  }

  for (let i = 0; i <= haystack.length - needle.length; i++) {
    for (let j = 0; j < needle.length; j++) {
      if (haystack[i + j] !== needle[j]) {
        break;
      }
      if (j === needle.length - 1) {
        return i;
      }
    }
  }

  return -1;
}
