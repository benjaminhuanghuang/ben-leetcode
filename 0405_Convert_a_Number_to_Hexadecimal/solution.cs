public class Solution405 {
    public string ToHex(int num) {
        string res = "";
        // 有符号数右移， 左边会补上符号位
        for (int i = 0; num != 0 && i<8; ++i) 
        {
            int t = num & 0xf;
            if (t >= 10) 
                res = (char)('a' + t - 10) + res;
            else 
                res = (char)('0' + t) + res;
            num >>= 4;
        }
        return res=="" ? "0" : res;
    }
}