/*
233. Number of Digit One

Given an integer n, count the total number of digit 1 appearing in all non-negative integers 
less than or equal to n.

For example:
Given n = 13,
Return 6, because digit 1 occurred in the following numbers: 1, 10, 11, 12, 13.
*/

public class Solution233 {
    public int CountDigitOne(int n) {
        int sum=0;
        for(long m =1; m<=n; m*=10)
        {
            /**得到包含当前位和之前位的数*/
            int a=(int) (n/m);
            /**如果当前位大于等于2，则总数为a/10+1*/
            int x=(int) ((a+8)/10*m);
            int y=0;
            /**付过当前位等于1，则需要考虑位数比他小的。如果当前数为0，就不需要考虑*/
            if(a%10==1)
            {
                y=(int)(n%m)+1;
            }
            
            sum+=x;
            sum+=y;
        }
        return sum;
    }
}