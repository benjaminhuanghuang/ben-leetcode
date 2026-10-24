/*
1980. Find Unique Binary String

https://leetcode.com/problems/find-unique-binary-string/
*/

/*

Let ans[i] = ‘1’ – nums[i][i], s.t. ans is at least one bit different from any strings.
Time complexity: O(n)
Space complexity: O(1)
*/
function findDifferentBinaryString(nums: string[]): string {
  const n = nums.length;
  let ans = Array(n).fill("0").join("");

  for (let i = 0; i < n; ++i) {
    // If the i-th bit of nums[i] is 0, then we set the ith bit of ans to 1.
    ans =
      ans.substring(0, i) +
      (1 - parseInt(nums[i][i], 10)).toString() +
      ans.substring(i + 1);
  }

  return ans;
}

/*
Approach 2: Set<number>
We can use bitset to convert between integer and binary string.

Time complexity: O(N^2)
Space complexity: O(N^2)
*/
function findDifferentBinaryString_2(nums: string[]): string {
  const n = nums.length;
  const seen = new Set<number>();

  // Convert binary strings to numbers and add them to the set
  for (const num of nums) {
    seen.add(parseInt(num, 2));
  }

  // Find the smallest number not in the set and return its binary representation
  for (let i = 0; i < 1 << n; ++i) {
    if (!seen.has(i)) {
      return i.toString(2).padStart(n, "0");
    }
  }

  return "";
}
