package cn.huang.leetcode;

import java.util.HashMap;

public class LC_0860_LemonadeChange {
    public boolean lemonadeChange(int[] bills) {
        HashMap<Integer, Integer> billMap = new HashMap<>();
        billMap.put(5, 0);
        billMap.put(10, 0);
//        billMap.put(20, 0);
        for (int i = 0; i < bills.length; i++) {
            if (bills[i] == 10) {
                if (billMap.get(5) > 0) {
                    billMap.put(5, billMap.get(5) - 1);
                    billMap.put(10, billMap.get(10) + 1);
                } else {
                    return false;
                }
            }
            else if (bills[i] == 20) {
                if (billMap.get(10) > 0 && billMap.get(5) > 0) {
                    billMap.put(10, billMap.get(10) - 1);
                    billMap.put(5, billMap.get(5) - 1);
//                    billMap.put(20, billMap.get(20) + 1);
                } else if (billMap.get(5) >= 3) {
                    billMap.put(5, billMap.get(5) - 3);
//                    billMap.put(20, billMap.get(20) + 1);
                } else {
                    return false;
                }
            } else
                billMap.put(5, billMap.get(5) + 1);
        }

        return true;
    }

    public boolean lemonadeChange_Better(int[] bills) {
        int fiveBill = 0;
        int tenBill = 0;
        for (int i = 0; i < bills.length; i++) {
            if (bills[i] == 5) {
                fiveBill++;
            } else if (bills[i] == 10) {
                if (fiveBill <= 0)
                    return false;
                fiveBill--;
                tenBill++;
            } else if (bills[i] == 20) {
                if (tenBill > 0 && fiveBill > 0) {
                    tenBill--;
                    fiveBill--;
                } else if (fiveBill >= 3) {
                    fiveBill -= 3;
                }
                else
                    return false;
            }
        }

        return true;
    }
}
