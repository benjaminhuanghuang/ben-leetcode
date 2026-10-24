package cn.huang.leetcode;

import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

/*
127. Word Ladder

Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation
sequence from beginWord to endWord, such that:

    Only one letter can be changed at a time.
    Each transformed word must exist in the word list. Note that beginWord is not a transformed word.

Note:

    Return 0 if there is no such transformation sequence.
    All words have the same length.
    All words contain only lowercase alphabetic characters.
    You may assume no duplicates in the word list.
    You may assume beginWord and endWord are non-empty and are not the same.

Example 1:

Input:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

Output: 5

Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Example 2:

Input:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

Output: 0

Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.
 */
public class LC_0127_WordLadder {
    /*

    https://www.youtube.com/watch?v=Sove6q_f-8I
     */
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        //set for fast query
        HashSet<String> set = new HashSet<>(wordList);
        if (set.contains(beginWord)) {
            set.remove(beginWord);
        }
        Queue<String> queue = new LinkedList<>();
        int level = 1;
        int currNum = 1;
        int nextNum = 0;
        queue.offer(beginWord);
        while (!queue.isEmpty()) {
            String word = queue.poll();
            currNum--;
            for (int i = 0; i < word.length(); i++) {
                char[] wordUnit = word.toCharArray();
                for (char j = 'a'; j <= 'z'; j++) {
                    wordUnit[i] = j;
                    String tmp = new String(wordUnit);
                    if (set.contains(tmp)) {
                        if (tmp.equals(endWord)) {
                            return level + 1;
                        }
                        nextNum++;
                        queue.offer(tmp);
                        set.remove(tmp);
                    }
                }
            }
            if (currNum == 0) {
                currNum = nextNum;
                nextNum = 0;
                level++;
            }
        }
        return 0;
    }

    /*
    // http://rainykat.blogspot.com/2017/01/leetcode-127-word-ladderbfs.html
     Use BFS to traverse dictionary. The level is composed of the words that are 1 char diff from curWord. If find such newWord, first check if is end word so we return min length, else check if in dict & remove it to avoid repeat.
        4 loops in total:
        1st queue.isEmpty(); 2nd queue.size() -- current level
                          3rd curword.length() - chose every char; 4th 'a' to 'z' - replace each char

    Note: if use DFS, we need to travel all path to decide the shortest one. If using BFS, we stop once we found since we start from short to find the path
    时间 O(N) 空间 O(N)

    */

    public int ladderLength_better(String beginWord, String endWord, List<String> wordList) {
        HashSet<String> wordDict = new HashSet<>(wordList);
        if (wordDict.contains(beginWord)) {
            wordDict.remove(beginWord);
        }

        Queue<String> queue = new LinkedList<String>();
        // step用来记录跳数
        int step = 2;
        queue.offer(beginWord);
        while(!queue.isEmpty()){
            int size = queue.size();
            // 控制size来确保一次while循环只计算同一层的节点，有点像二叉树level order遍历
            for(int j = 0; j < size; j++){
                String currWord = queue.poll();
                // 循环这个词从第一位字母到最后一位字母
                for(int i = 0; i < endWord.length(); i++){
                    // 循环这一位被替换成25个其他字母的情况
                    for(char letter = 'a'; letter <= 'z'; letter++){
                        StringBuilder sb = new StringBuilder(currWord);
                        sb.setCharAt(i, letter);
                        String tmp = sb.toString();

                        if(wordDict.contains(tmp)){
                            if(tmp.equals(endWord))
                                return step;//endword need to be in dict

                            wordDict.remove(tmp);
                            queue.offer(tmp);
                        }
                    }
                }
            }
            step++;
        }
        return 0;
    }
}
