/*
383. Ransom Note

https://leetcode.com/problems/ransom-note/
*/

/*
    Count the frequency of each character in the magazine.
    Then, check if the ransomNote can be constructed using the characters in the magazine.
*/
function canConstruct(ransomNote: string, magazine: string): boolean {
  let map = new Map<string, number>();

  for (let i = 0; i < magazine.length; i++) {
    let char = magazine[i];
    map.set(char, (map.get(char) || 0) + 1);
  }

  for (let i = 0; i < ransomNote.length; i++) {
    let char = ransomNote[i];
    let count = map.get(char) || 0;
    if (count === 0) return false;
    map.set(char, count - 1);
  }

  return true;
}
