package cn.huang.leetcode;

/*
717. 1-bit and 2-bit Characters
We have two special characters. The first character can be represented by one bit 0. The second character can be
represented by two bits (10 or 11).

Now given a string represented by several bits. Return whether the last character must be a one-bit character or not.
The given string will always end with a zero.
 */
public class LC_0717_1bitand2bitCharacters {
    /*
    题目的意思是要判断最后一个0元素是属于0还是输入10；
    遍历数组，给定指针，若当前位为1则指针+2；若当前位为0，则指针+1；
    判断最后指针是否与bits.length-1相等，相等则为真，否则为假；其中length=1的情况也包括进去了。
     */
    public boolean isOneBitCharacter(int[] bits) {
        int i = 0;
        while (i < bits.length - 1) {
            if (bits[i] == 1) {
                i += 2;
            } else {
                i++;
            }
        }
        return i == bits.length - 1;
    }
}
