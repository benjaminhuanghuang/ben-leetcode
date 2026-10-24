import {
  combine_sorted_linked_lists,
  ListNode,
} from "./combine_sorted_linked_lists";

describe("combine_sorted_linked_lists", () => {
  it("should merge k sorted linked lists", () => {
    // Example Usage
    const l1 = new ListNode(1, new ListNode(4, new ListNode(5)));
    const l2 = new ListNode(1, new ListNode(3, new ListNode(4)));
    const l3 = new ListNode(2, new ListNode(6));

    const merged = combine_sorted_linked_lists([l1, l2, l3]);

    // Print result
    let node = merged;
    const result: number[] = [];
    while (node) {
      result.push(node.val);
      node = node.next;
    }
    console.log(result); // Output: [1, 1, 2, 3, 4, 4, 5, 6]

    expect(result).toEqual([1, 1, 2, 3, 4, 4, 5, 6]);
  });
});
