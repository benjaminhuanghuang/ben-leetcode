/*
258. Add Digits

Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.

For example:

Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it.

Follow up:
Could you do it without any loop/recursion in O(1) runtime?

Hints
    A naive implementation of the above process is trivial. Could you come up with other methods?
    What are all the possible results?
    How do they occur, periodically or randomly?
    You may find this Wikipedia article useful.
*/

public class Solution258 {

    public int AddDigits_Finnal(int num) {
        if (num == 0)
            return 0;
            
        return (num - 1) % 9 + 1;
    }

    public int AddDigits(int num) {
        int next = this.GetNext( num);
        while(next > 10)
        {
            next = this.GetNext(next);            
        }
        return next;
    }

    //  Sum of digits
    private int GetNext(int num) {
        string s = num.ToString();
        int sum = 0;
        foreach(var c in s) {
            sum += c - '0';
        }
        return sum;
    }
    private int GetNext2(int num) {
        int sum = 0;
        while (num / 10 >0)
        {
            sum += num %10;
            num = num / 10;
        }
        sum += num;
        return sum;
    }

}