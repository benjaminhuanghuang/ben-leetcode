/*
1358. Number of Substrings Containing All Three Characters

Level: Medium

https://leetcode.com/problems/number-of-substrings-containing-all-three-characters
*/

/*
  Solution: 
  https://www.youtube.com/watch?v=XQ8vE_nLVXY
*/

/**
 * @param {string}
 * @return {number}
 */
var numberOfSubstrings = function (s) {
  const aMap = { a: 0, b: 0, c: 0 };
  let res = 0;
  for (let i = 0, j=0; i < s.length; i++) {
    const c = s[i];
    aMap[c]++;

    // run j
    while (j < i && aMap['a'] > 0 && aMap['b'] > 0 && aMap['c'] > 0) {
      aMap[s[j]]--;
      j++;
    }
    res += j;
  }
  return res;
};

export { numberOfSubstrings };
