/*
210. Course Schedule II

https://leetcode.com/problems/course-schedule-ii/
*/

/*
HuaHua
https://www.youtube.com/watch?v=Qqgck2ijUjU

Topological sort

DFS, add the node the visited array befr popping the stack.
If a node is already added to visited, there is a cycle.
Answer is the reverse of the visited array.

Time complexity: O(V + E) ~ O(V^2) 
O(V^2) means that there is a edge between every pair of nodes, shoule have cycle.
*/
function findOrder(numCourses: number, prerequisites: number[][]): number[] {
  const graph: Map<number, number[]> = new Map();

  // Create adjacency list
  for (let i = 0; i < numCourses; i++) {
    graph.set(i, []);
  }
  for (const [course, prereq] of prerequisites) {
    graph.get(prereq)!.push(course); //[1, 0] means 0 -> 1
  }

  // Track visited nodes
  const visited: number[] = new Array(numCourses).fill(0); // 0 = unvisited, 1 = visiting, 2 = visited
  const answer: number[] = [];

  // DFS return false if there is a cycle
  function dfs(
    course: number,
    graph: Map<number, number[]>,
    visited: number[],
    answer: number[]
  ): boolean {
    if (visited[course] === 1) return false; // 1 = visiting, Cycle detected
    if (visited[course] === 2) return true; // Already visited

    visited[course] = 1; // Mark as visiting
    for (const prereq of graph.get(course)!) {
      if (!dfs(prereq, graph, visited, answer)) return false;
    }
    visited[course] = 2; // Mark as visited
    answer.push(course);
    return true;
  }

  for (let course = 0; course < numCourses; course++) {
    if (!dfs(course, graph, visited, answer)) return [];
  }

  answer.reverse();
  return answer;
}
