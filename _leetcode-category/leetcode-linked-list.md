# Linked List
- 160. Intersection of Two Linked Lists
- 203. Remove Linked List Elements

## Delete
- 19. Remove Nth Node From End of List          # remove node

- 82. Remove Duplicates from Sorted List II       # pointer for unique
- 83. Remove Duplicates from Sorted List

## Reverse
```
  ListNode *prev = nullptr;
  ListNode *curr = head;

  while (curr)
  {
    ListNode *next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
```
- 24. Swap Nodes in Pairs        # head, n1, n2
- 206. Reverse Linked List
- 234. Palindrome Linked List    # fast-slow pointer and reverse

## Rotate 
- 61. Rotate List


## Slow-fast pointers
```
  auto slow = head;
  auto fast = head->next;

  while (fast != NULL && fast->next != NULL)
  {

  }
```
- 141. Linked List Cycle
- 234. Palindrome Linked List  # fast-slow pointer and reverse
- 876. Middle of the Linked List

## Sycle

## Merge






