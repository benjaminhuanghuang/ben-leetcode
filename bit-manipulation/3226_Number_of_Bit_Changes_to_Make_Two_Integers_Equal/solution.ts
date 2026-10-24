/*
3226. Number of Bit Changes to Make Two Integers Equal

https://leetcode.com/problems/number-of-bit-changes-to-make-two-integers-equal/
*/

/*
If n&k != k, it indicates that there exists at least one bit where k is 1
and the corresponding bit in n is 0. In this case, it is impossible to modify a bit in n to make n equal to k, and
we return -1. 

Otherwise, we count the number of 1s the binary representation of n ^ k.
They are the bits are 1 in n and 0 in k
*/
function minChanges(n: number, k: number): number {
  return (n & k) !== k ? -1 : bitCount(n ^ k);
}

function bitCount(n: number): number {
  let count = 0;

  while (n !== 0) {
    count += n & 1; // Add the least significant bit
    n >>>= 1; // Logical right shift (fills with zeros)
  }

  return count;
}
