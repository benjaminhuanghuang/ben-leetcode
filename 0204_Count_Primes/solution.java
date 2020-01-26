package cn.huang.leetcode;

/*
    204. Count Primes

    Calculating Prime Numbers
        https://www.youtube.com/watch?v=TDGETBsPKjQ
 */
public class LC_0204_CountPrimes {
    public int countPrimes(int n) {
        if (n < 3)
            return 0;

        boolean[] vis = new boolean[n];
        for (int i = 2; i * i < n; i++) {
            if (vis[i]) continue;
            for (int j = i; j * i < n; j++)
                vis[i * j] = true;
        }
        int ans = 0;
        for (int i = 2; i < n; i++)
            if (!vis[i]) ans++;
        return ans;
    }
}
