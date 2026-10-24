/*
1539. Kth Missing Positive Number

https://leetcode.com/problems/kth-missing-positive-number/
*/

function findKthPositive(arr: number[], k: number): number {
  // If the first element in the array is greater than k,
  // then the kth missing number must be k itself.
  if (arr[0] > k) {
    return k;
  }

  let left = 0;
  let right = arr.length; // The right boundary for the binary search.

  // Binary search to find the lowest index such that the number of
  // positive integers missing before arr[index] is at least k.
  while (left < right) {
    let mid = left + Math.floor((right - left) / 2);
    // If the number of missing numbers up to arr[mid] is at least k,
    // we need to search on the left side (including mid).
    if (arr[mid] - mid - 1 >= k) {
      right = mid;
    } else {
      left = mid + 1; // Otherwise, we search on the right side.
    }
  }

  // After the loop, left is the smallest index such that the number of
  // positive integers missing before arr[left] is at least k. Using the
  // index left - 1, we find the kth missing number.
  return arr[left - 1] + k - (arr[left - 1] - (left - 1) - 1);
}
