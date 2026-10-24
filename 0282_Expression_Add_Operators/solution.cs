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