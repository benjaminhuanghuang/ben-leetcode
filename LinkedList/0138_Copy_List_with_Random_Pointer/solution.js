/*
138. Copy List with Random Pointer

Level: Medium

https://leetcode.com/problems/copy-list-with-random-pointer
*/

/*
  Solution: 
*/

/**
 * // Definition for a Node.
 * function Node(val, next, random) {
 *    this.val = val;
 *    this.next = next;
 *    this.random = random;
 * };
 */

/**
 * @param {Node} head
 * @return {Node}
 */
var copyRandomList = function (head) {
  if (!head) return null;

  var map = new Map();
  
  // put <original, copied> to the map
  let curr = head;
  while (curr) {
    map.set(curr, new RandomListNode(now.val, null, null));
    curr = curr.next;
  }

  curr = head;
  while (curr) {
    map.get(curr).next = map.get(curr.next) || null;
    map.get(curr).random = map.get(curr.random) || null;
    curr = curr.next;
  }

  return map.get(head);
};
