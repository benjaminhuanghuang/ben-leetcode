/*
1525. Number of Good Ways to Split a String

Level: Medium

https://leetcode.com/problems/number-of-good-ways-to-split-a-string
*/

/*
  Solution: 
*/

/**
 * @param {string} s
 * @return {number}
 */
var numSplits = function (s) {
  let goodSplits = 0;
  const left = new Array(26).fill(0);
  const right = new Array(26).fill(0);

  const getDidtinct = (arr) => {
    return arr.reduce((acc, i) => {
      if (i > 0) {
        return acc + 1;
      }
      return acc;
    }, 0);
  };

  for (let i = 0; i < s.length; i++) {
    right[s.charCodeAt(i) - 97]++;
  }

  for (let i = 0; i < s.length; i++) {
    left[s.charCodeAt(i) - 97]++;
    right[s.charCodeAt(i) - 97]--;

    const distinctChartAtLeft = getDidtinct(left);
    
    const distinctChartAtRight = getDidtinct(right);
    if (distinctChartAtLeft === distinctChartAtRight) {
      goodSplits++;
    }
  }
  return goodSplits;
};

// Test
console.log(numSplits("aacaba"));
