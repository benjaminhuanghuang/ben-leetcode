/*
2389. Longest Subsequence With Limited Sum

https://leetcode.com/problems/longest-subsequence-with-limited-sum/
*/

/*
 prefixSums + binary search
*/
function answerQueries(nums: number[], queries: number[]): number[] {
  nums.sort((a, b) => a - b);

  // Calculate prefix sums in place, each element becomes the sum of all
  // previous elements in the sorted array
  for (let i = 1; i < nums.length; i++) {
    nums[i] += nums[i - 1];
  }

  // Answer array to hold the maximum lengths per query
  const answers: number[] = [];

  // Binary search function to find out the maximum length of subarray
  // for a single query
  const binarySearch = (prefixSums: number[], target: number): number => {
    let left = 0;
    let right = prefixSums.length;

    // Perform a binary search to find the right position where the sum
    // exceeds the query value
    while (left < right) {
      const mid = Math.floor((left + right) / 2);
      if (prefixSums[mid] > target) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }

    // Return the index, which represents the maximum length of subarray
    return left;
  };

  // Iterate through each query and use the binary search function
  // to find the maximum length of subarray that fits the query condition
  for (const query of queries) {
    answers.push(binarySearch(nums, query));
  }

  // Return the final answers array with maximum lengths per query
  return answers;
}
