package cn.huang.leetcode;

/*
670. Maximum Swap

 Given a non-negative integer, you could swap two digits at most once to get the maximum valued number.
 Return the maximum valued number you could get.

Example 1:

Input: 2736
Output: 7236
Explanation: Swap the number 2 and the number 7.

Example 2:

Input: 9973
Output: 9973
Explanation: No swap.

Note:

    The given number is in the range [0, 108]

 */
public class LC_0670_MaximumSwap {
    public int maximumSwap(int num) {
        if (num <= 10) {
            return num;
        }
        //转成字符串，更方便处理。
        char[] strArr = String.valueOf(num).toCharArray();
        char max = '0';
        int[] dp = new int[strArr.length];//dp[i]存储 i 后面的最大的数字。
        dp[strArr.length - 1] = strArr.length - 1;

        for (int i = strArr.length - 1; i >= 0; i--) {
            if (max < strArr[i]) { // 不选择等于。（只有比其大的数才有交换意义）
                max = strArr[i];
                dp[i] = i;
            } else {
                dp[i] = dp[i - 1];
            }
        }

        for (int i = 0; i < dp.length; i++) {
            if (dp[i] > i && strArr[i] != strArr[dp[i]]) {
                char tmp = strArr[i];
                strArr[i] = strArr[dp[i]];
                strArr[dp[i]] = tmp;
                break; //忘记加，导致bug.
            }
        }
        return Integer.valueOf(new String(strArr));
    }
    /*
    https://blog.csdn.net/magicbean2/article/details/79203146
    如果我们从后往前扫描，则只需要进行一遍扫描：记录一个截止当前的最大值和其对应位置，再记录一下当前参与交换的两个数的值和对应位置。
    扫描的过程中，如果遇到比最大值还大的数出现，则更新最大值及其对应位置；否则如果发现当前数比截止当前的最大值小，
    那么就更新swap为当前数和当前最大数之间的swap。这样最终结果就是最佳的swap。算法的空间复杂度是O(n)，时间复杂度也是O(n)。
     */
    int maximumSwap2(int num) {
        String s = num + "";
        int length = s.length();
        int max_index = -1, max_digit = -1;
        int left_index = -1, right_index = -1;
        for (int i = length - 1; i >= 0; --i) {
            if (s.charAt(i) > max_digit) {     // found the largest num so far
                max_digit = s.charAt(i);
                max_index = i;
                continue;
            }
            if (s.charAt(i) < max_digit) {
                left_index = i;
                right_index = max_index;
            }
        }
        if (left_index == -1) {
            return num;
        }
        s = swap(s, left_index, right_index);
        return Integer.parseInt(s);
    }

    private String swap(String str, int left, int right) {
        char[] charArray = str.toCharArray();
        char tmp = charArray[left];
        charArray[left] = charArray[right];
        charArray[right] = tmp;
        return String.valueOf(charArray);
    }
}
