/*
1347. Minimum Number of Steps to Make Two Strings Anagram

Level: Medium

https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram
*/

/*
  Solution: 
*/

/**
 * @param {string} s
 * @param {string} t
 * @return {number}
 */
var minSteps = function (s, t) {
  const n = s.length;

  if (n < 1) {
    return 0;
  }
  const map = {};

  for (var i = 0; i < n; i++) {
    const a = s[i],
      b = t[i];

    if (map[a] === undefined) {
      map[a] = 0;
    }
    if (map[b] === undefined) {
      map[b] = 0;
    }
    map[a]++;
    map[b]--;
  }
  let res = 0;
  for (let k in map) {
    res += Math.abs(map[key]);
  }
  return res / 2;
};

export { minSteps };
