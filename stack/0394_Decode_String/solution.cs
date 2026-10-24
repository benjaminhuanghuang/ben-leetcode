using System.Text;
using System.Collections.Generic;

public class Solution394 {
    public string DecodeString(string s) {
        string res = "";
        var counts = new Stack<int>();
        var strs = new Stack<string>();
        
        int i = 0;
        while( i < s.Length)
        {
            if(char.IsDigit(s[i]))
            {
                int num=0;
                while(char.IsDigit(s[i])){
                    num = num * 10 + (s[i]-'0');
                    i++;
                }
                counts.Push(num);
            }
            else if(s[i]=='[')
            {
                strs.Push(res);
                res="";
                i++;
            }
            else if (s[i]==']')
            {
                StringBuilder sb = new StringBuilder(strs.Pop());
                int count = counts.Pop();
                for(int j=0; j< count ; j++){
                    sb.Append(res);
                }
                res = sb.ToString();
                i++;
            }
            else   // normal char
            {   
                res += s[i++];
            }
        }
        return res;
    }
}