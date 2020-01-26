/*
282. Expression Add Operators

Given a string that contains only digits 0-9 and a target value, return all possibilities to add binary 
operators (not unary) +, -, or * between the digits so they evaluate to the target value.

Examples: 
"123", 6 -> ["1+2+3", "1*2*3"] 
"232", 8 -> ["2*3+2", "2+3*2"]
"105", 5 -> ["1*0+5","10-5"]
"00", 0 -> ["0+0", "0-0", "0*0"]
"3456237490", 9191 -> []
*/

/*
比如"123", 15能返回"12+3"，说明连着的数字也可以。

如果输入为"000",0的话，容易出现以下的错误：
Wrong:["0+0+0","0+0-0","0+0*0","0-0+0","0-0-0","0-0*0","0*0+0","0*0-0","0*0*0","0+00","0-00","0*00","00+0","00-0",
"00*0","000"]
Correct：["0*0*0","0*0+0","0*0-0","0+0*0","0+0+0","0+0-0","0-0*0","0-0+0","0-0-0"]
*/
using System.Collections.Generic;

public class Solution282 {
    //http://blog.csdn.net/u013027996/article/details/48713751
    public IList<string> AddOperators(string num, int target) {
        List<string> res = new List<string>();
        dfs(res, num, "", 0, 0, 0, target);  
        return res;
    }

    private void dfs(List<string> res, string num, string expression, int pos, long sum, long lastNum, int target) 
    {
        int len = num.Length;  
        if (pos == len && sum == target) {  
            res.Add(expression);  
            return;  
        }  
        if (pos >= len) {  
            return;  
        }  
        for (int i = pos; i < len; i++) 
        {  
            if (i != pos && num[pos] == '0') {  
                break;  
            }  
            long curNum = long.Parse(num.Substring(pos, i - pos + 1));  
            if (pos == 0) {  
                dfs(res, num, expression + "" + curNum, i + 1, curNum, curNum, target);  
            } 
            else 
            {  
                dfs(res, num, expression + "+" + curNum, i + 1, sum + curNum, curNum, target);  
                dfs(res, num, expression + "-" + curNum, i + 1, sum - curNum, -curNum, target);  
                dfs(res, num, expression + "*" + curNum, i + 1, sum - lastNum + lastNum * curNum, lastNum * curNum, target);  
            }  
        }  
    }
}