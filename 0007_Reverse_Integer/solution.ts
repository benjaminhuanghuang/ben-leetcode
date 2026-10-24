/*
Build the result digit by digit (% and / work with the sign in JS, so no
separate sign handling is needed). Bail out and return 0 as soon as the
result would overflow a 32-bit signed integer.

Time complexity: O(log x), one iteration per digit
Space complexity: O(1)
*/
function reverse(x: number): number {
  const INT_MAX = 2 ** 31 - 1;
  const INT_MIN = -(2 ** 31);

  let result = 0;
  let n = x;

  while (n !== 0) {
    const digit = n % 10;
    n = Math.trunc(n / 10);
    result = result * 10 + digit;

    if (result > INT_MAX || result < INT_MIN) {
      return 0;
    }
  }

  return result;
}

export {};
