package cn.huang.leetcode;
/*
258. Add Digits
 */
public class LC_0258_AddDigits {
    //叫做Digital Root，其解就是f(n) = 1 + (n - 1) % 9。
    public int addDigits(int num) {
        if(num==0)
            return 0;
        else if(num%9==0)
            return 9;
        else
            return num%9;
    }
    public int addDigits1(int num) {
        while (num / 10 > 0) {
            int result = 0;
            int temp = num;

            while (temp != 0) {
                result += (temp % 10);
                temp /= 10;
            }

            num = result;
        }
        return num;
    }
    public int addDights2(int num) {
        while (num >= 10) {
            num = num/10 + num % 10;
        }
        return num;
    }
}
