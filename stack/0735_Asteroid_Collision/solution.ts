/*
735. Asteroid Collision

https://leetcode.com/problems/asteroid-collision/
*/

function asteroidCollision(asteroids: number[]): number[] {
  const stack: number[] = [];

  for (let i = 0; i < asteroids.length; ++i) {
    const asteroid = asteroids[i];

    if (asteroid > 0) {
      // Moving to the right, add to stack
      stack.push(asteroid);
    } else {
      // Moving to the left
      while (
        stack.length &&
        stack[stack.length - 1] > 0 &&
        stack[stack.length - 1] < -asteroid
      ) {
        stack.pop(); // Destroy the asteroids moving to the right
      }

      // If the top of the stack is an asteroid of the same size (after negating the current asteroid's value),
      // they will collide and explode, so pop the top of the stack
      if (stack.length && stack[stack.length - 1] === -asteroid) {
        stack.pop(); // Destroy both asteroids
      } else if (stack.length === 0 || stack[stack.length - 1] < 0) {
        // If the stack is empty or the top of the stack is moving left (negative),
        // push the current asteroid onto the stack as there is no collision
        stack.push(asteroid);
      }
    }
  }

  // Stack should now only contain surviving asteroids
  return stack;
}
