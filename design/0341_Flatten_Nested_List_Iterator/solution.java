package cn.huang.leetcode;

import java.util.Iterator;
import java.util.List;

/*
341. Flatten Nested List Iterator

Given a nested list of integers, implement an iterator to flatten it.

Each element is either an integer, or a list -- whose elements may also be integers or other lists.

Example 1:

Input: [[1,1],2,[1,1]]
Output: [1,1,2,1,1]
Explanation: By calling next repeatedly until hasNext returns false,
             the order of elements returned by next should be: [1,1,2,1,1].

Example 2:

Input: [1,[4,[6]]]
Output: [1,4,6]
Explanation: By calling next repeatedly until hasNext returns false,
             the order of elements returned by next should be: [1,4,6].


 */
public class LC_0341_FlattenNestedListIterator {
    public interface NestedInteger {

        // @return true if this NestedInteger holds a single integer, rather than a nested list.
        public boolean isInteger();

        // @return the single integer that this NestedInteger holds, if it holds a single integer
        // Return null if this NestedInteger holds a nested list
        public Integer getInteger();

        // @return the nested list that this NestedInteger holds, if it holds a nested list
        // Return null if this NestedInteger holds a single integer
        public List<NestedInteger> getList();
    }

    public class NestedIterator implements Iterator<Integer> {

        List<NestedInteger> nestedList;
        int data;
        public NestedIterator(List<NestedInteger> nestedList) {
            this.nestedList = nestedList;
        }

        @Override
        public Integer next() {
            return data;
        }

        @Override
        public boolean hasNext() {
            while(nestedList != null && nestedList.size() > 0){
                NestedInteger tmpInt = nestedList.remove(0);
                if(tmpInt.isInteger()){
                    data = tmpInt.getInteger();
                    return true;
                }else{
                    nestedList.addAll(0,tmpInt.getList());
                }
            }
            return false;
        }
    }
}
