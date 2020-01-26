package cn.huang.leetcode;

/*
    541. Reverse String II
    Given a string and an integer k, you need to reverse the first k characters for every 2k characters counting from
    the start of the string.
    If there are less than k characters left, reverse all of them.
    If there are less than 2k but greater than or equal to k characters, then reverse the first k characters and left the other as original.
 */
public class LC_0541_ReverseString_II {
    public String reverseStr(String s, int k) {
        char[] chars = s.toCharArray();
        int start = 0;
        int end = Math.min(k - 1, chars.length-1);
        while (start< chars.length & end < chars.length) {
            swap(chars, start, end);
            start = start + 2 * k;
            end = Math.min(end + 2*k,chars.length-1) ;
        }

        return String.valueOf(chars);
    }


    private void swap(char[] chars, int left, int right) {
        while (left < right) {
            char temp = chars[left];
            chars[left] = chars[right];
            chars[right] = temp;
            left++;
            right--;
        }
    }
}
