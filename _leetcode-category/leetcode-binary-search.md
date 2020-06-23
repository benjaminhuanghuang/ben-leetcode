# Binary Search
- [花花酱 Binary Search II SP 5](https://www.youtube.com/watch?v=v57lNF2mb_s)
- [花花酱 Binary Search II SP17](https://www.youtube.com/watch?v=J-IQxfYRTto)

问题描述： Given a function g(), returns the **smallest**  m in the range that g(m) is true

要点：小心溢出

## 左闭右开  
  Returns the smallest m in range [l, r) such that g(m) is true.
  Returns r if not found
   左闭右开，小心溢出
```
bool g(int m)
{
  return true;
}

int binary_search(int l, int r)
{
  while (l < r)
  {
    int m = l + (r - l) / 2;
    
    if(f(m)) return m;    // optional
    
    if (g(m))             // left or right
    {
      r = m; // new range [l, m)
    }
    else
    {
      l = m + 1; // new range [m+1, r)
    }
  }
  return l;
}
```
## 左闭右闭
  Returns the smallest m in range [l, r] such that g(m) is true.
  Returns r if not found
```
int binary_search(int l, int r)
{
  while (l <= r)
  {
    int m = l + (r - l) / 2;
    if (g(m))
    {
      r = m - 1; // new rang [l, m-1]
    }
    else
    {
      l = m + 1; // new rang [m+1, r]
    }
  }
  return l;
}
```
## Java Arrays.binarySearch
index of the search key, if it is contained in the array; otherwise, (-(insertion point) - 1). 

The insertion point is defined as the point at which the key would be inserted into the array: the index of the first element greater than the key, or a.length if all elements in the array are less than the specified key. 
Note that this guarantees that the return value will be >= 0 if and only if the key is found.
     
```
private static int binarySearch0(int[] a, int fromIndex, int toIndex, int key) {
    int low = fromIndex;
    int high = toIndex - 1;

    while (low <= high) {
        int mid = (low + high) >>> 1;
        int midVal = a[mid];

        if (midVal < key)
            low = mid + 1;
        else if (midVal > key)
            high = mid - 1;
        else
            return mid; // key found
    }
    return -(low + 1);  // key not found.
}
```




### Binary search problems
-	4. Median of Two Sorted Arrays
-	33. Search in Rotated Sorted Array [*]
-	34. Find First and Last Position of Element in Sorted Array [*]
-	35. Search Insert Position  [*]
-	69. Sqrt(x)     #
-	74. Search a 2D Matrix [*]
-	81. Search in Rotated Sorted Array II
-	153. Find Minimum in Rotated Sorted Array
-	154. Find Minimum in Rotated Sorted Array II
-	162. Find Peak Element
-	240. Search a 2D Matrix II
- 278. First Bad Version                 # 
-	287. Find the Duplicate Number
-	295. Find Median from Data Stream
-	275. H-Index II
-	367. Valid Perfect Square                             # find the number
- 374. Guess Number Higher or Lower                     # find the number
-	378. Kth Smallest Element in a Sorted Matrix
- 441. Arranging Coins                                  # find the number, Special, return the bigest number <= target
-	475. Heaters
-	540. Single Element in a Sorted Array
-	611. Valid Triangle Number
-	633. Sum of Square Numbers
-	658. Find K Closest Elements
-	668. Kth Smallest Number in Multiplication Table
-	729. My Calendar I
-	744. Find Smallest Letter Greater Than Target
-	786. K-th Smallest Prime Fraction
-	875. Koko Eating Bananas
-	911. Online Election
-	1011. Capacity To Ship Packages Within D Days
- 1351. Count Negative Numbers in a Sorted Matrix