
# Monotonic Stacks
https://www.cnblogs.com/grandyang/p/8887985.html
```
  class MonotonicQueue {
    public:
      void push(int e) {
        while(!data_.empty() && e > data_.back()) 
          data_.pop_back();
        data_.push_back(e);
      } 
      
      void pop() {
        data_.pop_front();
      }
      
      int max() const { 
        return data_.front(); 
      }
    private:
      deque<int> data_;
  };
```
## 特征
对于每一个元素，找“第一个”比它小或大的元素

## problems
- 84. Largest Rectangle in Histogram
- 239. Sliding Window Maximum
- 503. Next Greater Element II
- 739. Daily Temperatures
- 907. Sum of Subarray Minimums

- 1475. Final Prices With a Special Discount in a Shop
