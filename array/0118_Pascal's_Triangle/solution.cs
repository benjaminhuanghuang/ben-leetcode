/*
118. Pascal's Triangle

Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
[
 [1],
 [1,1],
 [1,2,1],
 [1,3,3,1],
 [1,4,6,4,1]
]


*/
using System.Collections.Generic;

public class Solution118 {
    public IList<IList<int>> Generate(int numRows) {
        var res = new List<IList<int>>();
        for (int i = 0 ; i < numRows; i++)
        {
            var row = new List<int>();
                
            for(int col = 0; col <= i ; col++)
            {
                row.Add((col == 0 || col == i) ? 1 : res[i - 1][col - 1] + res[i - 1][col]);
            }
            res.Add(row);
        }
        return res;
    }
}