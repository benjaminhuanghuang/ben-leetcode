package cn.huang.leetcode;

import java.util.ArrayList;
import java.util.List;

/*
728. Self Dividing Numbers

 */
public class LC_0728_SelfDividingNumbers {
    public List<Integer> selfDividingNumbers(int left, int right) {
        List<Integer> res = new ArrayList<>();

        for (int i = left; i <= right; ++i) {
            if (check(i)) res.add(i);
        }
        return res;
    }

    private boolean check(int num) {
        int tmp = num;
        while (tmp > 0) {
            int digit = tmp % 10;
            if (digit == 0)
                return false;
            if (num % digit != 0)
                return false;
            tmp = tmp / 10;

        }
        return true;
    }
}
