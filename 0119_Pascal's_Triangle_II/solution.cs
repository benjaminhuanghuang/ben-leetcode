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