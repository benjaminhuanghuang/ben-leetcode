import { TreeNode } from "./tree";

function buildBinaryTree(
  preorder: number[],
  inorder: number[]
): TreeNode | null {
  const inorderIndexMap = new Map<number, number>();
  for (let i = 0; i < inorder.length; i++) {
    inorderIndexMap.set(inorder[i], i);
  }

  let preorderIndex = 0;

  function buildSubtree(left: number, right: number): TreeNode | null {
    if (left > right) return null;

    const val = preorder[preorderIndex];
    const inorderIndex = inorderIndexMap.get(val)!; // '!' asserts it's not undefined

    const node = new TreeNode(val);
    preorderIndex++;

    // Recursively build left and right subtrees
    node.left = buildSubtree(left, inorderIndex - 1);
    node.right = buildSubtree(inorderIndex + 1, right);

    return node;
  }

  return buildSubtree(0, inorder.length - 1);
}

/*
Time complexity: The time complexity of build_binary_tree is O(n), as it makes one call to the
build_subtree function, which recursively traverses each element in the preorder and inorder
arrays once, resulting in an O(n) runtime.

Space complexity: The space complexity is O(n) due to the space taken up by the recursive call
stack, which can grow as large as the height of the binary tree. The largest possible height of a
binary tree is n. The hash map inorder_indexes_map also takes up O(n) space.
*/
