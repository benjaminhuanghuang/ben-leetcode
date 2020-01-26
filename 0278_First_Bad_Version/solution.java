package cn.huang.leetcode;

/*
    278. First Bad Version

 */
public class LC_0278_FirstBadVersion {
    public int firstBadVersion(int n) {
        int start = 1;
        int end = n;

        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (isBadVersion(mid)) {
                end = mid;
            } else {
                start = mid;
            }
        }
        if (isBadVersion(start))
            return start;

        return end;
    }
    /*
    can not pass 2147483647, 2147483647
     */
    public int firstBadVersion_huahua(int n) {
        int start = 1;
        int end = n + 1;

        while (start < end) {
            int mid = start + (end - start) / 2;
            if (isBadVersion(mid)) {
                end = mid;
            } else {
                start = mid + 1;
            }
        }

        return start;
    }

    boolean isBadVersion(int version) {
        return false;
    }
}
