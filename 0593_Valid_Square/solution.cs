/*
593. Valid Square

Given the coordinates of four points in 2D space, return whether the four points could construct a square.

The coordinate (x,y) of a point is represented by an integer array with two integers.

Example:
Input: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,1]
Output: True
Note:

All the input integers are in the range [-10000, 10000].
A valid square has four equal sides with positive length and four equal angles (90-degree angles).
Input points have no order.
 */

using System;
public class Solution593
{
    /*
    There are only two equal longest lenghts, they are diagonal.
    The non longest lengths are all equal.
     */
    public bool ValidSquare(int[] p1, int[] p2, int[] p3, int[] p4)
    {
        long[] lengths = {length(p1, p2), length(p2, p3), length(p3, p4),
            length(p4, p1), length(p1, p3),length(p2, p4)}; // all 6 sides

        long max = 0, nonMax = 0;
        foreach (long len in lengths)
        {
            max = Math.Max(max, len);
        }
        int count = 0;
        for (int i = 0; i < lengths.Length; i++)
        {
            if (lengths[i] == max)
                count++;
            else 
                nonMax = lengths[i]; // non diagonal side.
        }
        if (count != 2)
            return false; // diagonals lenghts have to be same.

        foreach (long len in lengths)
        {
            if (len != max && len != nonMax) 
                return false; // sides have to be same length
        }
        return true;
    }

    private long length(int[] p1, int[] p2)
    {
        return (long)Math.Pow(p1[0] - p2[0], 2) + (long)Math.Pow(p1[1] - p2[1], 2);
    }
}