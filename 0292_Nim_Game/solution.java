package cn.huang.leetcode;

/*
    292	 Nim Game
 */
public class LC_0292_NimGame {
    public boolean canWinNim(int n) {
        if(n == 0)
            return false;

        return n %4 !=0;
    }
}
