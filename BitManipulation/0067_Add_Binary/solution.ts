/*
67. Add Binary

https://leetcode.com/problems/add-binary/
*/

/*
https://algo.monster/liteproblems/67
*/
function addBinary(a: string, b: string): string {
  // Initialize indices for the last characters of strings `a` and `b`
  let indexA = a.length - 1;
  let indexB = b.length - 1;
  // Initialize an array to store the result in reverse order
  let result: number[] = [];
  let carry = 0; // This will hold the carry-over for binary addition

  // Loop until both strings are traversed or carry is non-zero
  while (indexA >= 0 || indexB >= 0 || carry > 0) {
    // If indexA is valid, add corresponding digit from 'a' to carry
    if (indexA >= 0) {
      carry += a[indexA].charCodeAt(0) - "0".charCodeAt(0);
      indexA--;
    }
    // If indexB is valid, add corresponding digit from 'b' to carry
    if (indexB >= 0) {
      carry += b[indexB].charCodeAt(0) - "0".charCodeAt(0);
      indexB--;
    }

    // The binary digit is carry % 2, add to result
    result.push(carry % 2);
    // Update carry for next iteration: divide by 2 and floor
    carry = Math.floor(carry / 2);
  }

  // Since we stored the result in reverse, reverse it back to get the actual result
  return result.reverse().join("");
}
