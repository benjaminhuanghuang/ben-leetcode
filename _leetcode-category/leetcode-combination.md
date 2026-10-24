# Permutation and Combination

-[花花酱 Time/Space Complexity of Recursion Functions SP4]()

- <https://zxi.mytechroad.com/blog/searching/leetcode-39-combination-sum/>

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

<https://zxi.mytechroad.com/blog/searching/leetcode-78-subsets/> [一定要看]

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

- 1. Permutation Sequence
- 1. Combinations
- 1. Subsets
- 1. Beautiful Arrangement

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

- 1. Generate Parentheses
- 1.
- 1. Iterator for Combination

## Problems

- 1. Letter Combinations of a Phone Number
- 1. Next Permutation
- 1. Combination Sum
- 1. Permutation I
- 1. Permutation II
- 1. Subsets
- 1. Letter Tile Possibilities
- 1. Iterator for Combination
