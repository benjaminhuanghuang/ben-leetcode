/*
725. Split Linked List in Parts

Level: Medium

https://leetcode.com/problems/split-linked-list-in-parts
*/
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
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
  vector<ListNode *> splitListToParts(ListNode *root, int k)
  {
    int len = 0;  // length of liked list
    for (ListNode *head = root; head; head = head->next)
      ++len;
    vector<ListNode *> ans(k, nullptr);
    int l = len / k;   // lenght of each group
    int r = len % k;
    ListNode *head = root;
    ListNode *prev = nullptr;
    for (int i = 0; i < k; ++i, --r)
    {
      ans[i] = head;
      for (int j = 0; j < l + (r > 0); ++j)
      {
        prev = head;
        head = head->next;
      }
      if (prev)
        prev->next = nullptr;
    }
    return ans;
  }
};