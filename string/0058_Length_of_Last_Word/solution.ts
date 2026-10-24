/*
58. Length of Last Word

https://leetcode.com/problems/length-of-last-word/
*/

function lengthOfLastWord(s: string): number {
  if (s.length === 0) {
    return 0;
  }

  let wordEnd = s.length - 1;
  let i = s.length - 1;

  while (i >= 0) {
    if (s[i] === " ") {
      wordEnd = i - 1; // the word ends with ' '
    } else if (i === 0 || s[i - 1] === " ") {
      // word start with ' ' or the first word
      break;
    }
    i--;
  }
  return wordEnd - i + 1;
}
