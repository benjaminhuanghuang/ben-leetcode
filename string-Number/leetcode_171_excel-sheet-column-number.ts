/*
171. Excel Sheet Column Number

https://leetcode.com/problems/excel-sheet-column-number/
*/
/*
     26进制转10进制, 1 to 26 对应 A to Z 
     Use charCodeAt to get the ASCII value of the character
*/
function titleToNumber(columnTitle: string): number {
  let result = 0;
  for (let i = 0; i < columnTitle.length; i++) {
    result = result * 26 + columnTitle.charCodeAt(i) - "A".charCodeAt(0) + 1;
  }
  return result;
}
