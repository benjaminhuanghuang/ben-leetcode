using System;

public class Solution537
{
    public string ComplexNumberMultiply(string a, string b)
    {
        if (a == null || a.Length == 0 || b == null || b.Length == 0)
            return "0";

        int realA = int.Parse(a.Split('+')[0]);
        int virtualA = int.Parse(a.Split('+')[1].Substring(0, a.Split('+')[1].Length - 1));

        int realB = int.Parse(b.Split('+')[0]);
        int virtualB = int.Parse(b.Split('+')[1].Substring(0, b.Split('+')[1].Length - 1));

        int r = realA * realB - virtualA * virtualB;
        int v = realA * virtualB + virtualA * realB;

        return $"{r}+{v}i";
    }
}


/*

    var s = new Solution537();
    var res = s.ComplexNumberMultiply("1+-1i", "1+-1i");
    Console.WriteLine(res);

 */