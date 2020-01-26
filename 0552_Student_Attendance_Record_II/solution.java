package cn.huang.leetcode;

/*
552. Student Attendance Record II

Given a positive integer n, return the number of all possible attendance records with length n, which will be
regarded as rewardable. The answer may be very large, return it after mod 109 + 7.

A student attendance record is a string that only contains the following three characters:

    'A' : Absent.
    'L' : Late.
    'P' : Present.

A record is regarded as rewardable if it doesn't contain more than one 'A' (absent) or more than two continuous 'L' (late).

Example 1:

Input: n = 2
Output: 8
Explanation:
There are 8 records with length 2 will be regarded as rewardable:
"PP" , "AP", "PA", "LP", "PL", "AL", "LA", "LL"
Only "AA" won't be regarded as rewardable owing to more than one absent times.

 */
public class LC_0552_StudentAttendanceRecord_II {
    /*
    https://zxi.mytechroad.com/blog/dynamic-programming/leetcode-552-student-attendance-record-ii/
    http://bookshadow.com/weblog/2017/04/16/leetcode-student-attendance-record-ii/
     */
    private final int MOD = 1000000007;

    public long sum(int[] nums) {
        long ans = 0;
        for (int n : nums) ans += n;
        return ans % MOD;
    }

    public int checkRecord(int n) {
        int dp[][] = {{1, 1, 0}, {1, 0, 0}};
        for (int i = 2; i <= n; i++) {
            int ndp[][] = {{0, 0, 0}, {0, 0, 0}};
            ndp[0][0] = (int) sum(dp[0]);
            ndp[0][1] = dp[0][0];
            ndp[0][2] = dp[0][1];
            ndp[1][0] = (int) ((sum(dp[0]) + sum(dp[1])) % MOD);
            ndp[1][1] = dp[1][0];
            ndp[1][2] = dp[1][1];
            dp = ndp;
        }
        return (int) ((sum(dp[0]) + sum(dp[1])) % MOD);
    }
}
