/*
75. Sort Colors

https://leetcode.com/problems/sort-colors/


[Facebook][Meta]
*/

/*
The algorithm used here is the Dutch National Flag problem algorithm proposed by Edsger W. Dijkstra
https://en.wikipedia.org/wiki/Dutch_national_flag_problem

Approach: Two Pointers + in-place
split the array into 4 parts:
- 0: all 0 [0 to start]
- 1: all 1 [start to i]
- 2: unknown to be processed [i to end]
- 3: all 2 [end to len-1]
*/
function sortColors(nums: number[]): void {
  // pointer0: Pointer to the position where the next 0 should be placed.
  // pointer2: Pointer to the position where the next 2 should be placed.
  // i: Current index being evaluated.
  let pointer0 = 0;
  let pointer2 = nums.length - 1;
  let i = 0;
  while (i <= pointer2) {
    if (nums[i] == 0) {
      swap(nums, i, pointer0);
      i++;
      pointer0++;
    } else if (nums[i] == 1) {
      i++;
    } else {
      // don't increase i here, because we need to check the swapped element
      // 被换到 i 位置的元素是未知的！（可能是 0, 1）
      // the swapped element could be 0 or 1
      swap(nums, i, pointer2);
      pointer2--;
    }
  }
}

function swap(nums: number[], i: number, j: number) {
  const tmp = nums[j];
  nums[j] = nums[i];
  nums[i] = tmp;
}
