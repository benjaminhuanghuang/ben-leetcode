/*
6. ZigZag Conversion

The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: 
(you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".

*/

using System.Text;

public class Solution006 {
    public string Convert(string s, int numRows) {
        if (s==null || s.Length == 0 || numRows <=0){
            return "";
        }
        if (numRows == 1){
            return s;
        }
        StringBuilder sb = new StringBuilder();
        int step = 2 * numRows - 2;
        
        for (int row = 0 ; row < numRows ; row++)
        {
            if (row == 0 || row == numRows - 1)
            {
                // There are 2 numbs in a row in one step
                for (int index = row; index < s.Length; index += step)
                {
                    sb.Append(s[index]);
                }
            }
            else
            {
                // There are 3 numbs in a row in one step
                int index = row;
                bool flag = true;
                int step1 = 2 * (numRows -1 -index);
                int step2 = step - step1;
                while(index < s.Length){
                    sb.Append(s[index]);
                    if (flag)
                        index += step1;
                    else
                        index += step2;
                    flag = !flag;
                }
            }
        }

        return sb.ToString();
    }

    public string Convert_2(string s, int numRows) {
        if (s==null || s.Length == 0 || numRows <=0){
            return "";
        }
        if (numRows == 1){
            return s;
        }
        StringBuilder sb = new StringBuilder();
        int step = 2 * numRows - 2;
        
        for (int row = 0 ; row < numRows ; row++)
        {            
            for (int j = row; j < s.Length; j += step)
            {
                sb.Append(s[j]);
                if (row > 0 && row < numRows -1 && j+ 2*(numRows - 1 - row) < s.Length)
                {
                    sb.Append(s[j+ 2*(numRows - 1 - row)]);
                }
            }
        }

        return sb.ToString();
    }
}