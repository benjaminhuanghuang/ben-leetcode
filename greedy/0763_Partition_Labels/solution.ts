/*
763. Partition Labels

https://leetcode.com/problems/partition-labels/
*/
/*
  Solution: Brute Force

    Time complexity: O(n^2)

    Space complexity: O(1)
*/
function partitionLabels(s: string): number[] {
  const ans: number[] = [];
  let start = 0;
  let end = 0;

  for (let i = 0; i < s.length; ++i) {
    end = Math.max(end, s.lastIndexOf(s[i]));
    if (i === end) {
      ans.push(end - start + 1);
      start = end + 1;
    }
  }

  return ans;
}

/*
  Solution 1: Greedy

    Time complexity: O(n)

    Space complexity: O(26/128)
*/
function partitionLabels2(s: string): number[] {
  const lastIndex: number[] = Array(128).fill(0);

  // Record the last occurrence of each character in the string
  for (let i = 0; i < s.length; ++i) {
    lastIndex[s.charCodeAt(i)] = i;
  }

  const ans: number[] = [];
  let start = 0;
  let end = 0;

  // Partition the string
  for (let i = 0; i < s.length; ++i) {
    end = Math.max(end, lastIndex[s.charCodeAt(i)]);
    if (i === end) {
      ans.push(end - start + 1);
      start = end + 1;
    }
  }

  return ans;
}
