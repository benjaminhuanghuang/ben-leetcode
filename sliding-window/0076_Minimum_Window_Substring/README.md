# 76. Minimum Window Substring

<https://leetcode.com/problems/minimum-window-substring/>

[Facebook][Meta][LinkedIn][Twitter]

## Explain

使用两个指针维护一个窗口，先不断扩大窗口，直到窗口包含 t 的所有字符；然后不断缩小窗口，寻找最短的有效窗口。
最重要的变量：formed: 需要知道当前窗口是否满足要求。
