/*
149. Max Points on a Line

https://leetcode.com/problems/max-points-on-a-line/
*/

// for each point, calculate the slope with other point. put slope into hash table,
// then we know points with same slope in a line.
// points with same x and y. in that case, slope does not work.
// use an int to count how many points are same.

function maxPoints(points: number[][]): number {
  let max = 0;
  for (const point of points) {
    const hashtable: { [key: number]: number } = {};
    let samePointNumber = 0;

    for (const anotherPoint of points) {
      // Skip the point with the same location
      if (point[0] === anotherPoint[0] && point[1] === anotherPoint[1]) {
        samePointNumber++;
        continue;
      }

      // Calculate slope (handling vertical lines)
      let slope: number;
      if (point[0] === anotherPoint[0]) {
        slope = Infinity; // Vertical line
      } else {
        slope = (point[1] - anotherPoint[1]) / (point[0] - anotherPoint[0]);
      }
      // Count the slope occurrences
      if (hashtable[slope]) {
        hashtable[slope]++;
      } else {
        hashtable[slope] = 1;
      }
    }

    // Calculate the maximum points on the same line passing through the current point
    let currentMax = samePointNumber; // Points with the same coordinates
    for (const count of Object.values(hashtable)) {
      currentMax = Math.max(currentMax, count + samePointNumber);
    }

    max = Math.max(max, currentMax);
  }

  return max;
}
