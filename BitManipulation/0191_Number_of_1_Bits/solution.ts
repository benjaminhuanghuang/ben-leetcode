/*
191. Number of 1 Bits

https://leetcode.com/problems/number-of-1-bits/
*/

function hammingWeight(n: number): number {
  // Initialize a count for the number of 1 bits
  let count: number = 0;

  // Continue looping as long as n is not 0
  while (n !== 0) {
    // Apply bitwise AND between n and n-1, which flips the least significant 1 bit of n to 0
    // When you subtract 1 from a number n, the least significant 1 bit in n becomes 0,
    // and all the bits to the right of this bit become 1. All bits to the left remain unchanged.
    // For example, if n = 10100, then n - 1 = 10011.
    n &= n - 1;

    // Increment the count of 1 bits
    count++;
  }

  // Return the final count of 1 bits in n
  return count;
}
