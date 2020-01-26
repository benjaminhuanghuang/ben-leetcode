package cn.huang.leetcode;

import java.util.Arrays;

/*

455. Assign Cookies

 */
public class LC_0455_AssignCookies {
    public int findContentChildren(int[] g, int[] s) {
        int count = 0;
        Arrays.sort(g);
        Arrays.sort(s);
        int j=0;
        int i=0;
        while(i<s.length && count<g.length){
            if(g[count]<=s[i])
                count++;
            i++;
        }
        return count;
    }
}
