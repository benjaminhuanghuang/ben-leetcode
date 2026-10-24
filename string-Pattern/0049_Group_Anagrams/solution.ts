/*
49. Group Anagrams

https://leetcode.com/problems/group-anagrams/
*/

function groupAnagrams(strs: string[]): string[][] {
  let map = new Map<string, string[]>();
  for (let str of strs) {
    // sort the string to get the key
    let key = Array.from(str).sort().join("");

    if (!map.has(key)) {
      map.set(key, []);
    }
    map.get(key)!.push(str);
  }
  return Array.from(map.values());
}
