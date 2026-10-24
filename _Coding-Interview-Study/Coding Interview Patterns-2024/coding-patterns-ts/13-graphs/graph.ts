export class GraphNode {
  val: number;
  neighbors: GraphNode[];

  constructor(val: number, neighbors: GraphNode[] = []) {
    this.val = val;
    this.neighbors = neighbors;
  }
}
// Define direction vectors for up, down, left, and right.
export const dirs: [number, number][] = [
  [-1, 0],
  [1, 0],
  [0, -1],
  [0, 1],
];

export function isWithinBounds(
  r: number,
  c: number,
  matrix: number[][]
): boolean {
  return r >= 0 && r < matrix.length && c >= 0 && c < matrix[0].length;
}
