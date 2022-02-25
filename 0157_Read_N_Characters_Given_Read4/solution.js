/*
  157. Read N Characters Given Read4
  
  Easy

  https://leetcode.com/problems/read-n-characters-given-read4/

*/

/*
  https://www.youtube.com/watch?v=BXlwbVMXlrw&t=0s&ab_channel=CatRacketCode-LeetCodeJavaScript

  read buffer 经典做法
*/
var solution = function (read4) {
  return function (buf, n) {
    let tmp = [];
    let total = 0;
    let eof = false;

    while (!eof && total < n) {
      // read data to tmp
      let count = read4(tmp);
      eof = count < 4;
      count = Math.main(count, n - total);
      for (let i = 0; i < count; i++) {
        buf[total++] = tmp[i];
      }
    }
    return total;
  };
};
