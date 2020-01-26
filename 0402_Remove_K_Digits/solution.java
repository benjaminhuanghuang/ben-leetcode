package cn.huang.leetcode;
/*
402. Remove K Digits
Given a non-negative integer num represented as a string, remove k digits from the number so that the new number
is the smallest possible.

Note:

    The length of num is less than 10002 and will be ≥ k.
    The given num does not contain any leading zero.

Example 1:

Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.

Example 2:

Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.

Example 3:

Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.

 */
public class LC_0402_RemoveKDigits {
    /*
    如果n是num的长度，我们要去除k个，那么需要剩下n-k个，我们开始遍历给定数字num的每一位，对于当前遍历到的数字c，进行如下while循环，
    如果res不为空，且k大于0，且res的最后一位大于c，那么我们应该将res的最后一位移去，且k自减1。当跳出while循环后，我们将c加入res中，
    最后我们将res的大小重设为n-k。根据题目中的描述，可能会出现"0200"这样不符合要求的情况，所以我们用一个while循环来去掉前面的所有0，
    然后返回时判断是否为空，为空则返回“0”，

    https://www.cnblogs.com/Dylan-Java-NYC/p/8327380.html
     */
    public String removeKdigits(String num, int k) {
        if(num == null || num.length() == 0){
            return num;
        }

        int len = num.length();
        int remainDigits = len-k;
        char [] stk = new char[len];
        int top = 0;
        for(int i = 0; i<len; i++){
            char c = num.charAt(i);
            while(top>0 && c<stk[top-1] && k>0){
                top--;
                k--;
            }

            stk[top++] = c;
        }

        // 找到第一个不为0的index
        int ind = 0;
        while(ind<remainDigits && stk[ind]=='0'){
            ind++;
        }
        return ind == remainDigits ? "0" : new String(stk, ind, remainDigits-ind);
    }
}
