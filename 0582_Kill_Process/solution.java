package cn.huang.leetcode;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

/*
582. Kill Process

Given n processes, each process has a unique PID (process id) and its PPID (parent process id).

Each process only has one parent process, but may have one or more children processes. This is just like a tree
structure. Only one process has PPID that is 0, which means this process has no parent process. All the PIDs
will be distinct positive integers.

We use two list of integers to represent a list of processes, where the first list contains PID for each process
and the second list contains the corresponding PPID.

Now given the two lists, and a PID representing a process you want to kill, return a list of PIDs of processes that
will be killed in the end. You should assume that when a process is killed, all its children processes will be killed.
No order is required for the final answer.

Example 1:

Input:
pid =  [1, 3, 10, 5]
ppid = [3, 0, 5, 3]
kill = 5
Output: [5,10]
Explanation:
           3
         /   \
        1     5
             /
            10
Kill 5 will also kill 10.



Note:

    The given kill id is guaranteed to be one of the given PIDs.
    n >= 1.


 */

/*
题目给了我们两个数组，一个是进程的数组，还有一个是进程数组中的每个进程的父进程组成的数组。
题目中说结束了某一个进程，其所有的子进程都需要结束，由于一个进程可能有多个子进程，所以我们首先要理清父子进程的关系。
所以我们使用一个哈希表，建立进程和其所有子进程之间的映射，然后我们首先把要结束的进程放入一个队列queue中，然后while循环，
每次取出一个进程，将其加入结果res中，然后遍历其所有子进程，将所有子进程都排入队列中，这样我们就能结束所有相关的进程，
 */
public class LC_0582_KillProcess {
    public List<Integer> killProcess(List<Integer> pid, List<Integer> ppid, int kill) {
        // 采用邻接表存储
        HashMap<Integer, Node> map = new HashMap<>();
        for (Integer i : pid) {
            map.put(i, new Node(i));
        }

        for (int i = 0; i < ppid.size(); i++) {
            // map中为存储key为0的值
            if (ppid.get(i) != 0) {
                // 注意此时的逻辑
                map.get(ppid.get(i)).childs.add(map.get(pid.get(i)));
            }
        }
        List<Integer> res = new ArrayList<>();
        // 深度优先遍历
        dfs(map.get(kill), res);
        return res;
    }

    public void dfs(Node node, List<Integer> res) {
        if (node == null)
            return;
        res.add(node.id);
        for (Node n : node.childs) {
            dfs(n, res);
        }
    }

    private class Node {
        private Integer id;
        private List<Node> childs;

        public Node(Integer id) {
            this.id = id;
            this.childs = new ArrayList<>();
        }
    }
}
