/*
202. Happy Number

https://leetcode.com/problems/happy-number/

 A happy number is a number defined by the following process:
  Starting with any positive integer, replace the number by the sum of the squares of its digits,
  and repeat the process until the number equals 1 (where it will stay),
  or it loops endlessly in a cycle which does not include 1.
  Those numbers for which this process ends in 1 are happy numbers.
 
*/

function isHappy(n: number): boolean {
  const visited: { [key: number]: boolean } = {};
  let number = n;

  while (!visited[number]) {
    visited[number] = true;
    let start = number;
    number = 0;

    while (start !== 0) {
      const digit = start % 10;
      number += digit * digit; // number = the sum of the squares of start's digits
      start = Math.floor(start / 10);
    }

    if (number === 1) {
      return true;
    }
  }

  return false;
}
