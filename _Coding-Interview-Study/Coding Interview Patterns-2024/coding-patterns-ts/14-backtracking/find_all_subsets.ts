function findAllSubsets(nums: number[]): number[][] {
  const res: number[][] = [];
  backtrack(0, [], nums, res);
  return res;
}

function backtrack(
  i: number,
  currSubset: number[],
  nums: number[],
  res: number[][]
): void {
  // Base case: if all elements have been considered, add the
  // current subset to the output.
  if (i === nums.length) {
    res.push([...currSubset]);
    return;
  }

  // Include the current element and recursively explore all paths
  // that branch from this subset.
  currSubset.push(nums[i]);
  backtrack(i + 1, currSubset, nums, res);

  // Exclude the current element and recursively explore all paths
  // that branch from this subset.
  currSubset.pop();
  backtrack(i + 1, currSubset, nums, res);
}

/*
Time complexity: The time complexity of -find_all_subsets is O(n· 2n). This is because the state
space tree has a depth of n and a branching factor of 2 since there are two decisions we make at
each state. For each of the 2n subsets created, we make a copy of them and add the copy to the
output, which takes O(n) time. This results in a total time complexity of O(n • 2n).

Space complexity: The space complexity is O(n) because the maximum depth of the recursion tree
is n. The algorithm also maintains the currSubset data structure which also contributes O(n) space. Note, the res array does not contribute to space complexity.
*/
