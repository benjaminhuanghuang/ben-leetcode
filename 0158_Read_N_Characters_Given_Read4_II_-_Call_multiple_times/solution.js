/*
  158. Read N Characters Given Read4 II
  
  Hard

  https://leetcode.com/problems/read-n-characters-given-read4-ii-call-multiple-times/

*/

/*
  https://www.youtube.com/watch?v=BXlwbVMXlrw&t=0s&ab_channel=CatRacketCode-LeetCodeJavaScript

  read buffer 经典做法
*/
var solution = function (read4) {
  let iBuf = [];

  return function (buf, n) {
    let count = 0;

    while (n > 0) {
      if (iBuf.length == 0) {
        if (read4(iBuf) == 0) {
          return count;
        }
        buf.push(iBuf.shift());
        count++;
        n--;
      }
    }
  };
};
