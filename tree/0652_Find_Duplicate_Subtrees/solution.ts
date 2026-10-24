/*
652. Find Duplicate Subtrees

https://leetcode.com/problems/find-duplicate-subtrees/
*/

import { TreeNode } from "../Common/TreeNode";

/*
https://www.youtube.com/watch?v=LYU3y0-59_k FLAG高频精选面试题讲解

Approach 1: DFS, Brute Force:
     get all nodes in the tree [T:O(N), S:O(N)], 
     call recursion areSameTrees for each pair of nodes(for*for*recursion), T:O(N^3), S:O(N)
   

Approach 2: Serialization
    Serialize the tree: [root][left][right]  O(N^2): N nodes, each node needs to serialize the tree
    use a hashmap to store Key: serialized tree, Value: list of the nodes with the same serialized tree

Approach 3: Global Value Numbering
    1. Traverse the tree in a post-order manner
    2. Use a hashmap to store key (root.val, left number, right number), value: the number of the node

    Time Complexity: O(N)
    Space Complexity: O(N)

*/
let nextNumber = 1;
function numberNodes(
  root: TreeNode | null,
  nodeNumbering: Map<TreeNode, number>,
  expressionNumbering: Map<string, number>
): number {
  if (root === null) {
    return 0;
  }

  const leftNumber = numberNodes(root.left, nodeNumbering, expressionNumbering);
  const rightNumber = numberNodes(
    root.right,
    nodeNumbering,
    expressionNumbering
  );

  const expression = new Expression(root.val, leftNumber, rightNumber);
  const expressionKey = expression.hashCode().toString();

  let rootNumber = expressionNumbering.get(expressionKey);
  if (rootNumber === undefined) {
    rootNumber = nextNumber;
    nextNumber++;
    expressionNumbering.set(expressionKey, rootNumber);
  }

  nodeNumbering.set(root, rootNumber);
  return rootNumber;
}
class Expression {
  val: number;
  leftNumber: number;
  rightNumber: number;

  constructor(val: number, leftNumber: number, rightNumber: number) {
    this.val = val;
    this.leftNumber = leftNumber;
    this.rightNumber = rightNumber;
  }

  // Overriding equals and hashCode (or their TypeScript equivalents) may be necessary for correct map behavior.
  equals(other: Expression): boolean {
    return (
      this.val === other.val &&
      this.leftNumber === other.leftNumber &&
      this.rightNumber === other.rightNumber
    );
  }

  // Implementing a hash function for use in a map.
  hashCode(): number {
    const prime = 31;
    let result = 1;
    result = prime * result + this.val;
    result = prime * result + this.leftNumber;
    result = prime * result + this.rightNumber;
    return result;
  }
}

function findDuplicateSubtrees(root: TreeNode | null): Array<TreeNode | null> {
  return [];
}

/*
Hua Hua https://www.youtube.com/watch?v=JLK92dbTt8k

Approach 1: Serialize the tree
    LeetCode 297. Serialize and Deserialize Binary Tree
        serialize(root):
            if not root: return "#"
            return root.val + "," + serialize(root.left) + " " + serialize(root.right)

    if serialize(root) existed, push root to answer
    Time Complexity: O(N^2)
    Space Complexity: O(N^2)

Approach 2: Assign a unique number to each node
    Key: (root.val, id(root.left), id(root.right))
    Time Complexity: O(N)
    Space Complexity: O(N)
*/

function findDuplicateSubtrees_HuaHua(root: TreeNode | null): TreeNode[] {
  const counts: Map<string, number> = new Map();
  const ans: TreeNode[] = [];
  serialize(root, counts, ans);
  return ans;
}

function serialize(
  root: TreeNode | null,
  counts: Map<string, number>,
  ans: TreeNode[]
): string {
  if (!root) return "#";
  // key of the root
  const key = `${root.val},${serialize(root.left, counts, ans)},${serialize(root.right, counts, ans)}`;
  counts.set(key, (counts.get(key) ?? 0) + 1); // key sets

  if (counts.get(key) === 2) {
    ans.push(root);
  }

  return key;
}

function findDuplicateSubtrees_Huahua2(root: TreeNode | null): TreeNode[] {
  // key: id, value: count
  const counts: Map<string, number> = new Map();

  const ans: TreeNode[] = [];
  getId(root, counts, ans);
  return ans;
}

function getId(
  root: TreeNode | null,
  counts: Map<string, number>,
  ans: TreeNode[]
): string {
  if (!root) return "()";

  // Key: (root.val, id(root.left), id(root.right))
  const key = `(${root.val},${getId(root.left, counts, ans)},${getId(root.right, counts, ans)})`;

  counts.set(key, (counts.get(key) ?? 0) + 1); // key sets

  if (counts.get(key) === 2) {
    ans.push(root);
  }

  return key;
}
