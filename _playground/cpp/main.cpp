#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <map>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <set>
#include <utility>
#include <numeric>
using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *removeZeroSumSublists(ListNode *head)
{
  ListNode dummy(0);
  dummy.next = head;
  ListNode *prev = &dummy;
  ListNode *curr = prev->next;
  unordered_map<int, ListNode *> m{{0, prev}};
  int s = 0;
  while (curr)
  {
    s += curr->val;
    if (m.count(s))
    {
      m[s]->next = curr->next; // skip
    }
    else
      m[s] = curr;

    prev = curr;
    curr = curr->next;
  }
  return dummy.next;
}

int main()
{

  vector<int> vals = {1, 3, 2, -3, -2, 5, 5, -5, 1};
  ListNode *a = new ListNode(1);
  ListNode *head = a;
  for (int i = 1; i < vals.size(); i++)
  {
    head->next = new ListNode(vals[i]);
    head = head->next;
  }

  auto result = removeZeroSumSublists(a);
  return 0;
}