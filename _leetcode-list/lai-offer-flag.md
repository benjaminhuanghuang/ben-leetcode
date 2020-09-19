# Lai Offer FLAG高频精选面试题讲解 (35)

## 17. Letter Combinations of A Phone Number (https://www.youtube.com/watch?v=uMmFXWs_ZMY) 
Key: String字符, Backtracking

Solution:
- Recursion tree: 
  how may level: n levels, n is string length
  What does each level represent: represent the corresponding possible character

  对照Recursion tree写代码

- Time complexity
  O(branch factor ^ depth) = O(4^n)

- Space complexity O(n + n + n)  call stack N + string + dict


## 23. Merge K Sorted Lists (https://www.youtube.com/watch?v=Uz4fTr34270)
Key: Divide and Conquer, Heap

Naive Solution : 
  Put all numbers into an array and sort
  Time complexity O(n*k*log(n*k)), Space complexity (n*k)

Solution 2: 
  Compare every k nodes (head of every linked list) and get the node with the smallest value
  Time complexity O(n*k), Space complexity O(1)

Solution 3: PriorityQueue
  PriorityQueue can return min/max number in O(logN) time
  Time complexity O(n*logk), Space complexity O(K)
  C++ 默认priority_queue是将优先级最大的放在队列最前面，即是最大堆， lookup of the largest (by default) element
  Default use less<int>, priority_queue<int,vector<int>,less<int> > que与priority_queue<int > que是一样
  优先队列队首指向最后，队尾指向最前面的缘故！每次入队元素进去经排序调整后，优先级最大的元素排在最前面，也就是队尾指向的位置，这时候队首指向优先级最小的元素！


## 33. Search in Rotated Stored Array (https://www.youtube.com/watch?v=7SC0hWGeyBo)
Key: Binary Search

Solution: 
  画图，
  先根据mid与mum[left]的关系，确定mid在哪个区间，
  再根据target与mid，num[left],num[right]的关系确定如何narrow down


## 56. Merge Intervals (https://www.youtube.com/watch?v=VhCITGQVwfQ)
key: 扫描线
Naive Solution : Try to merge every pair, 
  Time complexity O(N^2)

Solution 2: 
  http://zxi.mytechroad.com/blog/geometry/leetcode-56-merge-intervals/
  Time complexity O(NlogN)


## 75. Sort Colors (https://www.youtube.com/watch?v=yTwW8WiGrKw）
key:  in place sort,  3个挡板(pointers)，4个区域， 注意边界

Solution: Two pointers
  https://zxi.mytechroad.com/blog/algorithms/array/leetcode-75-sort-colors/
  Time complexity: O(n)
  Space complexity: O(1)


## 76. Minimum Window Substring (https://youtu.be/9qFR2WQGqkU)
key: Sliding window
Solution:
  Need count the frequency of each distinct character => map
  Need match count


## 91.  Decode Ways (https://www.youtube.com/watch?v=ZLwwc3-vVP4)

- Solution 1: Recursion
  Time O(2^N) N 是树的高度
  Space O(N)   

- Solution 1: Recursion + Memorization
  Time O(1) * (N+1) = O(N) string length
  Space O(N)  

## 124. Binary Tree Maximum Path Sum (https://www.youtube.com/watch?v=WicS0ANkAdY&t=1s)
Recursion


## 138. Copy List with Random Pointer (https://www.youtube.com/watch?v=kGfsMookkzw)
Graph

- Solution 1: Map key=origin node, val=new node
先copy，建立 map 映射，再组装


## 161 - One Edit Distance (https://www.youtube.com/watch?v=U-klJfWOvt8)


## 199. Binary Tree Right Side View

## 200. Number of Islands

## 219. Contains Duplicate II

## 220. Contains Duplicate III

## 224. [Basic Calculator]()|stack| #227  |   |  |
## 243/244/245. [Shortest Word Distance](https://www.youtube.com/watch?v=URtu6Wqq_Mk)|stack| #227  |   |  |
## 277. Find the Celebrity
https://www.youtube.com/watch?v=QDehNYXlCAg"
## 309. Best Time to Buy and Sell Stock with Cooldown
## 311. Sparse Matrix Multiplication[locked]
## 322. Coin Change
## 332. Reconstruct Itinerary

## 450. Delete Node in a BST
## 250 - Count Univalue Subtrees 

## 496. Next Greater Element I
## 503. Next Greater Element II
## 516. Longest Palindromic Subsequence
## 518 - Coin Change II
## 560. Subarray Sum Equals K
https://www.youtube.com/watch?v=aYfwus5T3Bs"
## 632. Smallest Range
https://www.youtube.com/watch?v=csJXQZFYklE"
## 652. Find Duplicate Subtrees
## 692. Top K Frequent Words
https://www.youtube.com/watch?v=0MTNMM7KSRM&t=586s"

    