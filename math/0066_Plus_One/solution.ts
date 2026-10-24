/*
66. Plus One

https://leetcode.com/problems/plus-one/
*/

function plusOne(digits: number[]): number[] {
  let carry = 1; // add the 1 to the carry in the beginning

  for (let i = digits.length - 1; i >= 0; i--) {
    let sum = digits[i] + carry;
    digits[i] = sum % 10;
    carry = Math.floor(sum / 10);
  }

  if (carry > 0) {
    digits.unshift(carry);
  }
  return digits;
}
