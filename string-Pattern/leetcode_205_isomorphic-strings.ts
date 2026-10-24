/*
205. Isomorphic Strings

https://leetcode.com/problems/isomorphic-strings/

290. Word Pattern
*/

/*
    Use two maps to store the mapping of each character in s to t and t to s.
*/
function isIsomorphic(s: string, t: string): boolean {
  if (s.length !== t.length) return false;

  const stMap: { [key: string]: string } = {};
  const tsMap: { [key: string]: string } = {};

  // go through each character of s and t
  for (let i = 0; i < s.length; i++) {
    const sChar = s[i];
    const tChar = t[i];

    if (!stMap[sChar]) {
      // if sChar is not in the map, add it
      stMap[sChar] = tChar;
    } else {
      // if sChar is in the map, check if the value is the same as tChar
      if (stMap[sChar] !== tChar) return false;
    }

    if (!tsMap[tChar]) {
      tsMap[tChar] = sChar;
    } else {
      if (tsMap[tChar] !== sChar) return false;
    }
  }

  return true;
}
