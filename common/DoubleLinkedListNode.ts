export class DoubleLinkedListNode {
  val: number;
  prev: DoubleLinkedListNode | null;
  next: DoubleLinkedListNode | null;

  constructor(
    val: number,
    prev: DoubleLinkedListNode | null = null,
    next: DoubleLinkedListNode | null = null
  ) {
    this.val = val;
    this.prev = prev;
    this.next = next;
  }
}
