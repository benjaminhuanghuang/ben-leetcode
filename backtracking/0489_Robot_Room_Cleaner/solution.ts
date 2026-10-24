/*
489. Robot Room Cleaner

https://leetcode.com/problems/robot-room-cleaner/

[Google] [Meta]
*/

class Robot {
  // Returns true if the cell in front is open and robot moves into the cell.
  // Returns false if the cell in front is blocked and robot stays in the current cell.
  move(): boolean {
    return false;
  }

  // Robot will stay in the same cell after calling turnLeft/turnRight.
  // Each turn will be 90 degrees.
  turnRight() {}

  // Robot will stay in the same cell after calling turnLeft/turnRight.
  // Each turn will be 90 degrees.
  turnLeft() {}

  // Clean the current cell.
  clean() {}
}

function cleanRoom(robot: Robot) {
  const dirs = [-1, 0, 1, 0, -1];
  const vis = new Set<string>();

  const dfs = (row: number, col: number, direction: number) => {
    vis.add(`${row}-${col}`);
    robot.clean();

    for (let k = 0; k < 4; ++k) {
      const newDir = (direction + k) % 4;
      const [x, y] = [row + dirs[newDir], col + dirs[newDir + 1]];
      if (!vis.has(`${x}-${y}`) && robot.move()) {
        dfs(x, y, newDir);
        // return to the original position and direction
        robot.turnRight();
        robot.turnRight();
        robot.move();
        robot.turnRight();
        robot.turnRight();
      }
      robot.turnRight();
    }
  };

  dfs(0, 0, 0);
}
