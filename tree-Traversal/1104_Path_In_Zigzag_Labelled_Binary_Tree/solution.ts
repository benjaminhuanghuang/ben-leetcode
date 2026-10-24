/*
1104. Path In Zigzag Labelled Binary Tree

https://leetcode.com/problems/path-in-zigzag-labelled-binary-tree/
*/

function pathInZigZagTree(label: number): number[] {
  // Initialize root level value as 1, and depth as 1
  let levelStartValue: number = 1;
  let depth: number = 1;

  // Calculate the depth of the given label
  // The depth increases while it is possible to go further down
  while (levelStartValue << 1 <= label) {
    levelStartValue <<= 1;
    depth++;
  }

  // Prepare an array to store the path
  const path: number[] = [];

  // Loop from the level of the label to the root
  for (; depth > 0; depth--) {
    // Add current label to the path
    path.push(label);
    // Find the parent label. This operation calculates the opposite label in the same level and then finds
    // the parent in the previous level by performing integer division by 2
    label = ((1 << (depth - 1)) + (1 << depth) - 1 - label) >> 1;
  }

  // Reverse the path so that it starts from the root
  path.reverse();
  return path;
}
