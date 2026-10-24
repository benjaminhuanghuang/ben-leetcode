/*
415. Add Strings

https://leetcode.com/problems/add-strings/

[Facebook][Google]
*/

function addStrings(num1: string, num2: string): string {
  let i = num1.length - 1;
  let j = num2.length - 1;
  let carry = 0;
  let res = "";

  while (i >= 0 || j >= 0) {
    if (i >= 0) {
      carry += parseInt(num1[i--]);
    }
    if (j >= 0) {
      carry += parseInt(num2[j--]);
    }
    res = (carry % 10).toString() + res;
    carry = Math.floor(carry / 10);
  }

  return carry !== 0 ? "1" + res : res;
}
