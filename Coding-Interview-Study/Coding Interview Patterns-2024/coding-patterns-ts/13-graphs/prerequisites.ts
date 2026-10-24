function prerequisites(n: number, prerequisites: number[][]): boolean {
  const graph = new Map<number, number[]>();
  const inDegrees = new Array(n).fill(0);

  // Initialize graph with empty arrays for all nodes
  for (let i = 0; i < n; i++) {
    graph.set(i, []);
  }

  // Represent the graph as an adjacency list and record the in-
  // degree of each course.
  for (const [prerequisite, course] of prerequisites) {
    graph.get(prerequisite)!.push(course);
    inDegrees[course] += 1;
  }

  const queue: number[] = [];

  // Add all courses with an in-degree of 0 to the queue.
  for (let i = 0; i < n; i++) {
    if (inDegrees[i] === 0) {
      queue.push(i);
    }
  }

  let enrolledCourses = 0;

  // Perform topological sort.
  while (queue.length > 0) {
    const node = queue.shift()!;
    enrolledCourses += 1;

    for (const neighbor of graph.get(node)!) {
      inDegrees[neighbor] -= 1;

      // If the in-degree of a neighboring course becomes 0, add
      // it to the queue.
      if (inDegrees[neighbor] === 0) {
        queue.push(neighbor);
      }
    }
  }

  // Return true if we've successfully enrolled in all courses.
  return enrolledCourses === n;
}

/*
## Time complexity: The time complexity of prerequisites is O(n + t ), where t denotes the number of
edges derived from the prerequisites array. Here's why:
• Creating the adjacency list and recording the in-degrees takes O(e) time because we iterate
through each prerequisite once.
• Adding all courses with in-degree 0 to the queue takes O(n) time because we check the in-degree of each course once.
Performing Kahn's algorithm takes O(n + e) time because each course and prerequisite is processed
at most once during the traversal.


## Space complexity: The space complexity is O(n + e), since the adjacency list takes up O(n +e) space,
while the in_degrees array and queue each take up O(n) space.
*/
