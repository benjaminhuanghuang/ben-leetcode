package cn.huang.leetcode;

/*
    557. Reverse Words in a String III

 */
public class LC_0557_ReverseWordsinaString_III {
    public String reverseWords(String s) {
        String[] strs = s.split(" ");
        String result = "";
        int len = strs.length;
        for (int i = 0; i < len - 1; i++)
            result += reverse(strs[i]) + " ";
        result += reverse(strs[len - 1]);
        return result;
    }

    public String reverse(String str) {
        String result = "";
        int len = str.length();
        for (int i = 0; i < len; i++)
            result = str.charAt(i) + result;
        return result;
    }


    public String reverseWords_2(String s) {

        char[] chars = s.toCharArray();

        int start = 0;
        int end = 0;
        while (end < s.length()) {
            while (end < s.length() && chars[end] != ' ') {
                end++;
            }
            swap(chars, start, end - 1);

            end++;
            start = end;
        }
        return String.valueOf(chars);
    }

    private void swap(char[] chars, int left, int right) {
        while (left < right) {
            char tmp = chars[left];
            chars[left] = chars[right];
            chars[right] = tmp;
            left++;
            right--;
        }
    }
}
