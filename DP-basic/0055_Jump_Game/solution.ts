/*
Solution: DP

LeetCode DP终极学习计划！Day4 Jump Game I/II 
https://www.youtube.com/watch?v=3mIc_mKP4yM

design a function: can I jump to the N-1  from i
dp(i):bool

*/
function canJump(nums: number[]): boolean {
  return false;
}
const memo = new Map();

/** Returns whether we can reach n - 1 from i. */
function dp(i: number) {
  if (memo.has(i)) return memo.get(i);
  let result = false;

  if (i >= n - 1) result = true;
  else if (i + nums[i] >= n - 1) result = true;
  else {
    for (let s = 1; s <= nums[i]; s++) {
      if (dp(i + s)) {
        result = true;
        break;
      }
    }
  }

  memo.set(i, result);
  return result;
}

export {};
