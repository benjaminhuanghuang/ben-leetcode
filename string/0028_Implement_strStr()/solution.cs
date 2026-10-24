public class Solution028 {
    public int StrStr(string haystack, string needle) {
        if (string.IsNullOrEmpty(needle))
        {
            return 0;
        }
        for (int i = 0 ; i <= haystack.Length - needle.Length; i++)
        {
            for (int j = 0 ; j < needle.Length; j++)
            {
                char h = haystack[i+j];
                char n = needle[j];
                if (h != n)
                    break;
                if (j== needle.Length - 1)
                    return i; 
            }   

        }
        return -1;
    }

    public int StrStr_2(string haystack, string needle)
    {
        if (string.IsNullOrEmpty(needle)) return 0;
        var needleLength = needle.Length;
        for (int i = 0; i <= haystack.Length - needleLength; i++)
        {
            if (haystack.Substring(i, needleLength).Equals(needle))
                return i;
        }

        return -1;
    }
}