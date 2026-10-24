/*
909. Snakes and Ladders

https://leetcode.com/problems/snakes-and-ladders/
*/

/*
大富翁，某些点会直接跳到另一个点
*/
function snakesAndLadders(board: number[][]): number {
  const n = board.length;
  const b: number[] = new Array(n * n + 1);
  let flag = true;
  let x = 1;

  // copy the board to b
  for (let i = n - 1; i >= 0; i--) {
    if (flag) {
      for (let j = 0; j < n; j++) {
        b[x++] = board[i][j];
      }
    } else {
      for (let j = n - 1; j >= 0; j--) {
        b[x++] = board[i][j];
      }
    }
    flag = !flag;
  }
  // is the position visited
  const counter: number[] = new Array(n * n + 1).fill(-1);
  counter[1] = 0;

  // start from position 1
  const queue: number[] = [1];
  while (queue.length > 0) {
    const cur = queue.shift()!;
    // roll the dice, move 1 ~ 6 steps
    for (let i = 1; i <= 6; i++) {
      if (cur + i > n * n) break;
      let next = cur + i;
      if (b[next] > -1) {
        // if the next position is a snake or ladder, jump to the new position
        next = b[next];
      }
      if (next === n * n) return counter[cur] + 1;
      if (counter[next] === -1) {
        // if the position is not visited
        queue.push(next);
        counter[next] = counter[cur] + 1;
      }
    }
  }

  return -1;
}
