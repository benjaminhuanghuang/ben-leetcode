package cn.huang.leetcode;

/*
    69. Sqrt(x)
 */
public class LC_0069_Sqrtx {

    public int mySqrt_brute_force(int x) {
        if (x <= 1)
            return x;
        for (int s = 1; s <= x; s++) {
            if (s * s > x)
                return x - 1;
        }
        return -1;
    }

    public int mySqrt(int x) {
        int start = 0;
        int end = x;

        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            // 不要写成middle*middle==x，when x is very big 会溢出
            if (mid == x / mid) {
                return mid;
            } else if (mid < x / mid) {
                start = mid;
            } else {
                end = mid;
            }
        }
        if (end * end == x) {
            return end;
        }
        return start;
    }

    public int mySqrt2(int x) {
        int start = 1;
        int end = x;

        while (start <= end) {
            int mid = start + (end - start) / 2;
            // 不要写成middle*middle==x，when x is very big 会溢出
            if (mid > x / mid)
                end = mid - 1;
            else
                start = mid + 1;
        }

        return end;
    }
}