/*
172. Factorial Trailing Zeroes

https://leetcode.com/problems/factorial-trailing-zeroes/

Given an integer n, return the number of trailing zeroes in n!
*/

/* n! = 1*2*3*4... *n
    The number of trailing 0 = the count of 2*5 pair
    也就是要找乘数中10的个数，而10可分解为2和5，而我们可知2的数量又远大于5的数量，那么此题即便为找出5的个数。
    仍需注意的一点就是，像25,125，这样的不只含有一个5的数字需要考虑进去。
 */
function trailingZeroes(n: number): number {
  let count = 0;

  while (n > 0) {
    n = Math.floor(n / 5);
    count += n;
  }
  return count;
}
