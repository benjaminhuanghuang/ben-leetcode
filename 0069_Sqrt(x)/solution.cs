/*
69. Sqrt(x)

Implement int sqrt(int x).

Compute and return the square root of x.
*/

public class Solution069 {
    public int MySqrt(int x) {
        var res = 0;
        var low = 1;
        var high = x;

        while (low <= high)
        {
            var mid = (high - low) / 2 + low;

            if (mid == x / mid)
            {
                res = mid;
                break;
            }
            else if( mid < x / mid)  // mid * mid < x,  mid is too small
            {   // Can not use (mid * mid < x) , when x is very big
                res = mid;    // importent! for x = 2
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return res;   
    }
}