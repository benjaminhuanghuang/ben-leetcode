/*
382. Linked List Random Node

https://leetcode.com/problems/linked-list-random-node/
*/
#include <random>
#include <common/ListNode.h>

using namespace std;

class Solution
{
public:
  /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
  Solution(ListNode *head)
  {
    len = 0;
    ListNode *cur = head;
    this->head = head;
    while (cur)
    {
      ++len;
      cur = cur->next;
    }
  }

  /** Returns a random node's value. */
  int getRandom()
  {
    int t = rand() % len;
    ListNode *cur = head;
    while (t)
    {
      --t;
      cur = cur->next;
    }
    return cur->val;
  }

private:
  int len;
  ListNode *head;
};

/*
Follow up: Reservoir Sampling 
https://www.cnblogs.com/grandyang/p/5759926.html
Follow up 中说链表可能很长，我们没法提前知道长度，这里用到了著名了 水塘抽样 Reservoir Sampling 的思路，
由于限定了 head 一定存在，所以我们先让返回值 res 等于 head 的节点值，然后让 cur 指向 head 的下一个节点，
定义一个变量i，初始化为2，若 cur 不为空我们开始循环，我们在 [0, i - 1] 中取一个随机数，如果取出来0，
那么我们更新 res 为当前的 cur 的节点值，然后此时i自增一，cur 指向其下一个位置，这里其实相当于我们维护了一个
大小为1的水塘，然后我们随机数生成为0的话，我们交换水塘中的值和当前遍历到的值，这样可以保证每个数字的概率相等，
*/
class Solution
{
public:
  /** @param head The linked list's head. Note that the head is guanranteed to be not null, so it contains at least one node. */
  Solution(ListNode *head)
  {
    this->head = head;
  }

  /** Returns a random node's value. */
  int getRandom()
  {
    int res = head->val, i = 2;
    ListNode *cur = head->next;
    while (cur)
    {
      int j = rand() % i;
      if (j == 0)
        res = cur->val;
      ++i;
      cur = cur->next;
    }
    return res;
  }

private:
  ListNode *head;
};