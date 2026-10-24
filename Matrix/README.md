# Matrix

## 4 directions

```ts
const directions = [
  [0, 1],
  [1, 0],
  [0, -1],
  [-1, 0],
];

for (const [dr, dc] of directions) {
  const nr = r + dr;
  const nc = c + dc;
  if (isWithinBounds(nr, nc, matrix) && isValid(nr, nc, matrix)) {
    // dfs...
  }
}

export function isWithinBounds(
  r: number,
  c: number,
  matrix: number[][]
): boolean {
  return r >= 0 && r < matrix.length && c >= 0 && c < matrix[0].length;
}
```

## Init matrix

```ts
function create2DMatrix(
  rows: number,
  cols: number,
  defaultValue: number
): number[][] {
  return Array.from({ length: rows }).map(() =>
    Array.from({ length: cols }).map(() => defaultValue)
  );
}
```
