/*
9. Palindrome Number
https://leetcode.com/problems/palindrome-number/
*/

/*
    This method involves reverting the second half of the number and comparing it to the first half 
    without converting it into a string.
*/
function isPalindrome(x: number): boolean {
  if (x < 0 || (x % 10 === 0 && x !== 0)) {
    return false;
  }

  let revertedNumber = 0;
  while (x > revertedNumber) {
    revertedNumber = revertedNumber * 10 + (x % 10);
    x = Math.floor(x / 10);
  }

  return x === revertedNumber || x === Math.floor(revertedNumber / 10);
}

export { isPalindrome };
