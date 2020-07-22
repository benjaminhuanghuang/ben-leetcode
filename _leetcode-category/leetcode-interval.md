# Intervals
- 56. Merge Intervals
- 57. Insert Interval
- 435. Non-overlapping Intervals
- 436. Find Right Interval


## Code snippets
```
  // sort
  std::sort(intervals.begin(), intervals.end(),
    [](const vector<int> &a, const vector<int> &b) {
      return a[0] < b[0];
  });

```