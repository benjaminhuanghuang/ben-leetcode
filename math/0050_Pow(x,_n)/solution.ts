/*
50. Pow(x, n)

https://leetcode.com/problems/powx-n/

x to the power of n
*/

/*


*/
function myPow(x: number, n: number): number {
  // Note: n can be negative
  return n >= 0 ? myPowImp(x, n) : 1.0 / myPowImp(x, -n);
}

// x^n = x^(n/2)*x^(n/2)*x^(n%2)
function myPowImp(x: number, n: number): number {
  if (n === 0) {
    return 1;
  }
  const half = myPowImp(x, Math.floor(n / 2));
  const result = half * half * (n % 2 === 0 ? 1 : x);
  return result;
}
