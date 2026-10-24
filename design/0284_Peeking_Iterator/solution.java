package cn.huang.leetcode;

import java.util.Iterator;

/*
284. Peeking Iterator
Given an Iterator class interface with methods: next() and hasNext(), design and implement a PeekingIterator that
support the peek() operation -- it essentially peek() at the element that will be returned by the next call to next().

Example:

Assume that the iterator is initialized to the beginning of the list: [1,2,3].

Call next() gets you 1, the first element in the list.
Now you call peek() and it returns 2, the next element. Calling next() after that still return 2.
You call next() the final time and it returns 3, the last element.
Calling hasNext() after that should return false.

Follow up: How would you extend your design to be generic and work with all types, not just integer?

 */
public class LC_0284_PeekingIterator {
    class PeekingIterator implements Iterator<Integer> {
        Iterator<Integer> itr;
        //设一个 peeked 的flag 同时 保存 peeked 过得值.  如果已经peeked过了, next()直接返回保存的值即可.
        boolean peeked;
        int peekVal;

        public PeekingIterator(Iterator<Integer> iterator) {
            // initialize any member here.
            this.itr = iterator;
        }

        // Returns the next element in the iteration without advancing the iterator.
        public Integer peek() {
            if (peeked) {
                return peekVal;
            } else {
                peeked = true;
                peekVal = itr.next();
                return peekVal;
            }
        }

        // hasNext() and next() should behave the same as in the Iterator interface.
        // Override them if needed.
        @Override
        public Integer next() {
            if (peeked) {
                peeked = false;
                return peekVal;
            } else return itr.next();
        }

        @Override
        public boolean hasNext() {
            return peeked || itr.hasNext();
        }
    }
}
