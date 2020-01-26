/*
119. Pascal's Triangle II  

Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?

[
 [1],
 [1,1],
 [1,2,1],
 [1,3,3,1],
 [1,4,6,4,1]
]
*/
using System.Collections.Generic;

public class Solution119 {
    public IList<int> GetRow(int rowIndex) {
        var list = new int[rowIndex + 1];
        for (int row = 1; row <= rowIndex + 1; row++)
        {                 
            for (int index = row - 1; index >= 0; index--)
            {
                list[index] = (index == 0 || index == row - 1) ? 1 : list[index - 1] + list[index];
            }
        }

        return list;
    }
}