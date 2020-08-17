# Linked List
- 147. Insertion Sort List
- 160. Intersection of Two Linked Lists
- 203. Remove Linked List Elements
- 430. Flatten a Multilevel Doubly Linked List      # tail
- 725. Split Linked List in Parts
- 817. Linked List Components


## Delete
- 19. Remove Nth Node From End of List          # remove node

- 82. Remove Duplicates from Sorted List II       # pointer for unique
- 83. Remove Duplicates from Sorted List
- 1171. Remove Zero Sum Consecutive Nodes from Linked List

## Reverse
```
  ListNode *prev = nullptr;
  ListNode *curr = head;


  // return the tail as header
  while (curr)
  {
    ListNode *next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }

  // keep the header
  for (int i = m; i < n; ++i)
  {
    ListNode *t = curr->next;
    curr->next = t->next;
    t->next = prev->next;
    prev->next = t;
  }
```
- 24. Swap Nodes in Pairs        # head, n1, n2
- 92. Reverse Linked List II
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
- 109. Convert Sorted List to Binary Search Tree            # three points
- 141. Linked List Cycle
- 234. Palindrome Linked List  # fast-slow pointer and reverse
- 876. Middle of the Linked List

## Sycle

## Merge
```
```


## Reorder

- 143. Reorder List
- 328. Odd Even Linked List       #  p = p->next 





