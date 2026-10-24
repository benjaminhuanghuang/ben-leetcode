/*
137. Single Number II

https://leetcode.com/problems/single-number-ii/
*/

/*
可以为每个位上1的数目计数。然后将该计数%3，剩下的1肯定是单独的数字贡献的。
*/
function singleNumber(nums: number[]): number {
  let result = 0;
  for (let i = 0; i < 32; i++) {
    const curBits: number = nums
      .map((n) => (n >> i) & 1)
      .reduce((acc, val) => acc + val, 0);
    result |= (curBits % 3) << i;
  }

  return result;
}

function singleNumber_Navie(nums: number[]): number {
  let arraySet = new Set(nums);
  // Convert set back to array
  let uniqueArray = Array.from(arraySet);

  // Calculate the sum of the elements
  let uniqueSum = uniqueArray.reduce((acc, val) => acc + val, 0);
  let sum = nums.reduce((acc, val) => acc + val, 0);

  return (3 * uniqueSum - sum) / 2;
}
