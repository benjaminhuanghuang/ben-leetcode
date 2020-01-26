/*
402. Remove K Digits
Given a non-negative integer num represented as a string, remove k digits from the number so that the new number is the smallest possible.

Note:
The length of num is less than 10002 and will be ≥ k.
The given num does not contain any leading zero.
Example 1:

Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
Example 2:

Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
Example 3:

Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.
*/

using System.Text;
using System.Collections.Generic;

public class Solution402 {

    // 使得string builder 中的数字尽可能保持递增顺序。
    // 需要注意的是字符串首字符不为０
    public string RemoveKdigits(string num, int k) {
        if (k >= num.Length)
            return "0";
        StringBuilder sb = new StringBuilder(num);
        int i, j;
		for (i = 0; i < k; i++) {
			j = 0;
            while(j < sb.Length - 1)
            {
                if ( sb[j] > sb[j + 1])
                    break;
                j++;
            }
            sb.Remove(j, 1); // remove string at j, length = j + 1;
		}
        while (sb.Length > 1 && sb[0]=='0')
            sb.Remove(0,1);
        return sb.ToString();
    }
}