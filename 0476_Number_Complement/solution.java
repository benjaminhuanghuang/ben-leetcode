package cn.huang.leetcode;

/*
476. Number Complement

 */
public class LC_0476_NumberComplement {
    //5的二进制是101，我们的构造的掩码为mask=111，两者异或则为010，即是所要的结果。
    public int findComplement(int num) {
        int maskCreater = 1, temp = num;
        while (temp > 0) {
            maskCreater = maskCreater << 1;
            temp = temp >> 1;
        }
        int mask = maskCreater - 1;
        return num ^ (mask);
    }

    public int findComplement2(int num) {
        int res = ((Integer.highestOneBit(num) - 1) << 1) + 1;
        return res ^ num;
    }
}
