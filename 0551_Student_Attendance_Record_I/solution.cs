public class Solution551
{
    public bool CheckRecord(string s)
    {
        if (s == null || s.Length == 0)
            return false;

        char[] charArr = s.ToCharArray();
        int countA = 0;
        int countL = 0;
        for (int i = 0; i < s.Length; i++)
        {
            if (charArr[i] == 'A')
            {
                if (countA == 0)
                    countA += 1;
                else
                    return false;
            }
            if (charArr[i] == 'L')
            {
                if (countL < 2)
                    countL += 1;
                else
                    return false;
            }
            else
                countL = 0;
        }

        return true;
    }
}