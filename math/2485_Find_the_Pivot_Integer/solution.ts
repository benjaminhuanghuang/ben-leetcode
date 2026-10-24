/*
2485. Find the Pivot Integer

https://leetcode.com/problems/find-the-pivot-integer/description/
*/

/*

https://algo.monster/liteproblems/2485

the sum of all the integers from 1 to x (inclusive) is equal to the sum of all the integers from x to n (inclusive).
x * (x + 1) = n * (n + 1).
*/

function pivotInteger(n: number): number {
  const sumOfIntegers = Math.floor((n * (n + 1)) / 2);

  // Find the integer part of the square root of the sum.
  const integerRoot = Math.floor(Math.sqrt(sumOfIntegers));

  // Check if the square of the integer root is exactly equal to the sum of integers.
  // If it is, then 'integerRoot' is the pivot integer we're looking for.
  return integerRoot * integerRoot === sumOfIntegers ? integerRoot : -1;
}
