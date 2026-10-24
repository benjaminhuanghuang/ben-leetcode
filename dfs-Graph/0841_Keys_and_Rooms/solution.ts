/*
841. Keys and Rooms

https://leetcode.com/problems/keys-and-rooms/
*/

/*
  http://zxi.mytechroad.com/blog/graph/leetcode-841-keys-and-rooms/

  Solution: DFS, 遍历所有节点
    Time complexity: O(V + E)
    Space complexity: O(V)
*/

function canVisitAllRooms(rooms: number[][]): boolean {
  const visited: Set<number> = new Set();

  dfs(rooms, 0, visited);

  return visited.size === rooms.length;
}

function dfs(rooms: number[][], cur: number, visited: Set<number>): void {
  if (visited.has(cur)) return;

  visited.add(cur);
  for (const next of rooms[cur]) {
    dfs(rooms, next, visited);
  }
}
