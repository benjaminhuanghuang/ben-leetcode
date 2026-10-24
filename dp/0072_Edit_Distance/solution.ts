/*
72. Edit Distance

https://leetcode.com/problems/edit-distance/
*/
function minDistance(word1: string, word2: string): number {
  const l1 = word1.length;
  const l2 = word2.length;

  // d[i][j] := minDistance(word1[0:i - 1], word2[0:j - 1]);
  const d: number[][] = Array.from({ length: l1 + 1 }, () =>
    Array(l2 + 1).fill(0)
  );

  // Base cases
  for (let i = 0; i <= l1; ++i) {
    d[i][0] = i;
  }
  for (let j = 0; j <= l2; ++j) {
    d[0][j] = j;
  }

  // Fill the dp table
  for (let i = 1; i <= l1; ++i) {
    for (let j = 1; j <= l2; ++j) {
      const c = word1[i - 1] === word2[j - 1] ? 0 : 1;
      d[i][j] = Math.min(
        d[i - 1][j - 1] + c,
        Math.min(d[i][j - 1], d[i - 1][j]) + 1
      );
    }
  }

  return d[l1][l2];
}
