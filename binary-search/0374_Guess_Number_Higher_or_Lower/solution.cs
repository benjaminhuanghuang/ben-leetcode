public class Solution374 {
    // Much better than using Dictionary.
    public int GuessNumber(int n) {
        int low = 1;
        int high = n;

        while(low <= high)
        {
            int mid = low + (high - low)/2;
            if (guess(mid)==1)
                low = mid + 1;
            else
                high = mid;
        }
        return low;
    }

    private int guess(int n)
    {
        if (n == 2)
            return 0;
        if (n > 2)
            return -1;
        return 1;
    }
}