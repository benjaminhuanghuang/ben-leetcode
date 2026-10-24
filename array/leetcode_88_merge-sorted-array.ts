/*
88. Merge Sorted Array

*/

// Time Complexity : O(n)
// Space Complexity: O(1)

function merge(nums1: number[], m: number, nums2: number[], n: number): void {
  while (n) {
    if (nums1[m - 1] > nums2[n - 1]) {
      nums1[m + n - 1] = nums1[--m];
    } else {
      nums1[m + n - 1] = nums2[--n];
    }
  }
}

function merge1(nums1: number[], m: number, nums2: number[], n: number): void {
  let last = m + n - 1;

  while (m > 0 && n > 0) {
    if (nums1[m - 1] > nums2[n - 1]) {
      nums1[last] = nums1[m - 1];
      m -= 1;
    } else {
      nums1[last] = nums2[n - 1];
      n -= 1;
    }
    last -= 1;
  }

  // If there are remaining elements in nums2 after the first loop, you'll add them to the beginning of nums1.
  while (n > 0) {
    nums1[last] = nums2[n - 1];
    n -= 1;
    last -= 1;
  }
}

export {};
