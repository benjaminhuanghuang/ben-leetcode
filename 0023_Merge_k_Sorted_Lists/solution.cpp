/*
23. Merge k Sorted Lists

Level: Hard

https://leetcode.com/problems/merge-k-sorted-lists

21. Merge Two Sorted Lists
*/
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>

#include <algorithm>

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;

/*
  Solution: 
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
  ListNode *mergeKLists_Naive(vector<ListNode *> &lists)
  {
    // put all value in to array

    // sort

    // build result
  }
  /*
    https://www.youtube.com/watch?v=XqA8bBoEdIY HuaHua
    K 个list
    
    Time Complexity O(NKlogK) 共N*K个元素，每个出入queue一次，queue的size最大为K
    Space Complexity  O(K) + O(N)
    C++ 默认priority_queue是将优先级最大的放在队列最前面，即是最大堆， lookup of the largest (by default) element
    priority_queue<int,vector<int>,less<int> > que与priority_queue<int > que是一样
    优先队列队首指向最后，队尾指向最前面的缘故！每次入队元素进去经排序调整后，优先级最大的元素排在最前面，也就是队尾指向的位置，这时候队首指向优先级最小的元素！
  */
  ListNode *mergeKLists(vector<ListNode *> &lists)
  {
    ListNode dummy(-1);
    ListNode *tail = &dummy;
    // A priority queue is a container adaptor that provides constant time lookup of the largest (by default) element,
    //      at the expense of logarithmic insertion and extraction.
    // Compare parameter is defined such that it returns true if its first argument comes before its second
    auto comp = [](ListNode *a, ListNode *b) { return a->val > b->val; };
    priority_queue<ListNode, vector<ListNode *>, decltype(comp)> 
      pq(comp);

    for (ListNode *list : lists)
    {
      {
        if (list)
        {
          pq.push(list);
        }
      }
    }
    while (!pq.empty())
    {
      tail->next = pq.top(); // min val
      pq.pop();
      tail = tail->next;
      if (tail->next)
      {
        pq.push(tail->next);
      }
    }

    return dummy.next;
  }

  /*
    https://www.youtube.com/watch?v=XqA8bBoEdIY
    Divide and conquer

    Time Complexity O(NKlogK) 递归深度为logK，每一层 NK元素
    Space Complexity  O(logK)[递归实现] -> O(1)[非递归实现]
  */
  ListNode *mergeKLists(vector<ListNode *> &lists)
  {
    return merge(lists, 0, lists.size() - 1);
  }

  ListNode *merge(vector<ListNode *> &lists, int l, int r)
  {
    if (l > r)
      return nullptr;
    if (l == r)
      return lists[l];
    if (l + 1 == r)
      return mergeTwoLists(lists[l], lists[r]);
    int m = l + (r - l) / 2;
    auto l1 = merge(lists, l, m);
    auto l2 = merge(lists, m + 1, r);
    return mergeTwoLists(l1, l2);
  }

  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
  {
    ListNode dummy(-1);
    ListNode *tail = &dummy;
    while (l1 && l2)
    {
      if (l1->val > l2->val)
      {
        swap(l1, l2);
      }
      tail->next = l1;
      l1 = l1->next;
      tail = tail->next;
    }
    tail->next = l1 ? l1 : l2;
    return dummy.next;
  }
};