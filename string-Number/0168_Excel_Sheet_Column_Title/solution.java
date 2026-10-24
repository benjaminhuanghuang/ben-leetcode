package cn.huang.leetcode;

public class LC_0168_ExcelSheetColTitle {
    public String convertToTitle(int n) {
        StringBuilder sb = new StringBuilder();
        while (n > 0) {
            int d = (n - 1) % 26;
            sb.insert(0, (char) ('A' + d));
            n = (n - 1) / 26;
        }

        return sb.toString();
    }
}
