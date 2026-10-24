public class Solution400 {
    // 1 - 9  : 9
    // 10 - 99 : 90 * 2
    // 100 - 999 : 900 * 3
    // 1000 - 9999 : 9000 * 4
    // For example given n is 1000, we first -9 and then -180. The left is 811. 
    // The number is 100+810/3=370. The digit is the (810%3=0)th. Therefore, the digit is 3.
    public int FindNthDigit(int n) {
        long start=1,  len=1,  count=9;
        //start用来记录当前循环区间的第一个数字
        //len记录当前循环区间数字的位数 
        while(n > len*count){
            n = (int)(n-len*count);
            len++;
            count = count*10;
            start = start*10;
        }
        //当n落到某一个确定的区间里了，那么(n-1)/len就是目标数字在该区间里的坐标，加上start就是得到了目标数字，
        // 然后我们将目标数字start转为字符串，(n-1)%len就是所要求的目标
        start += (n - 1) / len;
        string t = start.ToString();
        return t[(n - 1) % (int)len] - '0';
    }
}