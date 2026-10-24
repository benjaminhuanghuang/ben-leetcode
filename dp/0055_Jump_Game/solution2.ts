/*
55. Jump Game

https://leetcode.com/problems/jump-game/

Determines if you are able to reach the last index.
*/

/*
Greedy Solution

https://www.youtube.com/watch?v=Yan0cv2cLy8
To every position, we can choose jump 1 or jump as fare a far as the current position allows.
*/

/*
https://www.youtube.com/watch?v=r3pZd9ghqxk

Maintain a variable maxReach to keep track of the farthest index we can reach.
*/

function canJump(nums: number[]): boolean {
  if (nums.length == 1) {
    return true;
  }

  let maxReach = 0;
  for (let i = 0; i < nums.length && i <= maxReach; i++) {
    // i <= maxReach is the key
    maxReach = Math.max(maxReach, i + nums[i]);
    if (maxReach >= nums.length - 1) {
      return true;
    }
  }
  return false;
}

export {};
