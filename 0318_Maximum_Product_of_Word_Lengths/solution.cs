using System;

public class Solution318 {
    public int MaxProduct(string[] words) {
        int count = words.Length;
        int[] words_bits = new int[count];

        for(int i=0; i< count; i++)
        {
            foreach (var c in words[i])
            {
                words_bits[i] |= 1 << (c -'a');
            }
        }
        int ans = 0;
        for(int i =0; i< count; i++)
        {
            for(int j= i+1; j < count; j++)
            {
                if((words_bits[i] & words_bits[j]) ==0) // two words do not have common letter
                {
                    ans = Math.Max(ans, words[i].Length * words[j].Length);
                }
            }
        }
        return ans;
    }
}