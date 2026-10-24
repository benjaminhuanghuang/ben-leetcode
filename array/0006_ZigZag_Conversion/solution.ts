/*
6. Zigzag Conversion
https://leetcode.com/problems/zigzag-conversion/
*/

function convert(s: string, numRows: number): string {
  if (numRows === 1) return s;

  const rows: string[] = Array(numRows).fill("");
  let row = 0;
  let direction = -1; // 1: down, -1: up

  for (const c of s) {
    rows[row] += c;
    if (row === 0 || row === numRows - 1) {
      direction *= -1; // change direction
    }
    row += direction;
  }

  return rows.join("");
}
