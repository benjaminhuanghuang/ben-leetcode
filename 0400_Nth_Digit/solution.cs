/*
400. Nth Digit

Find the nth digit of the infinite integer sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...

Note:
n is positive and will fit within the range of a 32-bit signed integer (n < 231).

Example 1:

Input:
3

Output:
3
Example 2:

Input:
11

Output:
0
Explanation:
The 11th digit of the sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... is a 0, which is part of the number 10.
*/


public class Solution400 {
    // 1 - 9  : 9
    // 10 - 99 : 90 * 2
    // 100 - 999 : 900 * 3
    // 1000 - 9999 : 9000 * 4
    // For example given n is 1000, we first -9 and then -180. The left is 811. 
    // The number is 100+810/3=370. The digit is the (810%3=0)th. Therefore, the digit is 3.
    public int FindNthDigit(int n) {
        long start=1,  len=1,  count=9;
        //start用来记录当前循环区间的第一个数字
        //len记录当前循环区间数字的位数 
        while(n > len*count){
            n = (int)(n-len*count);
            len++;
            count = count*10;
            start = start*10;
        }
        //当n落到某一个确定的区间里了，那么(n-1)/len就是目标数字在该区间里的坐标，加上start就是得到了目标数字，
        // 然后我们将目标数字start转为字符串，(n-1)%len就是所要求的目标
        start += (n - 1) / len;
        string t = start.ToString();
        return t[(n - 1) % (int)len] - '0';
    }
}