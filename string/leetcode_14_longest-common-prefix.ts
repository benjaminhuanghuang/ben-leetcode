/*
14. Longest Common Prefix
https://leetcode.com/problems/longest-common-prefix/
*/

/*
 Time Complexity: O(n * m^2) in the worst case. 
 N is the number of strings in the array 
 M is the length of the longest string in the array.
*/
function longestCommonPrefix(strs: string[]): string {
  if (strs.length === 0) {
    return "";
  }

  let prefix = strs[0];
  // for each string in the array, check if the prefix is the same
  for (let i = 1; i < strs.length; i++) {
    while (strs[i].indexOf(prefix) !== 0) {
      // remove the last character from the prefix
      prefix = prefix.slice(0, prefix.length - 1);
    }
  }
  return prefix;
}
