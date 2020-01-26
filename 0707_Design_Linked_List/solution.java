package cn.huang.leetcode;

/*
    707. Design Linked List
 */
public class LC_0707_DesignLinkedList {
    class MyLinkedList {
        class Node {
            public int val;
            public Node next;

            public Node(int val) {
                this.val = val;
                this.next = null;
            }

            public Node(int val, Node next) {
                this.val = val;
                this.next = next;
            }
        }

        private Node head;
        private Node tail;
        private int size;

        /**
         * Initialize your data structure here.
         */
        public MyLinkedList() {
            this.head = this.tail = null;
            this.size = 0;
        }

        /**
         * Get the value of the index-th node in the linked list. If the index is invalid, return -1.
         */
        public int get(int index) {
            if (index < 0 || index >= size) return -1;
            return getNode(index).val;
        }

        /**
         * Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
         */
        public void addAtHead(int val) {
            this.head = new Node(val, this.head);
            if (this.size++ == 0)
                this.tail = this.head;
        }

        /**
         * Append a node of value val to the last element of the linked list.
         */
        public void addAtTail(int val) {
            Node n = new Node(val);
            if (this.size++ == 0)
                this.head = this.tail = n;
            else
                this.tail = this.tail.next = n;
        }

        /**
         * Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted.
         */
        public void addAtIndex(int index, int val) {
            if (index < 0 || index > this.size) return;
            if (index == 0)  { this.addAtHead(val); return; }
            if (index == size) { this.addAtTail(val); return; }
            Node prev = this.getNode(index - 1);
            prev.next = new Node(val, prev.next);
            ++this.size;
        }

        /**
         * Delete the index-th node in the linked list, if the index is valid.
         */
        public void deleteAtIndex(int index) {
            if (index < 0 || index >= this.size) return;
            Node prev = this.getNode(index - 1);
            prev.next = prev.next.next;
            if (index == 0) this.head = prev.next;
            if (index == this.size - 1) this.tail = prev;
            --this.size;
        }

        private Node getNode(int index) {
            Node n = new Node(0, this.head);
            while (index-- >= 0) {
                n = n.next;
            }
            return n;
        }
    }
}

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */