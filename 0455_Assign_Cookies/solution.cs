using System;

public class Solution455 {
    public int FindContentChildren(int[] greed, int[] size) 
    {
        Array.Sort(greed);
        Array.Sort(size);
        int i_greed = greed.Length - 1;
        int i_size = size.Length - 1;
        int ans = 0;
        while(i_greed >=0 && i_size >=0)
        {
            if (size[i_size] >= greed[i_greed])
            {
                ans ++;
                i_size --;
            }
            i_greed--;           
        }
        return ans;
    }
}