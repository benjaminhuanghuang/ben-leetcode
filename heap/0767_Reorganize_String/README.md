# 767. Reorganize String

https://leetcode.com/problems/reorganize-string/

重新排列字符串，使得相同字符不相邻，如果不可能返回空字符串。

想优先选择剩余次数最多的字符。
如果我们先用低频字符，频率高的字符可能会被迫连续出现，最终无法安排。
选频率高的字符 → 保证它们能“均匀分布”在整个结果中。
