/*
242. Valid Anagram

https://leetcode.com/problems/valid-anagram/

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, 
typically using all the original letters exactly once.
*/

/*
    Count the frequency of each character in both strings.
*/
function isAnagram(s: string, t: string): boolean {
  if (s.length !== t.length) return false;

  const map = new Map<string, number>();

  for (let i = 0; i < s.length; i++) {
    map.set(s[i], (map.get(s[i]) || 0) + 1);
    map.set(t[i], (map.get(t[i]) || 0) - 1);
  }

  for (const [key, value] of map) {
    if (value !== 0) return false;
  }
  return true;
}
