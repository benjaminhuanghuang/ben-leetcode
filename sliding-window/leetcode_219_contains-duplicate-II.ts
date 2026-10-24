/*
219. Contains Duplicate II

https://leetcode.com/problems/contains-duplicate-ii/
*/

/*
    Approach: Brute Force
    Time Complexity: O(N * K)
*/

/*
    Approach: Hash Map
    Time Complexity: O(N)
    Space Complexity: O(N)
*/
function containsNearbyDuplicate(nums: number[], k: number): boolean {
  const map = new Map<number, number>();
  for (let i = 0; i < nums.length; i++) {
    if (map.has(nums[i]) && i - map.get(nums[i])! <= k) {
      return true;
    }
    map.set(nums[i], i);
  }
  return false;
}

/*
    Approach: Sliding Window+Hash Set

    https://www.bilibili.com/video/BV1Pt41137RR/
    Add new element to the set, if the set size is greater than k, remove the oldest element

    Time Complexity: O(N)
    Space Complexity: O(K)
*/

function containsNearbyDuplicate2(nums: number[], k: number): boolean {
  const set = new Set<number>();

  for (let i = 0; i < nums.length; i++) {
    if (set.has(nums[i])) {
      return true;
    }
    set.add(nums[i]);
    if (set.size > k) {
      set.delete(nums[i - k]);
    }
  }
  return false;
}
