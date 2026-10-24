/*
  Solution: 
*/

/**
 * @param {number} n
 * @return {number[]}
 */
var getNoZeroIntegers = function (n) {
  for (let i = 1; i < n; i++) {
    if (i.toString().includes("0")) {
      continue;
    }

    const right = n - i;

    if (!right.toString().includes("0")) {
      return [i, right];
    }
  }
};

export { getNoZeroIntegers };
