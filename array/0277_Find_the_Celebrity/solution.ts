/*
277. Find the Celebrity

https://leetcode.com/problems/find-the-celebrity/

A celebrity is someone whom everyone knows but who knows no one themselves.

[Facebook][Amazon]
*/

declare function knows(a: number, b: number): boolean;
/*
Laioffer: https://www.youtube.com/watch?v=QDehNYXlCAg

Approach: Brute Force
for each person
   for each other person
      check !knows(i, j) && knows(j, i)

Time Complexity: O(N^2)


Approach: Two Pass
Time Complexity: O(N)

knows(a, b) => b is NOT a celebrity
!knows(a, b) => b is NOT a celebrity
*/

function findCelebrity(n: number): number {
  return -1;
}
/*

https://www.youtube.com/watch?v=kzgYtJOUfMM

*/

function findCelebrity1(n: number): number {
  if (n === 0) {
    return -1;
  }

  let x = 0;
  let y = n - 1;

  while (x < y) {
    // x knows y => x is not a celebrity
    if (knows(x, y)) {
      x++;
    } else {
      // x does not know y => y is not a celebrity
      y--;
    }
  }
  // x mby be a celebrity
  // make sure x is a celebrity
  for (let i = 0; i < n; i++) {
    if (i !== x && (knows(x, i) || !knows(i, x))) {
      return -1;
    }
  }
  return x;
}

/*
Approach: Tow Pass

https://algo.monster/liteproblems/277
*/

function findCelebrity2(n: number): number {
  // Initialize the candidate for the celebrity to 0
  let candidate: number = 0;

  // The first loop is to find a candidate who might be the celebrity.
  for (let i = 1; i < n; i++) {
    // If the candidate knows 'i', then 'candidate' cannot be the celebrity.
    // In this case, 'i' might be the new candidate.
    if (knows(candidate, i)) {
      candidate = i;
    }
  }

  // The second loop is to confirm whether the candidate is the celebrity.
  for (let i = 0; i < n; i++) {
    // The candidate should not know any other person,
    // and all other people should know the candidate.
    // If these conditions are not met, return -1 indicating there is no celebrity.
    if (candidate !== i && (knows(candidate, i) || !knows(i, candidate))) {
      return -1;
    }
  }

  // If all conditions are met, return the candidate as the celebrity.
  return candidate;
}
