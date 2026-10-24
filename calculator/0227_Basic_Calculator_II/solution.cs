public class Solution227 {
    public int Calculate(string s) {
        s = s.Trim();
        
        int num = 0;
        int left = 0;
        int right = 0;
        char op = '+';
        for(int i=0; i < s.Length; i++)
        {
            char c = s[i];

            if (c == ' ')
                continue;
            if (char.IsDigit(c))
            {
                num = num * 10 + c - '0';
            }
            if (c == '+' || c == '-' || c == '*' || c == '/' || i== s.Length -1)
            {
                if ( op == '+')
                {
                    left = left + right;
                    right = num;
                }
                else if(op == '-')
                {
                    left = left + right;
                    right = -num;
                }
                else if(op == '*'){
                    right *= num;
                }
                else
                {
                    right = right / num;
                }
                num = 0;
                op = c;
            }
        }
        return left + right;     
    }
}