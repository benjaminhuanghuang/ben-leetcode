package cn.huang.leetcode;
/*
641. Design Circular Deque
Design your implementation of the circular double-ended queue (deque).

Your implementation should support following operations:

    MyCircularDeque(k): Constructor, set the size of the deque to be k.
    insertFront(): Adds an item at the front of Deque. Return true if the operation is successful.
    insertLast(): Adds an item at the rear of Deque. Return true if the operation is successful.
    deleteFront(): Deletes an item from the front of Deque. Return true if the operation is successful.
    deleteLast(): Deletes an item from the rear of Deque. Return true if the operation is successful.
    getFront(): Gets the front item from the Deque. If the deque is empty, return -1.
    getRear(): Gets the last item from Deque. If the deque is empty, return -1.
    isEmpty(): Checks whether Deque is empty or not.
    isFull(): Checks whether Deque is full or not.



Example:

MyCircularDeque circularDeque = new MycircularDeque(3); // set the size to be 3
circularDeque.insertLast(1);			// return true
circularDeque.insertLast(2);			// return true
circularDeque.insertFront(3);			// return true
circularDeque.insertFront(4);			// return false, the queue is full
circularDeque.getRear();  			// return 2
circularDeque.isFull();				// return true
circularDeque.deleteLast();			// return true
circularDeque.insertFront(4);			// return true
circularDeque.getFront();			// return 4


 */
public class LC_0641_DesignCircularDeque {
    class MyCircularDeque {
        class DoubleListNode {
            DoubleListNode pre;
            DoubleListNode next;
            int val;
            public DoubleListNode(int val) {
                this.val = val;
            }
        }


        int size;
        int k;
        DoubleListNode head;
        DoubleListNode tail;


        /** Initialize your data structure here. Set the size of the deque to be k. */
        public MyCircularDeque(int k) {
            head = new DoubleListNode(-1);
            tail = new DoubleListNode(-1);
            head.pre = tail;
            tail.next = head;
            this.k = k;
            this.size = 0;
        }

        /** Adds an item at the front of Deque. Return true if the operation is successful. */
        public boolean insertFront(int value) {
            if (size == k)
                return false;
            DoubleListNode node = new DoubleListNode(value);
            node.next = head;
            node.pre = head.pre;
            head.pre.next = node;
            head.pre = node;
            size++;
            return true;
        }

        /** Adds an item at the rear of Deque. Return true if the operation is successful. */
        public boolean insertLast(int value) {
            if (size == k)
                return false;
            DoubleListNode node = new DoubleListNode(value);
            node.next = tail.next;
            tail.next.pre = node;
            tail.next = node;
            node.pre = tail;
            size++;
            return true;
        }

        /** Deletes an item from the front of Deque. Return true if the operation is successful. */
        public boolean deleteFront() {
            if (size == 0)
                return false;
            head.pre.pre.next = head;
            head.pre = head.pre.pre;
            size--;
            return true;
        }

        /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
        public boolean deleteLast() {
            if (size == 0)
                return false;
            tail.next.next.pre = tail;
            tail.next = tail.next.next;
            size--;
            return true;
        }

        /** Get the front item from the deque. */
        public int getFront() {
            return head.pre.val;
        }

        /** Get the last item from the deque. */
        public int getRear() {
            return tail.next.val;
        }

        /** Checks whether the circular deque is empty or not. */
        public boolean isEmpty() {
            return size == 0;
        }

        /** Checks whether the circular deque is full or not. */
        public boolean isFull() {
            return size == k;
        }
    }
}
