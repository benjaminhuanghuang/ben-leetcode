public class Solution367 {
    public bool IsPerfectSquare(int num) {
        if (num < 1)
            return false;
        if (num == 1)
            return true;

        long left = 0;
        long right = num/2;
        while (left <= right)
        {
            long mid = left + ((right - left) >> 1);
            long val = mid * mid;
            if (val == num)
                return true;
            else if (val > num)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return false;
    }
}