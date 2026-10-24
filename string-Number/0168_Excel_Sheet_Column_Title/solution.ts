/*
168. Excel Sheet Column Title

https://leetcode.com/problems/excel-sheet-column-title/
*/
/*
   对于小于26的数字, 只需要对26取余，然后减去1，加上字符A即可，
   对于26来说，如果还是这么做的话就会出现问题，因为对26取余是0，减去1后成为-1，加上字符A后，并不等于字符Z。
   所以对于能被26整除的数我们得分开处理:
   能整除26的，直接在结果res上加上字符Z，然后n自减去26；
   不能的话，就按照一般的处理，n要减去这个余数。之后n要自除以26，继续计算下去

   合并if和else，写的更简洁一些。
   用一个小trick，比如对于26来说，我们先让n自减1，变成25，然后再对26取余，得到25，此时再加上字符A，就可以得到字符Z了。
   这对其他的不能整除26的数也是成立的，
   https://www.cnblogs.com/grandyang/p/4227618.html
 */
function convertToTitle(columnNumber: number): string {
  let title = "";
  while (columnNumber > 0) {
    columnNumber--;
    title += String.fromCharCode((columnNumber % 26) + "A".charCodeAt(0));
    columnNumber = Math.floor(columnNumber / 26);
  }
  return title.split("").reverse().join("");
}
