public class Solution191 {
    public int HammingWeight(uint n) {
        int count = 0;
        for (int i =0 ;i <32; i++)
        {
            var ibit = (int)n >> i & 1;
            count += ibit;
        }
        return count;
    }
}