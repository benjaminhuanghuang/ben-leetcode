cmp indicates whether the element passed as first argument is considered to go before the second 
```
  sort(ranks.begin(), ranks.end(), [](pair<int, int> &a, pair<int, int> &b) { return a.first > b.first; });
```

## Qucik sort
1. Check range
2. Pick a pivot value in range.
3. While loop, 从两头向中间逼近, compare with pivot
4. do left part, do right part



- 506. Relative Ranks         # sort [number, index]
- 912. Sort an Array
- 1029. Two City Scheduling
- 1030. Matrix Cells in Distance Order    # sort by distance
- 1337. The K Weakest Rows in a Matrix
- 1356. Sort Integers by The Number of 1 Bits


## Merge sort
- 147. Insertion Sort List

## Customize sort
- 435. Non-overlapping Intervals
- 451. Sort Characters By Frequency
- 692. Top K Frequent Words
- 937. Reorder Log Files
- 1366. Rank Teams by Votes                # js version