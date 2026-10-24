/*
Given an array, return true if there are two elements withing a window of size k that are q

*/

// 检查数组中是否存在一对重复值，
// 且两个重复元素的距离不超过 k（即 arr[i] == arr[j] 且 abs(i-j) <= k）
// 时间复杂度 O(n * k)
function closeDuplicatesBruteForce(nums: number[], k: number): boolean {
  for (let l = 0; l < nums.length; l++) {
    for (let r = l + 1; r < Math.min(nums.length, l + k + 1); r++) {
      if (nums[l] === nums[r]) {
        return true;
      }
    }
  }
  return false;
}

// Same problem using sliding window
// O(n)
function closeDuplicates(nums: number[], k: number): boolean {
  const window = new Set<number>(); // Current window of size <= k, stores unique elements
  let l = 0;

  for (let r = 0; r < nums.length; r++) {
    // Shrink window if size exceeds k
    if (r - l + 1 > k) {
      window.delete(nums[l]);
      l++;
    }
    // Duplicate found within window
    if (window.has(nums[r])) {
      return true;
    }
    window.add(nums[r]);
  }

  return false;
}
