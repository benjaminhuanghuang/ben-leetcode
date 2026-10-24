public class Solution557 {
    public string ReverseWords(string s) {
        if(s == null || s.Length == 0)
            return s;

        char[] charArray = s.ToCharArray();
        int start = 0;
        for (int i = 0 ;i < charArray.Length ; i++)
        {
            if (i == charArray.Length -1)
            {
                this.Reverse(charArray, start, i);
            }
            else
            {
                if(charArray[i] == ' ')
                {
                    this.Reverse(charArray, start, i-1);
                    start = i +1;
                }
            }
        }
        return new string(charArray);
    }
    private void Reverse(char[] charArr, int start, int end){
        while(start < end)
        {
            char temp = charArr[start];
            charArr[start] = charArr[end];
            charArr[end] = temp;
            start++;
            end--;
        }   
    }
}