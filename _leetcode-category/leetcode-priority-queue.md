

In C++, priority_queue is max heap by default, 默认排序是less，也就说大顶堆, 取值时是最大值。
In java priority_queue is min heap by default

## Time complexity

## Code snippets
```
priority_queue<int, vector<int>, less<int>> min_q; // max_heap

// Compare it returns true if its first argument comes before its second argument 
priority_queue<int, vector<int>, greater<int>> max_q; // min_heap    
```

## Problems
628. Maximum Product of Three Numbers