/*
420. Strong Password Checker

A password is considered strong if below conditions are all met:

It has at least 6 characters and at most 20 characters.
It must contain at least one lowercase letter, at least one uppercase letter, and at least one digit.
It must NOT contain three repeating characters in a row ("...aaa..." is weak, but "...aa...a..." is strong, 
assuming other conditions are met).
Write a function strongPasswordChecker(s), that takes a string s as input, and return the MINIMUM change 
required to make s a strong password. If s is already strong, return 0.

Insertion, deletion and replace of any one character are all considered as one change.
*/
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