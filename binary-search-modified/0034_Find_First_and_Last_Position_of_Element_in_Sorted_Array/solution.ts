/*
34. Find First and Last Position of Element in Sorted Array

https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
*/

function searchRange(nums: number[], target: number): number[] {
  if (nums.length < 1) return [-1, -1];

  let left = 0;
  let right = nums.length - 1;
  let result: number[] = [-1, -1];

  while (left <= right) {
    let mid = left + Math.floor((right - left) / 2);
    if (nums[mid] > target) right = mid - 1;
    else if (nums[mid] < target) left = mid + 1;
    else {
      // mid == target, expand the range
      result[0] = mid;
      result[1] = mid;
      let i = mid - 1;
      while (i >= 0 && nums[i] == target) {
        result[0] = i;
        i--;
      }
      i = mid + 1;
      while (i < nums.length && nums[i] == target) {
        result[1] = i;
        i++;
      }
      break; // DO NOT Forget
    }
  }
  return result;
}

function searchRange_2(nums: number[], target: number): number[] {
  const index = find(nums, target);
  if (index === -1) return [-1, -1];

  const left = findLest(nums, target);
  const right = findRight(nums, target);
  return [left, right - 1];
}

function find(nums: number[], target: number): number {
  let left = 0;
  let right = nums.length;

  while (left < right) {
    let mid = left + Math.floor((right - left) / 2);
    if (nums[mid] === target) {
      return mid;
    }
    // find minimin m can make g(m) is true
    if (nums[mid] > target) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }
  return -1;
}

// lower bound, find the first number >= target
function findLest(nums: number[], target: number): number {
  let left = 0;
  let right = nums.length;

  while (left < right) {
    let mid = left + Math.floor((right - left) / 2);
    // find minimin m can make g(m) is true
    if (nums[mid] >= target) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }
  return left;
}
// Upper bound, first number that is greater than target
function findRight(nums: number[], target: number): number {
  let left = 0;
  let right = nums.length;

  while (left < right) {
    let mid = left + Math.floor((right - left) / 2);
    if (nums[mid] > target) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }
  return left;
}
