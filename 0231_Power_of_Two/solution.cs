/*
231. Power of Two
Given an integer, write a function to determine if it is a power of two.

*/

public class Solution231
{
    // The power of 2 only have one "1" ant most left bit
    public bool IsPowerOfTwo(int n)
    {
        int countOfOne = 0;
        while (n > 0)
        {
            countOfOne += n & 1;
            n >>= 1;
        }
        return countOfOne == 1;
    }

    public bool IsPowerOfTwo_32(int n)
    {
        if (n <= 0)
            return false;
        int countOfOne = 0;
        for (int i = 0; i < 32; i++)
        {
            if ((n & 1) == 1)
            {
                countOfOne++;
            }
            n = n >> 1;
        }
        return countOfOne == 1;
    }
    // The power of 2 only have one "1" ant most left bit
    // if minus 1 from it, all of bits in the result will be 1
    public bool IsPowerOfTwo_2(int n)
    {
        return (n > 0) && ((n & (n - 1)) == 0);
    }
}