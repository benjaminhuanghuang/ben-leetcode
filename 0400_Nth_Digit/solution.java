package cn.huang.leetcode;

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
public class LC_0400_NthDigit {
    /*
    这里有这样一个规律，从1到9，有9个只占1个位数的数字，数字个数为10 - 1 + 1；从10到99，有90个占2个位数的数字，数字个数为99 - 10 + 1
    1——9	   1	9-1+1 = 9	9*1=9
    10——99	   2	99-10+1=90	90*2=180
    100——999   3	999-100+1=900	900*3=2700

    https://www.youtube.com/watch?v=3aGHrMBfO1o
     */
    public int findNthDigit(int n) {
        // 该范围内所有实际数字都占用了digit个单数字
        int digit = 1;
        // 该范围之前的所有实际数字已经占用了totalDigit个单数字
        long totalDigit = 0;
        // 先查出区间范围
        while (true) {
            long top = totalDigit + digit * 9 * (long) Math.pow(10, digit - 1);
            if (n >= totalDigit && n <= top)
                break;
            totalDigit = top;
            digit++;
        }

        // 根据范围算出具体的值
        int start = (int) Math.pow(10, digit - 1);
        int ret = 0;
        totalDigit += 1;
        // 第n个digit在哪个具体的实际数字上
        int value = start + (n - (int) totalDigit) / digit;
        ret = Integer.toString((int) value).charAt((int) ((n - totalDigit) % digit)) - '0';
        return ret;
    }

    // https://www.youtube.com/watch?v=IvJuM8Dr9E8
    public int findNthDigit_2(int n)
    {
        // len   数字的长度, 1位数，2位数...
        // start 同样长度的数字的最小值 1, 10, 100
        // total 同样长度的数字有多少，9， 90，
        for(long len =1, start =1, total=9;;)
        {
            if(n <=len * total)
            {
                long num = (n -1)/ len + start;
                int ret = Integer.toString((int)num).charAt((n - 1) % (int)len) - '0';
                return ret;
            }
            else
            {
                n -= len * total;
                start *= 10;
                len ++;
                total = total * 10;
            }
        }
    }
}
