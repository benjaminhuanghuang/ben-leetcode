using System.Text;

public class Solution038 {
         
    private static string SayNext(string start)
    {
        var res = new StringBuilder();
        var pre = 0;
        for (int i = 0; i < start.Length; i++)
        {
            if (start[i] != start[pre])
            {
                int count = i - pre;
                res.Append(count).Append(start[pre]);
                pre = i;
            }
        }

        res.Append(start.Length - pre).Append(start[pre]);

        return res.ToString();
    }

    public string CountAndSay_Recursion(int n) 
    {
            if (n == 1) 
                return "1";

            var pre = CountAndSay_Recursion(n - 1);

            return SayNext(pre);    
    }

    public string CountAndSay_Iteration(int n)
        {
            var start = "1";
            while (--n > 0)
            {
                start = SayNext(start);
            }

            return start;
        }
}