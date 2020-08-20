# Permutation and Combination
-[花花酱 Time/Space Complexity of Recursion Functions SP4]()
- https://zxi.mytechroad.com/blog/searching/leetcode-39-combination-sum/

permutation是有序的；从n个不同的元素中取出m个元素，按照一定的顺序排成一列，叫做从n个不同元素中取出m个元素的一个permutation(排列)

The number of permutations of n objects taken r at a time
```
    P（n, r) = n!/(n-r)!
```
combination是无序的；从n个不同的元素中取出m个元素并成一组，叫做从n个不同元素中取出m个元素的一个combination(组合)

If the order didn't matter we would have what is the definition of a combination
The number of combinations of n objects taken r at a time is determined by the following formula:
```
    C(n,r) =n!/[(n−r)!r!]
```

## Combination pseudo code
https://zxi.mytechroad.com/blog/searching/leetcode-78-subsets/ [一定要看]

Time complexity O(2^n) two to the power of n
Space complexity O(kn)

因为combination 不关心顺序，所以需要一个start point
```
  C (nums, depth, n, start, curr, answer):
      if depth == n:
          answer.append(curr)
          return
      for i = start to len(nums):  #  i start from s
          curr.push(nums[i])
          C (nums, depth + 1, n, i + 1, curr, answer)
          curr.pop()
```
### Combination Problems
- 60. Permutation Sequence
- 77. Combinations
- 78. Subsets
- 526. Beautiful Arrangement



## Back-tracking 
Time complexity: 
Space complexity: 
```
void dfs(const string& input, int pos, string& combination, vector<string>& ans) {
    if (pos == length()) {
        // Put combination into answer list
        ans.push_back(combination);
        return;
    }
    
    for (const char c : input) {
        // add char
        combination.push_back(c);
        // pos++, recursion
        dfs(digits, digitMap, pos + 1, combination, ans);
        // recover 
        combination.pop_back();
    }
}
```
### Back-tracking problems
- 22. Generate Parentheses
- 77. 
- 1286. Iterator for Combination

## Problems
- 0017. Letter Combinations of a Phone Number
- 0031. Next Permutation
- 0039. Combination Sum
- 0046. Permutation I
- 0047. Permutation II
- 0078. Subsets
- 1079. Letter Tile Possibilities
- 1286. Iterator for Combination