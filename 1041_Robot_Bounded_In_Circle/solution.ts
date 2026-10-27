/*
https://leetcode.com/problems/robot-bounded-in-circle/

执行一轮指令后：
- 若回到原点，必然循环 -> bounded
- 若方向不再朝北（初始方向），最多 4 轮方向会回到朝北，轨迹闭合 -> bounded
- 否则方向不变且未回原点，之后每轮都会沿同一方向继续偏移，永远逃离 -> not bounded
*/
function isRobotBounded(instructions: string): boolean {
  const directions = [
    [0, 1], // N
    [1, 0], // E
    [0, -1], // S
    [-1, 0], // W
  ];
  let x = 0;
  let y = 0;
  let dir = 0;

  for (const move of instructions) {
    if (move === 'G') {
      x += directions[dir][0];
      y += directions[dir][1];
    } else if (move === 'L') {
      dir = (dir + 3) % 4;
    } else {
      dir = (dir + 1) % 4;
    }
  }

  return (x === 0 && y === 0) || dir !== 0;
}

export {};
