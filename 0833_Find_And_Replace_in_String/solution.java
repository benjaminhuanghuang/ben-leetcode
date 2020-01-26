package cn.huang.leetcode;

import java.util.*;

/*
833. Find And Replace in String

To some string S, we will perform some replacement operations that replace groups of letters with new ones (not necessarily the same size).

Each replacement operation has 3 parameters: a starting index i, a source word x and a target word y.  The rule is that if x starts at position i in the original string S, then we will replace that occurrence of x with y.  If not, we do nothing.

For example, if we have S = "abcd" and we have some replacement operation i = 2, x = "cd", y = "ffff", then because "cd" starts at position 2 in the original string S, we will replace it with "ffff".

Using another example on S = "abcd", if we have both the replacement operation i = 0, x = "ab", y = "eee", as well as another replacement operation i = 2, x = "ec", y = "ffff", this second operation does nothing because in the original string S[2] = 'c', which doesn't match x[0] = 'e'.

All these operations occur simultaneously.  It's guaranteed that there won't be any overlap in replacement: for example, S = "abc", indexes = [0, 1], sources = ["ab","bc"] is not a valid test case.

Example 1:

Input: S = "abcd", indexes = [0,2], sources = ["a","cd"], targets = ["eee","ffff"]
Output: "eeebffff"
Explanation: "a" starts at index 0 in S, so it's replaced by "eee".
"cd" starts at index 2 in S, so it's replaced by "ffff".

Example 2:

Input: S = "abcd", indexes = [0,2], sources = ["ab","ec"], targets = ["eee","ffff"]
Output: "eeecd"
Explanation: "ab" starts at index 0 in S, so it's replaced by "eee".
"ec" doesn't starts at index 2 in the original S, so we do nothing.

Notes:

    0 <= indexes.length = sources.length = targets.length <= 100
    0 < indexes[i] < S.length <= 1000
    All characters in given inputs are lowercase letters.

 */

/*
将indexes按逆序排序，然后对S从右往左依次查找可替换的单词，如果出现在指定位置，则替换。由于indexes排序后，会变化，因此需要用map结构保存原来的索引。
技巧：

    将indexes按逆序排序；
    对字符串从右往左处理；

 */
public class LC_0833_FindAndReplaceinString {
    public String findReplaceString(String S, int[] indexes, String[] sources, String[] targets) {
        Map<Integer, Integer> map = new HashMap<>();
        List<Integer> indList =new ArrayList<>();
        int n = indexes.length;
        for(int i = 0; i < n; i++) {
            map.put(indexes[i], i);
            indList.add(indexes[i]);
        }

        Collections.sort(indList);

        for(int i = n - 1; i >= 0; i--) {// 从右往左替换
            int pos = indList.get(i);
            int curInd = map.get(pos);
            if(S.indexOf(sources[curInd], pos) == pos) {// 检查sources[curInd]是否出现在指定pos，如果出现，则替换
                S = S.substring(0, pos) + targets[curInd] + S.substring(pos + sources[curInd].length());
            }
        }

        return S;
    }
}
