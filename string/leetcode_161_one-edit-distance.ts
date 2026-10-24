/*
161. One Edit Distance

https://leetcode.com/problems/one-edit-distance/
*/

/*
    https://algo.monster/liteproblems/161
*/
// Check if string 's' can be converted to string 't' with exactly one edit
function isOneEditDistance(s: string, t: string): boolean {
  let lengthS = s.length; // Length of string 's'
  let lengthT = t.length; // Length of string 't'

  // Ensure 's' is not shorter than 't'
  if (lengthS < lengthT) return isOneEditDistance(t, s);

  // If the lengths differ by more than 1, it can't be a single edit
  if (lengthS - lengthT > 1) return false;

  // Iterate through characters in both strings, T is the shorter string
  for (let i = 0; i < lengthT; i++) {
    // If characters don't match, check the types of possible one edit
    //       i
    // T: aaabc
    // S: aaadca
    if (s[i] !== t[i]) {
      // If lengths are the same, check for replace operation
      if (lengthS === lengthT) return s.substring(i + 1) === t.substring(i + 1);
      // If lengths differ, check for insert operation
      return s.substring(i + 1) === t.substring(i);
    }
  }

  // If all previous characters matched, it might be an append operation
  return lengthS === lengthT + 1;
}
