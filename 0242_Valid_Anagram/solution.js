/*
242. Valid Anagram

Level: Easy

https://leetcode.com/problems/valid-anagram
*/

/*
  Solution: 
*/

/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isAnagram = function (s, t) {
  if (s.length != t.length)
    return false;
  var Array = [];
  for (var k = 0; k < 26; k++) {
    Array[k] = 0;
  }
  const aCode = 'a'.charCodeAt(0)
  for (var i = 0; i < s.length; i++) {
    Array[(s.charCodeAt(i) - aCode)]++;
    Array[(t.charCodeAt(i) - aCode)]--;
  }
  for (var x = 0; x < 26; x++) {
    if (Array[x] !== 0) {
      return false;
    }
  }
  return true;
};

var isAnagram_sort = function (s, t) {
  return s.split('').sort().join('') === t.split('').sort().join('');
};


export { isAnagram };