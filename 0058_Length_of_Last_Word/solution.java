package cn.huang.leetcode;

public class LC_0058_LengthLastWord {
    public int lengthOfLastWord(String s) {
        if (s == null || s.length() == 0)
            return 0;
        int length = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            char c = s.charAt(i);
            if (c == ' ' && length == 0)
                continue;
            else if (c == ' ' && length > 0)
                break;
            else if (c != ' ')
                length++;
        }

        return length;
    }

}
