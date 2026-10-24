# 937. Reorder Log Files

https://leetcode.com/problems/reorder-data-in-log-files

Log的格式是第一个单词是Log的索引，后面的都是Log的内容。
有两种Log，一种内容是纯数字的，一种内容是纯英文字符的。现在要求，把所有的英文Log放到数字Log前面。
而且如果是纯英文的字符Log，需要按照内容对Log进行排序，当内容相同的时候按照索引排序；
如果是数字Log，保持原来的顺序。
