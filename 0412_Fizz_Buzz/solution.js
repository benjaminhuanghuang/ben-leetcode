/*
412. Fizz Buzz

Level: Easy

https://leetcode.com/problems/fizz-buzz
*/

/*
  Solution: 
*/

/**
 * @param {number} n
 * @return {string[]}
 */
var fizzBuzz = function (n) {
  var arr = [];
  for (i = 1; i <= n; i++) {
    if (i % 15 === 0){
      arr.push('FizzBuzz');
    } else if (i % 5 === 0) {
      arr.push('Buzz');
    } else if (i % 3 === 0) {
      arr.push('Fizz');
    } else {
      arr.push(i.toString());
    }
  }
  return arr
};


var fizzBuzz = function (n) {
  var arr = new Array(n);
  for (i = 1; i <= n; i++) {
    if (i % 15 === 0){
      arr[i-1] = 'FizzBuzz';
    } else if (i % 5 === 0) {
      arr[i-1]='Buzz';
    } else if (i % 3 === 0) {
      arr[i-1]='Fizz';
    } else {
      arr[i-1]= i.toString();
    }
  }
  return arr
};


export { fizzBuzz };