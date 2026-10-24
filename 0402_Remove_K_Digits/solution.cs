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