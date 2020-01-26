package cn.huang.leetcode;

import java.util.HashMap;
import java.util.Map;

/*
    551. Student Attendance Record I
 */
public class LC_0551_StudentAttendanceRecord_I {
    public boolean checkRecord(String s) {
        Map<Character, Integer> dict = new HashMap<>();
        dict.put('L', 0);
        dict.put('A', 0);
        dict.put('P', 0);
        for (Character c : s.toCharArray()) {
            int n = dict.get(c);
            if(c=='A'&& n ==1)
                return false;
            if(c=='L' && n ==2)
                return false;
            if(c != 'L')
                dict.put('L', 0);
            dict.put(c, n + 1);
        }
        return true;
    }
}
