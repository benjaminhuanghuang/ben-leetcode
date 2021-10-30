// https://leetcode.com/problems/two-sum/

/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function (nums, target) {
  const hashTable = {};

  for (let i = 0; i < nums.length; i++) {
    const rest = target - nums[i];
    if (rest in hashTable) {
      return [i, hashTable[rest]];
    }
    hashTable[nums[i]] = i;
  }
  return [-1, -1]
};


var twoSum_es6 = function (nums, target) {
    const hashTable = new Map();
  
    for (let i = 0; i < nums.length; i++) {
      const rest = target - nums[i];
      if (hashTable.has(rest)) {
        return [i, hashTable.get(rest)];
      }
      hashTable.set(nums[i], i);
    }
    return [-1, -1]
  };

export { twoSum };