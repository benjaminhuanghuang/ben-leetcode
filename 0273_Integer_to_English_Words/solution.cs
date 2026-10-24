using System.Collections.Generic;

public class Solution273 {
    public string NumberToWords(int num) {
        // convert number less than 1000
        string res = convertHundred(num % 1000);

        List<string> v = new List<string>{"Thousand", "Million", "Billion"};
        for (int i = 0; i < 3; ++i) 
        {
            num /= 1000;
            res = num % 1000 > 0? convertHundred(num % 1000) + " " + v[i] + " " + res : res;
        }
        res = res.Trim();
        return res.Length == 0 ? "Zero" : res;
    }

    // convert number less than 1000
    private string convertHundred(int num) 
    {
        List<string> v1 = new List<string>{"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        List<string> v2 = new List<string>{"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        string res;
        int a = num / 100, b = num % 100, c = num % 10;
        if (b < 20)
            res =  v1[b];
        else
            res = v2[b / 10] + (c > 0 ? " " + v1[c] : "");
       
        if (a > 0) 
            res = v1[a] + " Hundred" + (b>0 ? " " + res : "");
        return res;
    }
}