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
