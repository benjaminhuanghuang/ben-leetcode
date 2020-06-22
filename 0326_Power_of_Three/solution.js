/*
326. Power of Three

Level: Easy

https://leetcode.com/problems/power-of-three

- 342. Power of Four

*/

/*
  Solution: 
*/

/**
 * @param {number} n
 * @return {boolean}
 */
var isPowerOfThree = function(n) {
    if(n < 1)
      return false;

    while(n % 3 == 0)
    {
      n /= 3;
    }
    return n ==1;
};


export { twoSum };