using System.Text;
using System.Collections.Generic;
public class Solution482
{
    public string LicenseKeyFormatting_MemoryIssue(string S, int K)
    {
        S = S.Replace("-", "").ToUpper();
        int len = S.Length;
        if (len % K != 0)
            for (int i = 0; i < (K - (len % K)); i++)   // Do NOT use S.Length in for(;;)
            {
                S = '#' + S;
            }

        List<string> group = new List<string>();

        for (int i = 0; i < S.Length; i += S.Length % K)
        {
            group.Add(S.Substring(i, S.Length % K));
        }
        return string.Join("-", group.ToArray());
    }

    public string LicenseKeyFormatting(string S, int K)
    {
        StringBuilder sb = new StringBuilder(S);
        sb.Replace("-", "");
        int len = sb.Length;
        if (len % K != 0)
            for (int i = 0; i < (K - (len % K)); i++)   // Do NOT use S.Length in for(;;)
            {
                sb.Insert(0, "#");
            }
        int dashes = sb.Length / K - 1;
        for (int i = 1; i <= dashes; i++)
        {
            sb.Insert(K * i + (i - 1), "-");
        }
        if (len % K != 0)
            sb.Remove(0, (K - (len % K)));
        return sb.ToString().ToUpper();
    }
}