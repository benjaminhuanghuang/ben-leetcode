using System;

public class Solution306 {
    //http://www.it610.com/article/5587652.htm
    //只要前两个数固定了，后面是否能划分就是确定的了。
    //枚举前两个数的终点位置，进行递归判断即可。
    // 第一层是first的长度，第二层是second的长度，一旦发现first或second以0开头（单独一个0除外），表示加数不合法，就返回false，
    // 否则，下一层递归时候将second作为first，second + first的和作为second，依此进行下去，
    //如果恰好index指向最后一个num的字符，则返回true：
    public bool IsAdditiveNumber(string num) {
        if (String.IsNullOrEmpty(num))
            return false;
        
        for (int i = 1; i <= num.Length / 2; i++)
        {
            for (int j = 1; j < num.Length - i ; j++)
            {
                if (isValid(num, num.Substring(0, i), num.Substring(i, j), i + j)) 
                    return true;
            }
        }
        return false;
    }

     private bool isValid(string num, string first, string second, int index) 
     {
        if (first.Length > 1 && first[0]=='0' || second.Length > 1 && second[0]=='0') 
            return false;
        if (index == num.Length) 
            return true;
        long sum = Int64.Parse(first) + Int64.Parse(second);
        string sumStr = sum.ToString();
        if (index + sumStr.Length<= num.Length && num.Substring(index, sumStr.Length) == sumStr)
            if(isValid(num, second, sumStr, index + sumStr.Length)) 
                return true;
        return false;
    }  
}


/*
    var input = "1023";

    var s = new Solution306();
    var result = s.IsAdditiveNumber(input);  

    Console.WriteLine(result);
*/