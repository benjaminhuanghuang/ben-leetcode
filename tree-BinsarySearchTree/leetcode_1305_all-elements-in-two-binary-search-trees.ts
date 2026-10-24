/*
1305. All Elements in Two Binary Search Trees

https://leetcode.com/problems/all-elements-in-two-binary-search-trees/
*/

import { TreeNode } from "../Common/TreeNode";

/*
Collect and sort
https://algo.monster/liteproblems/1305
https://www.youtube.com/watch?v=2cbsWlAHlj4

Time complexity: O(NLogN)
Space complexity: O(N)
*/
function getAllElements_huahua(
  root1: TreeNode | null,
  root2: TreeNode | null
): number[] {
  const smallest = (root: TreeNode | null, stack: TreeNode[]): void => {
    while (root) {
      stack.push(root);
      root = root.left;
    }
  };

  const s1: TreeNode[] = [];
  const s2: TreeNode[] = [];
  smallest(root1, s1);
  smallest(root2, s2);

  const ans: number[] = [];

  while (s1.length > 0 || s2.length > 0) {
    const s =
      s1.length === 0
        ? s2
        : s2.length === 0
          ? s1
          : s1[s1.length - 1].val < s2[s2.length - 1].val
            ? s1
            : s2;
    const n = s.pop();
    if (n) {
      ans.push(n.val);
      smallest(n.right, s);
    }
  }

  return ans;
}
function getAllElements(
  root1: TreeNode | null,
  root2: TreeNode | null
): number[] {
  const result: number[] = [];

  // Use two stacks to perform inorder traversal on both trees simultaneously.
  const stacks: [TreeNode[], TreeNode[]] = [[], []];

  while (
    root1 !== null ||
    stacks[0].length > 0 ||
    root2 !== null ||
    stacks[1].length > 0
  ) {
    // Inorder traversal on the first tree. the leftmost node is the smallest.
    while (root1 !== null) {
      stacks[0].push(root1);
      root1 = root1.left; // Move to the left child.
    }

    // Inorder traversal on the second tree. the leftmost node is the smallest.
    while (
      root2 !== null &&
      (stacks[0].length === 0 ||
        root2.val < stacks[0][stacks[0].length - 1].val)
    ) {
      stacks[1].push(root2);
      root2 = root2.left; // Move to the left child.
    }

    // Determine which tree's node value to take (the smaller one), and move to the right subtree.
    if (
      stacks[0].length === 0 ||
      (stacks[1].length > 0 &&
        stacks[0][stacks[0].length - 1].val >
          stacks[1][stacks[1].length - 1].val)
    ) {
      const { val, right } = stacks[1].pop()!;
      result.push(val); // Add the value of the node to the result array.
      root2 = right; // Update root2 to the right child.
    } else {
      const { val, right } = stacks[0].pop()!;
      result.push(val); // Add the value of the node to the result array.
      root1 = right; // Update root1 to the right child.
    }
  }

  return result;
}

/*
https://www.youtube.com/watch?v=2cbsWlAHlj4 (HuaHua)

Time complexity: O(t1 + t2)
Space complexity: O(t1 + t2)
*/
function getAllElements2(
  root1: TreeNode | null,
  root2: TreeNode | null
): number[] {
  const inorder = (root: TreeNode | null, arr: number[]): void => {
    if (!root) return;
    inorder(root.left, arr);
    arr.push(root.val);
    inorder(root.right, arr);
  };

  const t1: number[] = [];
  const t2: number[] = [];
  inorder(root1, t1);
  inorder(root2, t2);

  const merged: number[] = [];
  let i = 0,
    j = 0;

  while (merged.length !== t1.length + t2.length) {
    if (j === t2.length) merged.push(t1[i++]);
    else if (i === t1.length) merged.push(t2[j++]);
    else merged.push(t1[i] < t2[j] ? t1[i++] : t2[j++]);
  }

  return merged;
}
