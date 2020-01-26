package cn.huang.leetcode;

/*
858. Mirror Reflection

There is a special square room with mirrors on each of the four walls.
Except for the southwest corner, there are receptors on each of the remaining corners, numbered 0, 1, and 2.

The square room has walls of length p, and a laser ray from the southwest corner first meets the east wall at a distance q from the 0th receptor.

Return the number of the receptor that the ray meets first.  (It is guaranteed that the ray will meet a receptor eventually.)



Example 1:

Input: p = 2, q = 1
Output: 2
Explanation: The ray meets receptor 2 the first time it gets reflected back to the left wall.


Note:

    1 <= p <= 1000
    0 <= q <= p


 */
public class LC_0858_MirrorReflection
{
    /*
    https://buptwc.com/2018/06/26/Leetcode-858-Mirror-Reflection/
     */
    public int mirrorReflection(int p, int q) {
        // 先找到第一个横坐标为p的倍数的点
        int k = 1;
        int r = 0;
        while (p*k % q != 0)
            k += 1;
        // 若为x的偶数倍
        if (k  % 2 == 0)
            return 0;
        else
        	// 分别判断p的奇数倍和偶数倍
            r = p*k / q;
        if(r % 2 == 1)
            return 1;
        else
            return 2;
    }

}
