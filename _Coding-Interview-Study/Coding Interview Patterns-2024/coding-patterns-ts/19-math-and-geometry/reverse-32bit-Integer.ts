function reverse32BitInteger(n: number): number {
  const INT_MAX = Math.pow(2, 31) - 1;
  const INT_MIN = -Math.pow(2, 31);

  let reversedN = 0;

  // Keep looping until we've added all digits of 'n' to 'reversedN'
  // in reverse order.
  while (n !== 0) {
    const digit = Math.trunc(n % 10);
    n = Math.trunc(n / 10);

    // Check for integer overflow or underflow.
    if (
      reversedN > Math.trunc(INT_MAX / 10) ||
      reversedN < Math.trunc(INT_MIN / 10)
    ) {
      return 0;
    }

    // Add the current digit to 'reversedN'.
    reversedN = reversedN * 10 + digit;
  }

  return reversedN;
}
