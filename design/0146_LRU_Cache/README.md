# 146. LRU Cache

Difficulty: Medium

<https://leetcode.com/problems/lru-cache>

Related Problem # 460. LFU Cache

Design and implement a data structure for Least Recently Used (LRU) cache.
It should support the following operations: get and set.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache,
otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present. When the cache
reached its capacity, it should invalidate the least recently used item before inserting a new item.

保证最近被访问过的数据在cache中
