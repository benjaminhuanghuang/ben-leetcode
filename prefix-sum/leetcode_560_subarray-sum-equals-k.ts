/*
560. Subarray Sum Equals K

https://leetcode.com/problems/subarray-sum-equals-k/
*/

/*
    Approach 1: Brute Force
    Time Complexity: O(n^3)
*/

/*
https://zxi.mytechroad.com/blog/hashtable/leetcode-560-subarray-sum-equals-k/

Solution 0: Brute Force + Prefix sun

Pre-compute the prefix sum and check sum of nums[i:j] in O(1)

Time complexity: O(n^2)
Space complexity: O(n)
*/
function subarraySum_2(nums: number[], k: number): number {
  const n = nums.length;
  const sums: number[] = new Array(n + 1).fill(0);

  for (let i = 1; i <= n; ++i) {
    sums[i] = sums[i - 1] + nums[i - 1];
  }

  let ans = 0;
  for (let i = 0; i < n; ++i) {
    for (let j = i; j < n; ++j) {
      if (sums[j + 1] - sums[i] === k) {
        ++ans;
      }
    }
  }

  return ans;
}

/*
https://zxi.mytechroad.com/blog/hashtable/leetcode-560-subarray-sum-equals-k/

https://www.youtube.com/watch?v=2ifoG7ZIz4Q

Solution 3: Running Prefix sum

prefixSum array : 用于解决和 sum of subarray 相关问题
    prefixSum[x] = sum of subArray(0, x)
                 = prefixSum[x - 1] + nums[x]
    sum of subarray(i,j) = prefixSum[j] - prefixSum[i-1]

Time complexity: O(n)
Space complexity: O(n)
*/
function subarraySum(nums: number[], k: number): number {
  if (nums.length === 0) return 0;

  // key: sum of subarray[0, i], value: count of subarray[0, i]
  const counts: Map<number, number> = new Map();
  counts.set(0, 1); //

  let cur_sum = 0; // sum of subarray[0, i]
  let ans = 0;

  for (const num of nums) {
    cur_sum += num;

    // counts.has(cur_sum - k) means there are some positions,sum[0:pos] = cur_sum - k
    // that also means there are some subarrays, sum[pos:cur] = k
    if (counts.has(cur_sum - k)) {
      ans += counts.get(cur_sum - k)!;
    }

    counts.set(cur_sum, (counts.get(cur_sum) || 0) + 1);
  }

  return ans;
}
