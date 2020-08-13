# DFS
1. 检测参数，指定返回条件
2. dfs 函数参数： data，index
3. template
```
  // terminator


  // process

  // drill

  // clear status
```
## DFS Tempalte
```
  class dfs_solution {
  private:
    dfsHelper( data, index, combination, ans ){
      if(condition)
      {
        return;
      }
      do_something();
      for(){
        combination.push()
        dfsHelper();
        combination.pop()
      }
    }

  public:
    main() {
      res = dfsHelper(data,  0, empay_combination, ans)
    }
  }
```


- 120. Triangle                          # DP, or DFS
- 130. Surrounded Regions
- 200. Number of Islands                 # [!] No back track
- 301. Remove Invalid Parentheses        # r, l 
- 491. Increasing Subsequences           # **
- 690. Employee Importance
- 698. Partition to K Equal Sum Subsets
- 733. Flood Fill                        # typical
- 797. All Paths From Source to Target   # backtracking 
- 949. Largest Time for Given Digits
- 1415. The k-th Lexicographical String of All Happy Strings of Length n
- 1219. Path with Maximum Gold