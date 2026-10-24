/*
128. Longest Consecutive Sequence

https://leetcode.com/problems/longest-consecutive-sequence/

Consecutive sequence means that the numbers are in sequence, but not necessarily in order.

O(N) solution is required.   Meas the solution should use Hashtable.
*/

/*
Hua Hua
https://www.youtube.com/watch?v=rc2QdQ7U78I

Hashset h: key
Check whether h contains (key - 1) or not
if not, key is a lower bound, check key + 1, key + 2, until key + 1 + 1 is not in h,
key ~ key + 1 in h, length is 1.
Find the max of 1s

Time complexity: O(N) , every element is visited twice.
Space complexity: O(N)
*/

function longestConsecutive(nums: number[]): number {
  const numSet: Set<number> = new Set(nums);
  let ans = 0;

  for (const num of nums) {
    if (!numSet.has(num - 1)) {
      // num is a lower bound of a sequence
      let length = 0;
      while (numSet.has(num + length)) {
        length++;
      }
      ans = Math.max(ans, length);
    }
    // if numSet.has(num - 1), (num-1) will be visited later
  }

  return ans;
}
