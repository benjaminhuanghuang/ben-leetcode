/*
{TITLE}

{URL}
*/
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


export { twoSum };