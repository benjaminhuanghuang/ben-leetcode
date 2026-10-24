/*
1529. Minimum Suffix Flips

https://leetcode.com/problems/minimum-suffix-flips/
*/

function minFlips(target: string): number {
  let flipsCount = 0;

  for (let i = 0; i < target.length; i++) {
    let bit = parseInt(target[i], 10); // Convert character to integer (0 or 1)

    //if flipsCount is even and bit is 1
    if ((flipsCount & 1) ^ bit) {
      flipsCount++;
    }
  }

  return flipsCount;
}
