# 419. Battleships in a Board

Level: Medium

<https://leetcode.com/problems/battleships-in-a-board>

这份代码不是 DFS，是纯线性扫描，没有递归/visited 标记。

它利用了题目保证的约束（战舰一定是直线、互不相邻）：对每个 'X'，只有当它是整条战舰的"起点"（上方和左方都不是同色的 'X'）时才计数，否则说明这个 'X' 属于已经数过的战舰，跳过。O(1) 额外空间，比 DFS 更省。

这题也可以用 DFS 解（跟 Number of Islands 一样：遇到没访问过的 'X' 就 flood-fill 整艘船，标记 visited，计数+1），

Number of Islands 不能用这个解法， 战舰依赖"保证是直线、不相邻"这个特殊约束。
Number of Islands 的岛可以是任意形状（比如 L 形、带凹角的形状），没有这个保证。
