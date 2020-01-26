package cn.huang.leetcode;

import java.util.*;

/*
692. Top K Frequent Words
Given a non-empty list of words, return the k most frequent elements.

Your answer should be sorted by frequency from highest to lowest. If two words have the same frequency, then
the word with the lower alphabetical order comes first.

Example 1:

Input: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
Output: ["i", "love"]
Explanation: "i" and "love" are the two most frequent words.
    Note that "i" comes before "love" due to a lower alphabetical order.

Example 2:

Input: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
Output: ["the", "is", "sunny", "day"]
Explanation: "the", "is", "sunny" and "day" are the four most frequent words,
    with the number of occurrence being 4, 3, 2 and 1 respectively.

Note:

    You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
    Input words contain only lowercase letters.

Follow up:

    Try to solve it in O(n log k) time and O(n) extra space.

 */


/*
一看到复杂度nlogk，就应该知道用堆排序，维护一个k大小的堆。
make_heap:O(k)
pop_heap:O(logk)
push_heap:O(logk)
 */
public class LC_0692_TopKFrequentWords {
    /*
    https://www.youtube.com/watch?v=0MTNMM7KSRM
     */

    private Comparator<Map.Entry<String, Integer>> byDescendingFrequency
            = Comparator.comparing(Map.Entry<String, Integer>::getValue).reversed()
            .thenComparing(Map.Entry<String, Integer>::getKey);


    private HashMap<String, Integer> countWords(String[] words){
        HashMap<String, Integer> wordCounts = new HashMap<String, Integer>();
        for(String w: words){
            int count = wordCounts.getOrDefault(w, 0);
            wordCounts.put(w, count+1);
        }
        return wordCounts;
    }

    public List<String> topKFrequent(String[] words, int k) {
        List<String> result = new ArrayList<String>();

        HashMap<String, Integer> wordCounts = countWords(words);

        PriorityQueue<Map.Entry<String, Integer>> q = new PriorityQueue<>(wordCounts.size(), byDescendingFrequency);

        for(Map.Entry<String, Integer> entry: wordCounts.entrySet())
        {
            q.add(entry);
        }

        for(int i =0;i < k; i++)
        {
            result.add(q.remove().getKey());
        }

        return result;
    }
}























