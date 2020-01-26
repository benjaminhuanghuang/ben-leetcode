package cn.huang.leetcode;

import cn.huang.leetcode.common.ListNode;

/*
725. Split Linked List in Parts
 */
public class LC_0725_SplitLinkedListinParts {
    public ListNode[] splitListToParts(ListNode root, int k) {
        ListNode[] res = new ListNode[k];
        int len = 0;
        for (ListNode t = root; t != null; t = t.next)
            ++len;

        int avg = len / k, ext = len % k;
        //余数ext就是包含有多余的结点的子链表的个数

        for (int i = 0; i < k && root != null; ++i) {
            res[i] = root;
            //如果i小于ext，就说明当前子链表还得有一个多余结点
            int n = (i < ext)? 1 : 0;
            for (int j = 1; j < (avg + n); ++j) {
                root = root.next;
            }
            ListNode t = root.next;
            root.next = null;
            root = t;
        }
        return res;
    }
}
