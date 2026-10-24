public class Solution390 {
    // http://www.cnblogs.com/grandyang/p/5860706.html
    public int LastRemaining(int n) {
        return help(n, true);   
    }

    int help(int n, bool left2right) 
    {
        if (n == 1) return 1;
        // 如果n大于1，且是从左往右的话，我们返回2倍的对n/2的从右往左的遍历；
        // 如果是从右往左的话，稍稍麻烦一些，我们肯定还是要对n/2调用递归函数的，
        // 但是要分奇偶情况，如果n为奇数，返回2倍的对n/2的从左往右的遍历的值；
        //如果n为偶数，2倍的对n/2的从左往右的遍历的值，再减去1。
        if (left2right) 
        {
            return 2 * help(n / 2, false);
        } else 
        {
            return 2 * help(n / 2, true) - 1 + n % 2;
        }
    }
}