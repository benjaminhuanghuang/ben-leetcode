/*
 77. Combinations

 https://leetcode.com/problems/combinations

 返回 [1,2,...,n] 中所有长度为 k 的组合

*/

/*
Use the Huanhuan template
https://www.youtube.com/watch?v=CUzm-buvH_8
*/
function combine(n: number, k: number): number[][] {
  const ans: number[][] = [];
  const cur: number[] = [];

  /*
    n: total numbers
    k: combination length
    start: start index for this dfs
   */
  function dfs(start: number): void {
    if (cur.length === k) {
      ans.push([...cur]);
      return;
    }
    for (let i = start; i < n; i++) {
      cur.push(i + 1);
      dfs(i + 1);
      cur.pop();
    }
  }

  dfs(0);

  return ans;
}

/*

https://algo.monster/liteproblems/77
  
The time complexity is O(n! / (k! * (n - k)!)).
The space complexity is O(n choose k * k).

*/
// Function to generate all possible combinations of k numbers out of the range [1, n].
function combine1(n: number, k: number): number[][] {
  // Initialize the array to hold the resulting combinations.
  const combinations: number[][] = [];
  // Temporary array to hold the current combination.
  const currentCombination: number[] = [];
  // Depth-first search function to explore all possible combinations.
  const depthFirstSearch = (currentIndex: number) => {
    // If the current combination's length is k, a complete combination has been found.
    if (currentCombination.length === k) {
      // Add a copy of the current combination to the results.
      combinations.push(currentCombination.slice());
      return;
    }
    // If the currentIndex exceeds n, we've explored all numbers, so return.
    if (currentIndex > n) {
      return;
    }
    // Include the current index in the current combination and move to the next number.
    currentCombination.push(currentIndex);
    depthFirstSearch(currentIndex + 1);
    // Exclude the current index from the current combination and move to the next number.
    currentCombination.pop();
    depthFirstSearch(currentIndex + 1);
  };

  // Start the depth-first search from number 1.
  depthFirstSearch(1);
  // Return all the generated combinations.
  return combinations;
}
