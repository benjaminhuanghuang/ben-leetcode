/*
207. Course Schedule
https://leetcode.com/problems/course-schedule/
*/

/*
    This method involves using in-degrees to represent the number of prerequisites for each course.
*/
function canFinish(numCourses: number, prerequisites: number[][]): boolean {
  const graph: Map<number, number[]> = new Map();
  const indegrees = Array.from({ length: numCourses }, () => 0);

  for (let i = 0; i < numCourses; i++) {
    graph.set(i, []);
  }
  for (const [course, prereq] of prerequisites) {
    graph.get(prereq)!.push(course);
    indegrees[course]++;
  }

  // Add courses with no prerequisites to the queue, the indegree is 0
  const queue = [];
  for (let i = 0; i < numCourses; i++) {
    if (indegrees[i] === 0) {
      queue.push(i);
    }
  }

  while (queue.length) {
    const course = queue.shift() as number;
    numCourses--;

    for (const nextCourse of graph.get(course)!) {
      indegrees[nextCourse]--;
      if (indegrees[nextCourse] === 0) {
        queue.push(nextCourse);
      }
    }
  }

  return numCourses === 0;
}

/*
Hua Hua https://www.youtube.com/watch?v=M6SBePBMznU
Topologic sort via DFS Use in-degree to represent the number of prerequisites for each course.

*/

function canFinish_DFS(numCourses: number, prerequisites: number[][]): boolean {
  const graph: Map<number, number[]> = new Map();

  // Create adjacency list
  for (let i = 0; i < numCourses; i++) {
    graph.set(i, []);
  }
  for (const [course, prereq] of prerequisites) {
    graph.get(course)!.push(prereq);
  }

  // Track visited nodes
  const visited: number[] = new Array(numCourses).fill(0); // 0 = unvisited, 1 = visiting, 2 = visited

  function dfs(course: number): boolean {
    if (visited[course] === 1) return false; // 1 = visiting, Cycle detected
    if (visited[course] === 2) return true; // Already visited

    visited[course] = 1; // Mark as visiting
    for (const prereq of graph.get(course)!) {
      if (!dfs(prereq)) return false;
    }
    visited[course] = 2; // Mark as visited
    return true;
  }

  for (let course = 0; course < numCourses; course++) {
    if (!dfs(course)) return false;
  }

  return true;
}
