/*
392. Is Subsequence
https://leetcode.com/problems/is-subsequence/
*/

function isSubsequence(s: string, t: string): boolean {
  let i = 0;
  let j = 0;
  while (i < s.length && j < t.length) {
    if (s[i] === t[j]) {
      i++;
    }
    j++;
  }
  return i === s.length;
}

/*
follow up:
We can preprocess t to build a list of positions for each character in t. Then store the information 
in a dictionary where the key is the character in t and the value is a list of positions where this 
character appears in t.
*/

class Solution {
  private preprocessed_t: { [key: string]: number[] };
  constructor() {
    this.preprocessed_t = {};
  }

  preprocess(t: string) {
    for (let i = 0; i < t.length; i++) {
      const char = t[i];
      if (!this.preprocessed_t[char]) {
        this.preprocessed_t[char] = [];
      }
      this.preprocessed_t[char].push(i);
    }
  }

  isSubsequence(s: string) {
    let j = -1; // Initialize j to -1, so that we start searching from the beginning of t.
    for (const char of s) {
      const posList = this.preprocessed_t[char] || [];
      const i = posList.findIndex((pos) => pos > j);
      if (i === -1) {
        // if not found
        return false;
      }
      j = posList[i]; // Update j to the index of the found character in t.
    }
    return true;
  }
}
