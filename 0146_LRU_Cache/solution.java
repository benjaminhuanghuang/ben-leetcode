package cn.huang.leetcode;

import java.util.*;

/*
146. LRU Cache

Design and implement a data structure for Least Recently Used (LRU) cache.
It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity,
it should invalidate the least recently used item before inserting a new item.

Follow up:
Could you do both operations in O(1) time complexity?

*/

/*
https://www.youtube.com/watch?v=q1Njd3NWvlY

requirement
    Access to a random key in O(1) -> should use hashtable
    Remove the last entry in O(1)  -> need list
    Add/Remove an entry to the front in O(1) -> need list

 */
public class LC_0146_LRUCache {
    public class LRUCache {
        public class ListNode {
            int key, val;
            ListNode prev, next;

            public ListNode(int k, int v) {
                key = k;
                val = v;
                prev = null;
                next = null;
            }
        }

        private int capacity, size;
        private ListNode dummyHead, dummyTail;
        private Map<Integer, ListNode> map;   // key: value

        public LRUCache(int capacity) {
            if (capacity <= 0) {
                throw new IllegalArgumentException("Positive capacity required.");
            }
            this.capacity = capacity;
            size = 0;
            dummyHead = new ListNode(0, 0);
            dummyTail = new ListNode(0, 0);
            dummyTail.prev = dummyHead;
            dummyHead.next = dummyTail;
            map = new HashMap<Integer, ListNode>();
        }

        public int get(int key) {
            if (!map.containsKey(key)) {
                return -1;
            }
            ListNode target = map.get(key);
            // update
            remove(target);
            addToLast(target);
            return target.val;
        }

        public void put(int key, int value) {
            if (map.containsKey(key)) { // update old value of the key
                ListNode target = map.get(key);
                target.val = value;
                // update
                remove(target);
                addToLast(target);
            } else { // insert new key value pair, need to check current size
                if (size == capacity) {
                    map.remove(dummyHead.next.key);
                    remove(dummyHead.next);
                    --size;
                }
                ListNode newNode = new ListNode(key, value);
                map.put(key, newNode);
                addToLast(newNode);
                ++size;
            }
        }

        private void addToLast(ListNode target) {
            target.next = dummyTail;
            target.prev = dummyTail.prev;
            dummyTail.prev.next = target;
            dummyTail.prev = target;
        }

        private void remove(ListNode target) {
            target.next.prev = target.prev;
            target.prev.next = target.next;
        }
    }
}
