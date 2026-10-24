using System;

public class Solution319 {
    //可以看出一个数只有被操作奇数次，最终才会亮。
    // 如果n可以分解为a*b，那么在第ａ轮和第ｂ也会被各操作一次。
    // 但是当n = k * k时，只会被操作一次，因此可以知道只有当ｎ可以被分解为一个数的平方的时候才会出现奇数次操作，最终才会保持亮。
    public int BulbSwitch(int n) {
        return (int)Math.Sqrt(n);
    }
}