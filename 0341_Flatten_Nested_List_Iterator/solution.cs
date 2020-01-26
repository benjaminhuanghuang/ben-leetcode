/*
341. Flatten Nested List Iterator

Given a nested list of integers, implement an iterator to flatten it.

Each element is either an integer, or a list -- whose elements may also be integers or other lists.

Example 1:
Given the list [[1,1],2,[1,1]],

By calling next repeatedly until hasNext returns false, the order of elements returned by next should 
be: [1,1,2,1,1].

Example 2:
Given the list [1,[4,[6]]],

By calling next repeatedly until hasNext returns false, the order of elements returned by next should 
be: [1,4,6].


*/
using System.Collections.Generic;


public class NestedIterator {
    public class NestedInteger
    {
        public NestedInteger(){}
        public bool IsInteger(){return true;}
        public int GetInteger(){return 0;}
        public IList<NestedInteger> GetList(){return null;}
    }

    private IList<NestedInteger> list;
    private Stack<NestedInteger> stack = new Stack<NestedInteger>();
    public NestedIterator(IList<NestedInteger> nestedList) {
        list = nestedList;
        for(int i = nestedList.Count - 1; i >= 0; i--){
            stack.Push(list[i]);
        }
    }

    public bool HasNext() {
         while (stack.Count > 0) 
         {
            NestedInteger t = stack.Peek(); 
            if (t.IsInteger()) 
                return true;
            stack.Pop();
            list = t.GetList();
            for (int i = list.Count - 1; i >= 0; --i) {
                stack.Push(list[i]);
            }
        }
        return false;
    }

    public int Next() {
        NestedInteger t = stack.Pop();
        return t.GetInteger();
    }
}

