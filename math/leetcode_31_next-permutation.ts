/*
31. Next Permutation

https://leetcode.com/problems/next-permutation/

[Meta]
*/

/*
Solution: 
Find the min number that is greater than the current number.

Find the last acceding element x: find nums[i] < nums[i+1]
swap with the smallest number y, y is after x and y is greater than x.
Reverse the elements after x.
Sample:
1 2 7 4 3 1
  ^
1 2 7 4 3 1
        ^
1 3 7 4 2 1
  ^      ^
1 3 1 2 4 7
    ^ ^ ^ ^

Time complexity: O(n)
Space complexity: O(1)
*/

function nextPermutation(nums: number[]): void {
  let i = nums.length - 2;

  // Find the first decreasing element
  // 找到从递增到递减的转折点 ^
  while (i >= 0 && nums[i + 1] <= nums[i]) {
    i--;
  }

  // the number n[i] to n[n-1] is in descending order
  // Find the min number that is greater than the pivot number, nums[i]
  if (i >= 0) {
    let j = nums.length - 1;
    while (j >= 0 && nums[j] <= nums[i]) {
      j--;
    }
    // Swap nums[i] and nums[j]
    [nums[i], nums[j]] = [nums[j], nums[i]];
  }

  // Reverse the elements from i + 1 to the end of the array
  reverse(nums, i + 1);
}

function reverse(nums: number[], start: number): void {
  let end = nums.length - 1;
  while (start < end) {
    [nums[start], nums[end]] = [nums[end], nums[start]];
    start++;
    end--;
  }
}
