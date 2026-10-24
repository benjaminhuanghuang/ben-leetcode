/*
1079. Letter Tile Possibilities

https://leetcode.com/problems/letter-tile-possibilities/
*/

function numTilePossibilities(tiles: string): number {
  const count: number[] = new Array(26).fill(0);
  for (const tile of tiles) {
    count[tile.charCodeAt(0) - "A".charCodeAt(0)]++;
  }

  // Depth-first search function to explore all combinations
  const dfs = (count: number[]): number => {
    let sum = 0;

    for (let i = 0; i < 26; ++i) {
      // If a tile of the current letter is available, explore further combinations
      if (count[i] > 0) {
        // Increment the sum for the current combination
        sum++;
        // Choose the tile and explore further
        count[i]--;
        // Add the number of combinations from the sub-problem
        sum += dfs(count);
        // Backtrack and return the tile to the pool
        count[i]++;
      }
    }
    return sum;
  };

  return dfs(count);
}
