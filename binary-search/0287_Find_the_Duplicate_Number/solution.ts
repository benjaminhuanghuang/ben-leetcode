/*
287. Find the Duplicate Number

https://leetcode.com/problems/find-the-duplicate-number/

Note: no extra space 

*/

/*
Approach: Binary Search

https://zxi.mytechroad.com/blog/algorithms/binary-search/leetcode-287-find-the-duplicate-number/
 
Time Complexity O(NlogN) 
Space Complexity O(1)
二分查找,    1..10, 小于等于5的一定有5个,如果多于5个,就在lower part, 等于5个就是upper part.
Find the smallest m such that len(nums <= m) > m, which means m is the duplicate number.
   
*/

function findDuplicate(nums: number[]): number {
  let l = 1;
  let r = nums.length;

  while (l < r) {
    const m = Math.floor((r - l) / 2) + l;
    let count = 0; // len(nums <= m)

    for (const num of nums) {
      if (num <= m) {
        ++count;
      }
    }

    if (count <= m) {
      // find the smallest m such that len(nums <= m) > m
      l = m + 1;
    } else {
      r = m;
    }
  }

  return l;
}

function findDuplicate_faster(nums: number[]): number {
  let slow = nums[0];
  let fast = nums[slow];
  while (slow !== fast) {
    slow = nums[slow];
    fast = nums[nums[fast]];
  }
  fast = 0;
  while (slow !== fast) {
    fast = nums[fast];
    slow = nums[slow];
  }
  return slow;
}
