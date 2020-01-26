package cn.huang.leetcode;

public class LC_0917_ReverseOnlyLetters {
    public String reverseOnlyLetters_fast(String S) {
        if (S == null) return null;
        if (S.length() == 0) return "";

        char[] charArray = S.toCharArray();

        int left = 0;
        int right = S.length() - 1;
        while (left < right) {
            while (left < S.length() && !isLetter(charArray[left]))
                left++;
            while (right > 0 && !isLetter(charArray[right]))
                right--;

            if(left < right)
            {
                char tmp = charArray[right];
                charArray[right] = charArray[left];
                charArray[left] = tmp;
                left++;
                right--;
            }
        }

        return String.valueOf(charArray);
    }

    private boolean isLetter(char c) {
        return ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z');
    }


    public String reverseOnlyLetters(String S) {
        if (S == null) return null;
        if (S.length() == 0) return "";

        char[] charArray = S.toCharArray();

        int left = 0;
        int right = S.length() - 1;
        while (left < right) {
            // Ignore special characters
            if (!Character.isAlphabetic(charArray[left]))
                left++;
            else if(!Character.isAlphabetic(charArray[right]))
                right--;
            // Both str[l] and str[r] are not spacial
            else
            {
                char tmp = charArray[left];
                charArray[left] = charArray[right];
                charArray[right] = tmp;
                left++;
                right--;
            }
        }

        return String.valueOf(charArray);
    }
}
