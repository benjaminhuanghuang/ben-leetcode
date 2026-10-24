/*
364. Nested List Weight Sum II

https://leetcode.com/problems/nested-list-weight-sum-ii


weight = maxDepth - depth + 1

[LinkedIn]
*/
interface NestedInteger {
  isInteger(): boolean;
  getInteger(): number | null;
  getList(): NestedInteger[];
}

/*
时间复杂度 O(n)，空间 O(n) (queue)
*/
function depthSumInverse(nestedList: NestedInteger[]): number {
  let unweighted = 0;
  let weighted = 0;
  let queue: NestedInteger[] = nestedList;

  while (queue.length > 0) {
    const nextQueue: NestedInteger[] = [];

    for (const ni of queue) {
      if (ni.isInteger()) {
        unweighted += ni.getInteger()!;
      } else {
        nextQueue.push(...ni.getList());
      }
    }

    // 每深入一层，就把当前 unweighted（包含所有上层 + 当前层的 integer）加到 weighted
    // 浅层的整数会被加很多次
    weighted += unweighted;
    queue = nextQueue;
  }

  return weighted;
}

/*
时间复杂度：O(n)，n 为所有整数 + 列表节点总数（遍历两次，但仍是线性） 
空间复杂度：O(d)，d 为最大嵌套深度（递归栈空间）
*/
function depthSumInverse_2(nestedList: NestedInteger[]): number {
  // 先遍历一遍，求最大深度
  let maxDepth = 1;

  function dfsDepth(list: NestedInteger[], depth: number) {
    maxDepth = Math.max(maxDepth, depth);
    for (const ni of list) {
      if (!ni.isInteger()) {
        dfsDepth(ni.getList(), depth + 1);
      }
    }
  }

  dfsDepth(nestedList, 1);

  // 再一遍，计算加权和
  function dfsSum(list: NestedInteger[], depth: number): number {
    let sum = 0;
    for (const ni of list) {
      if (ni.isInteger()) {
        const val = ni.getInteger()!;
        const weight = maxDepth - depth + 1;
        sum += val * weight;
      } else {
        sum += dfsSum(ni.getList(), depth + 1);
      }
    }
    return sum;
  }

  return dfsSum(nestedList, 1);
}
