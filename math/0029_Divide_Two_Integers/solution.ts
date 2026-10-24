/*
29. Divide Two Integers

https://leetcode.com/problems/divide-two-integers/
*/

function divide(dividend: number, divisor: number): number {
  const INT_MAX = 2147483647; // 2^31 - 1
  const INT_MIN = -2147483648; // -2^31

  if (divisor === 0) return INT_MAX;
  if (dividend === INT_MIN && divisor === -1) return INT_MAX; // special case to prevent overflow

  const isPositive =
    (dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0);

  let dividendL = Math.abs(dividend);
  let divisorL = Math.abs(divisor);

  let result = 0;

  while (dividendL >= divisorL) {
    let multiple = 1;
    let start = divisorL;

    // / //用除数每次*2（向左移动一位）去逼近被除数，被除数减去新的除数如此循环。
    // Use left shift to double the divisor and approach the dividend
    while (start << 1 <= dividendL) {
      start <<= 1;
      multiple <<= 1;
    }
    dividendL -= start;
    result += multiple;
  }

  if (isPositive) {
    return Math.min(result, INT_MAX);
  } else {
    return Math.max(-result, INT_MIN);
  }
}
