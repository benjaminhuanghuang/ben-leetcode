# 690. Employee Importance

Difficulty: Easy

[robinhood]

<https://leetcode.com/problems/employee-importance>

## Explain

本质是一个树/图上的子树求和问题：从查询的员工节点出发，用 DFS（或 BFS）遍历他的整棵"下属子树"，把沿途所有员工的 importance 累加起来。所以归类在树/DFS 类分类下。
