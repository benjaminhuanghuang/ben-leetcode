/*
292. Nim Game
You are playing the following Nim Game with your friend: There is a heap of stones on the table, 
each time one of you take turns to remove 1 to 3 stones. 

The one who removes the last stone will be the winner. 
You will take the first turn to remove the stones.

Both of you are very clever and have optimal strategies for the game. Write a function to determine 
whether you can win the game given the number of stones in the heap.

For example, if there are 4 stones in the heap, then you will never win the game: no matter 1, 2, or 
3 stones you remove, the last stone will always be removed by your friend.

Hint:

If there are 5 stones in the heap, could you figure out a way to remove the stones such that you will always be the winner?
*/

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