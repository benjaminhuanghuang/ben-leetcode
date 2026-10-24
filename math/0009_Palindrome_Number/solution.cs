public class Solution009 {
    public bool IsPalindrome(int x) {
        if (x < 0)
        {
            return false;
        }
        int tmp = x;
        int revert = 0;
        while(tmp>0)
        {
            revert = revert * 10 + tmp % 10;
            tmp = tmp / 10;
        }
        return revert == x;
    }
}