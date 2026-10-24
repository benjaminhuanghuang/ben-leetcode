public class Solution186
{
    public void reverseWords(char[] s)
    {
        int i = 0;
        for (int j = 0; j < s.Length; j++)
        {
            if (s[j] == ' ')
            {
                reverseBetween(s, i, j - 1);
                i = j + 1;
            }
        }
        reverseBetween(s, 0, s.Length - 1);
    }

    public void reverseBetween(char[] s, int i, int j)
    {
        while (i < j)
        {
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            i++;
            j--;
        }
    }
}