/*
464. Can I Win

Level: Medium

https://leetcode.com/problems/can-i-win
*/

/*
  Solution: 

  https://www.youtube.com/watch?v=lP9qkrJu4xw
*/

/**
 * @param {number} maxChoosableInteger
 * @param {number} desiredTotal
 * @return {boolean}
 */
var canIWin = function (maxChoosableInteger, desiredTotal) {
  // game state is number list for unchoosen nubmbers
  // use memo to remember win on states

  const sum = ((maxChoosableInteger + 1) * maxChoosableInteger) / 2;
  if (sum < desiredTotal) return false;

  if (desiredTotal <= 0) return true;

  let memo = {};

  // nums: nums can be choosen
  // target: desired total
  var recur = function (nums, target) {
    let str = nums.join(' ');
    if (nums[str]) {
      return memo[str];
    }

    if (nums[nums.length - 1] >= target) {
      memo[str] = true;
      return true;
    }
    for (let i = 0; i < nums.length; i++) {
      let nextNums = nums.slice(0, i); // [0-i)
      nextNums = nextNums.concat(nums.slice(i + 1)); // remove nums[i]
      // opponent can win
      if (!recur(nextNums, target - nums[i])) {
        memo[str] = true;
        return true;
      }
      memo[str] = false;
      return false;
    }
  }


  var initNums = new Array(maxChoosableInteger).fill(0);
  initNums = initNums.map((item, index)=>{
    return index + 1;
  });

  return recur(initNums, desiredTotal);
};

export { canIWin };
