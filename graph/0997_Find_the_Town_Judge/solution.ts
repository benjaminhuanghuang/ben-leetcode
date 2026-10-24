/*
997. Find the Town Judge

https://leetcode.com/problems/find-the-town-judge/
*/

/*
Approach: Graph

node with degree (in_degree – out_degree) N – 1 is the judge.
Time complexity: O(N+T)
Space complexity: O(N)

*/
function findJudge(n: number, trust: number[][]): number {
  // N people, 1 to N
  const degrees: number[] = new Array(n + 1).fill(0); // N people, 1 to N

  for (const t of trust) {
    degrees[t[0]]--;
    degrees[t[1]]++;
  }

  for (let i = 1; i <= n; ++i) {
    if (degrees[i] === n - 1) {
      return i;
    }
  }

  return -1;
}
