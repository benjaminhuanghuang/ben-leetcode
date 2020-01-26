package cn.huang.leetcode;

/*
482. License Key Formatting

 */
public class LC_0482_LicenseKeyFormatting {
    public String licenseKeyFormatting_TLE(String S, int K) {
        String res = "";
        int groupLen = K;
        for (int i = S.length() - 1; i >= 0; i--) {
            if (S.charAt(i) == '-')
                continue;

            if (groupLen > 0) {
                res = Character.toUpperCase(S.charAt(i)) + res;
                groupLen--;
            } else {
                res = Character.toUpperCase(S.charAt(i)) + "-" + res;
                groupLen = K-1;
            }
        }
        return res;
    }

    public String licenseKeyFormatting(String S, int K) {
        StringBuilder sb = new StringBuilder();
        int groupLen = K;
        for (int i = S.length() - 1; i >= 0; i--) {
            if (S.charAt(i) != '-') {
                if (groupLen > 0) {
                    sb.insert(0,S.charAt(i));
                    groupLen--;
                } else {
                    sb.insert(0,"-");
                    sb.insert(0,S.charAt(i));
                    groupLen = K - 1;
                }
            }
        }
        return sb.toString().toUpperCase();
    }

    public String licenseKeyFormatting_Better(String S, int K) {
        StringBuilder sb = new StringBuilder();
        for (int i = S.length() - 1; i >= 0; i--)
            if (S.charAt(i) != '-')
                sb.append(sb.length() % (K + 1) == K ? '-' : "").append(S.charAt(i));
        return sb.reverse().toString().toUpperCase();
    }
}
