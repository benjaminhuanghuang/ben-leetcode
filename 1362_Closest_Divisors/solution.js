/*
1362. Closest Divisors

Level: Medium

https://leetcode.com/problems/closest-divisors
*/

/*
  Solution: 
*/

/**
 * @param {number} num
 * @return {number[]}
 */
var closestDivisors = function(num) {
    for(let i = Math.floor(Math.sqrt(num+2));i >=1; i--){
      if((num+1) % i ==0){
        return [(num+1)/i, i]
      }
      if((num+2) % i ==0){
        return [(num+2)/i, i]
      }
    }
};


export { closestDivisors };