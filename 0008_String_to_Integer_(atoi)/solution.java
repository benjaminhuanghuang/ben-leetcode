package cn.huang.leetcode;
/*
8. String to Integer (atoi)

 */

public class LC_0008_StringtoInteger {
    /*
    几个关键点：1.正负号；2.中间存在字母（只取字母前的数字）;3.溢出;4.前后空格

     */
    public int myAtoi(String str) {
        if (str == null || str.trim().length() < 1)
            return 0;

        //处理掉前后空格
        char[] arr = str.trim().toCharArray();

        int sign = 1, index = 0;
        //判断正负号
        if (arr[0] == '+')
            index++;
        if (arr[0] == '-') {
            sign = -1;
            index++;
        }

        int num = 0;
        for (int i = index; i < arr.length; i++) {
            if (arr[i] - '0' >= 0 && arr[i] - '9' <= 0) {
                //如果当前运算会越界的时候，直接输出结果
                //Integer.Min_VALUE=-2147483648 . Integer.MAX_VALUE=2147483647
                if (num > Integer.MAX_VALUE / 10 || num == Integer.MAX_VALUE / 10 && arr[i] - '7' > 0) {
                    if (sign > 0)
                        return Integer.MAX_VALUE;
                    else
                        return Integer.MIN_VALUE;
                }

                num = 10 * num + arr[i] - '0';
            } else
                //如果是字母，跳出循环
                break;
        }

        return num * sign;
    }

    public int atoi_easyer(String str) {
        if (str == null || str.trim().length() < 1)
            return 0;

        // trim white spaces
        str = str.trim();

        char flag = '+';

        // check negative or positive
        int i = 0;
        if (str.charAt(0) == '-') {
            flag = '-';
            i++;
        } else if (str.charAt(0) == '+') {
            i++;
        }
        // use double to store result
        double result = 0;

        // calculate value
        while (str.length() > i && str.charAt(i) >= '0' && str.charAt(i) <= '9') {
            result = result * 10 + (str.charAt(i) - '0');
            i++;
        }

        if (flag == '-')
            result = -result;

        // handle max and min
        if (result > Integer.MAX_VALUE)
            return Integer.MAX_VALUE;

        if (result < Integer.MIN_VALUE)
            return Integer.MIN_VALUE;

        return (int) result;
    }
}
