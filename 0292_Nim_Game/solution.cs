/*
when n in [1,3] , first mover will win.
when n == 4 , no matter how many stones the first player take, game will convert to case 1, first player will lose.
when n in [5,7] , first mover can move [1,3] stones and convert the status to case 2, first player will win.
when n == 8 , no matter how many stones the first player take, game will convert to case 3, first player will lose.
...
*/
public class Solution292 {
    public bool CanWinNim(int n) {
        return n % 4 > 0;
    }
}