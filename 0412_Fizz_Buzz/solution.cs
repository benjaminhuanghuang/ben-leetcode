using System.Collections.Generic;

public class Solution412 {
    public IList<string> FizzBuzz(int n) {
        List<string> res = new List<string>();
        for(int i=0; i< n; i++)
        {
            int num = i + 1;
            if (num % 15 == 0)
                res.Add("FizzBuzz");
            else if (num % 3 ==0)
                res.Add("Fizz");
            else if (num % 5 == 0)
                res.Add("Buzz");
            else
                res.Add(num.ToString());
        }       
        return res;
    }
}