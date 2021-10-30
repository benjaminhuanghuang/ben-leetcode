/*
454. 4Sum II

Level: Medium

https://leetcode.com/problems/4sum-ii
*/

/*
  Solution: 
*/

/**
 * @param {number[]} A
 * @param {number[]} B
 * @param {number[]} C
 * @param {number[]} D
 * @return {number}
 */
var fourSumCount = function (A, B, C, D) {
  let combinationMap = new Map();   // save <A+B : times>

  // Compute and store all combinations of A + B
  for (let i = 0; i < A.length; i++) {
    for (let j = 0; j < B.length; j++) {
      const combination = A[i] + B[j];

      // Add the combination to the map if new, else increment its number of occurrences
      combinationMap.set(combination, combinationMap.has(combination) ? combinationMap.get(combination) + 1 : 1);
    }
  }

  let combinations = 0;

  // Compute all combinations of C + D
  for (let k = 0; k < C.length; k++) {
    for (let l = 0; l < D.length; l++) {
      // Calculate the complement required to sum as 0
      const complement = -(C[k] + D[l]);
      if (combinationMap.has(complement)) {
        // Increment the number of combinations by the number of times said compliment was found
        combinations += combinationMap.get(complement);
      }
    }
  }

  return combinations;
};
