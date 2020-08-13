# Intervals
- 56. Merge Intervals
- 57. Insert Interval
- 435. Non-overlapping Intervals
- 436. Find Right Interval
- 986. Interval List Intersections
- 1288. Remove Covered Intervals


## Code snippets
-  Sort
```

  std::sort(intervals.begin(), intervals.end(),
    [](const vector<int> &a, const vector<int> &b) {
      return a[0] < b[0];
  });

```
- Interction
```
  const int start = max(A[i][0], B[j][0]);
  const int end = min(A[i][1], B[j][1]);
  if (start <= end)
    ...
```