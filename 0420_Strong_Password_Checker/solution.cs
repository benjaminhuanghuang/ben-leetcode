using System.Linq;

public class Solution420 {
    //http://bookshadow.com/weblog/2016/10/21/leetcode-strong-password-checker/
    public int StrongPasswordChecker(string s) {
        int totalCount = s.Length;
        int lowers = s.Select(i=>char.IsLower(i)).Count();
        int uppers = s.Select(i=>char.IsUpper(i)).Count();
        int digits = s.Select(i=>char.IsDigit(i)).Count();
        // 有效字符类型数（小写、大写字母、数字各算一种）
        int charTypeCount = lowers>0?1:0 + uppers>0?1:0 + digits>0?1:0;


        return 0;
    }
}