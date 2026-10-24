/*
427. Construct Quad Tree

https://leetcode.com/problems/construct-quad-tree/
*/

class _Node {
  val: boolean;
  isLeaf: boolean;
  topLeft: _Node | null;
  topRight: _Node | null;
  bottomLeft: _Node | null;
  bottomRight: _Node | null;
  constructor(
    val?: boolean,
    isLeaf?: boolean,
    topLeft?: _Node,
    topRight?: _Node,
    bottomLeft?: _Node,
    bottomRight?: _Node
  ) {
    this.val = val === undefined ? false : val;
    this.isLeaf = isLeaf === undefined ? false : isLeaf;
    this.topLeft = topLeft === undefined ? null : topLeft;
    this.topRight = topRight === undefined ? null : topRight;
    this.bottomLeft = bottomLeft === undefined ? null : bottomLeft;
    this.bottomRight = bottomRight === undefined ? null : bottomRight;
  }
}

//如果一个正方形中所有的数字都是0，则val是False，否则val是True。
// http://www.cnblogs.com/grandyang/p/9649348.html
function construct(grid: number[][]): _Node | null {
  return helper(grid, 0, 0, grid.length);
}

function helper(
  grid: number[][],
  row: number,
  col: number,
  len: number
): _Node | null {
  if (len === 1) {
    return new _Node(grid[row][col] === 1, true);
  }

  let nextLen = len >> 1; // nextLen = len / 2
  let tl = helper(grid, row, col, nextLen);
  let tr = helper(grid, row, col + nextLen, nextLen);
  let bl = helper(grid, row + nextLen, col, nextLen);
  let br = helper(grid, row + nextLen, col + nextLen, nextLen);

  if (
    tl!.isLeaf &&
    tr!.isLeaf &&
    bl!.isLeaf &&
    br!.isLeaf &&
    ((tl!.val && tr!.val && bl!.val && br!.val) ||
      (!tl!.val && !tr!.val && !bl!.val && !br!.val))
  ) {
    return new _Node(tl!.val, true);
  } else {
    return new _Node(false, false, tl!, tr!, bl!, br!);
  }
}

export {};
