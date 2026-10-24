/*
23. Merge K Sorted Lists

https://leetcode.com/problems/merge-k-sorted-lists/
*/

/*
   https://www.youtube.com/watch?v=XqA8bBoEdIY HuaHua
   K 个list， 假设所有linked list长度为N
   priority_queue time complexity 为 LogN
   Time Complexity O(N * KlogK) ， 共N*K个元素，每个出入queue一次，queue的size最大为K
   Space Complexity  O(K) + O(N)
   
   C++ 默认priority_queue是将优先级最大的放在队列最前面，即是最大堆， lookup of the largest (by default) element
   priority_queue<int,vector<int>,less<int> > que与priority_queue<int > que是一样
   优先队列队首指向最后，队尾指向最前面的缘故！每次入队元素进去经排序调整后，优先级最大的元素排在最前面，也就是队尾指向的位置，
   这时候队首指向优先级最小的元素！
 */
import { ListNode } from "../Common/ListNode";

import { PriorityQueue } from "./PriorityQueue";
function mergeKLists(lists: ListNode[]): ListNode | null {
  const pq = new PriorityQueue<ListNode>((a, b) => a.val < b.val);

  // add all the list to the priority queue
  for (const list of lists) {
    if (list) {
      pq.add(list);
    }
  }
  const dummy = new ListNode(0);
  let curr = dummy;
  while (!pq.isEmpty()) {
    const node = pq.poll(); // get the smallest node
    curr.next = node as ListNode;
    curr = curr.next;
    if (node!.next) {
      pq.add(node!.next);
    }
  }
  return dummy.next;
}
