# Linked List

- 160. Intersection of Two Linked Lists
- 203. Remove Linked List Elements
- 234. Palindrome Linked List    # fast-slow pointer and reverse

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
- 206. Reverse Linked List
- 234. Palindrome Linked List    # fast-slow pointer and reverse

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

## Sycle

## Merge






