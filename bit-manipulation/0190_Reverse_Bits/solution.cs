public class Solution190 {
    public uint reverseBits(uint n) {
        uint res = 0;

        for (int i = 0; i < 32; i++)             
        {                 
            var ibit = (n >> i) & 1;  // get ith bit
            res = (res << 1) + ibit;
        }

        return res;
    }
}