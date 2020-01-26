package cn.huang.leetcode;

/*
    67. Add Binary
 */
public class LC_0067_AddBinary {
    public String addBinary(String a, String b) {
        String ans = "";

        int indexA = a.length() - 1;
        int indexB = b.length() - 1;
        int carry = 0;
        while (indexA >= 0 || indexB >= 0) {
            int valA = indexA >= 0 ? a.charAt(indexA--) - '0' : 0;
            int valB = indexB >= 0 ? b.charAt(indexB--) - '0' : 0;
            int sum = valA + valB + carry;
            ans = (sum % 2) + ans;
            carry = sum / 2;
        }
        return carry == 1 ? "1" + ans : ans;
    }
}
