package cn.huang.leetcode;
/*
339. Nested List Weight Sum

Given a nested list of integers, return the sum of all integers in the list weighted by their depth.

Each element is either an integer, or a list -- whose elements may also be integers or other lists.

Example 1:
Given the list [[1,1],2,[1,1]], return 10. (four 1's at depth 2, one 2 at depth 1)

Example 2:
Given the list [1,[4,[6]]], return 27. (one 1 at depth 1, one 4 at depth 2, and one 6 at depth 3; 1 + 4*2 + 6*3 = 27)


*/

import cn.huang.leetcode.common.NestedInteger;

import java.util.List;

/*
思路: 一个比较简单的DFS, 因为数组中的每一个元素都可能包含另外一个数组, 因此这是一个多层嵌套的关系,
但是嵌套的层数需要有个记录, 所以我们只需要另外写一个函数, 记录当前是第几层即可.

 */
public class LC_0339_NestedListWeightSum {
    public int depthSum(List<NestedInteger> nestedList) {
        return helper(nestedList, 1);
    }

    public int helper(List<NestedInteger> nestedList, int depth) {
        if (nestedList == null || nestedList.size() == 0)
            return 0;

        int sum = 0;
        for (NestedInteger ni : nestedList) {
            if (ni.isInteger()) {
                sum += ni.getInteger() * depth;
            } else {
                sum += helper(ni.getList(), depth + 1);
            }
        }

        return sum;
    }
}
