/*
3222. Find the Winning Player in Coin Game

https://leetcode.com/problems/find-the-winning-player-in-coin-game/
*/

/*
Each round of operation consumes 2 coins valued at 75 and 8 coins valued at 10
The max of rounds k = min(x/2, y/8), and then update the values of x and y, where x and y are the remaining
number of coins after k rounds of operations.

If x > 0 and y ≥ 4, then Alice can continue the operation, and Bob loses, return "Alice"; otherwise, return
"Bob".
The time complexity is O(1), and the space complexity is O(1).
*/

function losingPlayer(x: number, y: number): string {
  const k = Math.min(Math.floor(x / 2), Math.floor(y / 8));
  x -= k * 2;
  y -= k * 8;
  return x && y >= 4 ? "Alice" : "Bob";
}
