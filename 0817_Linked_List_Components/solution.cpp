/*
817. Linked List Components

Level: Medium

https://leetcode.com/problems/linked-list-components
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
  int numComponents(ListNode *head, vector<int> &G)
  {
    unordered_set<int> g(G.begin(), G.end());
    int ans = 0;
    while (head)
    {
      // head->nex is null or head->next->val is not in set, that means Find an end of componenet
      if (g.count(head->val) && (!head->next || !g.count(head->next->val)))
        ++ans;
      head = head->next;
    }
    return ans;
  }
};