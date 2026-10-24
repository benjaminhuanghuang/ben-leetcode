package cn.huang.leetcode;

import java.util.HashMap;
import java.util.LinkedHashSet;
import java.util.Map;
import java.util.Objects;

/*
460. LFU Cache [146]

Design and implement a data structure for Least Frequently Used (LFU) cache. It should support the following
operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reaches its capacity, it
should invalidate the least frequently used item before inserting a new item. For the purpose of this problem, when
there is a tie (i.e., two or more keys that have the same frequency), the least recently used key would be evicted.

Follow up:
Could you do both operations in O(1) time complexity?

*/
public class LC_0460_LFUCache {
    /*
    http://bookshadow.com/weblog/2016/11/22/leetcode-lfu-cache/

    head --- FreqNode1 ---- FreqNode2 ---- ... ---- FreqNodeN
              |               |                       |
            first           first                   first
              |               |                       |
           KeyNodeA        KeyNodeE                KeyNodeG
              |               |                       |
           KeyNodeB        KeyNodeF                KeyNodeH
              |               |                       |
           KeyNodeC         last                   KeyNodeI
              |                                       |
           KeyNodeD                                 last
              |
            last


    set(key, value)：

        如果capacity为0，忽略当前操作，结束

        如果keyDict中包含key，则替换其value，更新节点频度，结束

        否则，如果当前keyDict的长度 == capcity，移除head.last（频度最低且最老的KeyNode）

        新增KeyNode(key, value)，加入keyDict，并更新freqDict
    get(key)：

        若keyDict中包含key，则更新节点频度，返回对应的value

        否则，返回-1
        节点频度的更新：

        从keyDict中找到对应的KeyNode，然后通过KeyNode的freq值，从freqDict找到对应的FreqNode

        如果FreqNode的next节点不等于freq + 1，则在其右侧插入一个值为freq + 1的新FreqNode节点

        将KeyNode的freq值+1后，从当前KeyNode链表转移到新的FreqNode对应的KeyNode链表

        如果KeyNode移动之后，原来的FreqNode对应的KeyNode链表为空，则删除原来的FreqNode

        在操作完毕后如果涉及到head的变更，则更新head

     */
    public class LFUCache {
        Node head = null;
        final int capacity;
        Map<Integer, Integer> valueMap;
        Map<Integer, Node> nodeMap;

        public LFUCache(int capacity) {
            this.capacity = capacity;
            valueMap = new HashMap<>(this.capacity, 1f);
            nodeMap = new HashMap<>(this.capacity, 1f);
        }

        public int get(int key) {
            if (valueMap.containsKey(key))
                increase(key, valueMap.get(key));
            return valueMap.getOrDefault(key, -1);
        }

        private void increase(int key, int value) {
            Node node = nodeMap.get(key);
            node.keys.remove(key);
            if (Objects.isNull(node.next))
                node.next = new Node(node, null, 1 + node.count, key);
            else if (node.next.count == node.count + 1)
                node.next.keys.add(key);
            else
                node.next = node.next.prev = new Node(node, node.next, node.count + 1, key);
            nodeMap.put(key, node.next);
            valueMap.put(key, value);
            if (node.keys.isEmpty()) remove(node);
        }

        private void remove(Node node) {
            if (head == node) head = node.next;
            else node.prev.next = node.next;
            if (Objects.nonNull(node.next)) node.next.prev = node.prev;
        }

        public void put(int key, int value) {
            if (0 == this.capacity)
                return;

            if (valueMap.containsKey(key)) {
                increase(key, value);
            } else {
                if (valueMap.size() == this.capacity)
                    remove();
                valueMap.put(key, value);
                add(key);
            }
        }

        private void add(int key) {
            if (Objects.isNull(head)) head = new Node(null, null, 1, key);
            else if (head.count == 1) head.keys.add(key);
            else head = head.prev = new Node(null, head, 1, key);
            nodeMap.put(key, head);
        }

        private void remove() {
            if (Objects.isNull(head)) return;
            int oldest = head.keys.iterator().next();
            head.keys.remove(oldest);
            if (head.keys.isEmpty()) remove(head);
            nodeMap.remove(oldest);
            valueMap.remove(oldest);
        }

        class Node {
            public Node prev, next;
            public final int count;
            public LinkedHashSet<Integer> keys = new LinkedHashSet<>();

            public Node(Node prev, Node next, int count, int key) {
                this.prev = prev;
                this.next = next;
                this.count = count;
                keys.add(key);
            }
        }
    }
}
