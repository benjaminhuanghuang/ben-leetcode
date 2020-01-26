package cn.huang.leetcode;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.util.List;

/*
    599. Minimum Index Sum of Two Lists
    Suppose Andy and Doris want to choose a restaurant for dinner, and they both have a list of favorite restaurants
    represented by strings.

    You need to help them find out their common interest with the least list index sum.
    If there is a choice tie between answers, output all of them with no order requirement.
    You could assume there always exists an answer.

    Example 1:
    Input:
    ["Shogun", "Tapioca Express", "Burger King", "KFC"]
    ["Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"]
    Output: ["Shogun"]
    Explanation: The only restaurant they both like is "Shogun".

    Example 2:
    Input:
    ["Shogun", "Tapioca Express", "Burger King", "KFC"]
    ["KFC", "Shogun", "Burger King"]
    Output: ["Shogun"]
    Explanation: The restaurant they both like and have the least index sum is "Shogun" with index sum 1 (0+1).
 */
public class LC_0599_MinimumIndexSumofTwoLists {
    /*
        给两个字符串数组，找到坐标位置之和最小的相同的字符串。
        对于这种数组项和其坐标之间关系的题，最先考虑的就是要建立数据和其位置坐标之间的映射。
        我们建立list1的值和坐标的之间的映射，然后遍历list2，如果当前遍历到的字符串在list1中也出现了，那么我们计算两个的坐标之和，
        如果跟我们维护的最小坐标和mn相同，那么将这个字符串加入结果res中，如果比mn小，那么mn更新为这个较小值，然后将结果res清空并加入这个字符串：
     */
    public String[] findRestaurant(String[] list1, String[] list2) {
        List<String> minRes = null;
        Map<String, Integer> map1 = new HashMap<>();
        Map<String, Integer> map2 = new HashMap<>();

        int min = Integer.MAX_VALUE;

        for (int i = 0; i < list1.length; i++) {
            map1.put(list1[i], i);
        }
        for (int i = 0; i < list2.length; i++) {
            map2.put(list2[i], i);
        }

        for (int i = 0; i < list1.length; i++) {
            // 如果map2包含map1的key
            if (map2.containsKey(list1[i])) {
                int sum = map1.get(list1[i]) + map2.get(list1[i]);
                if (sum < min) {
                    min = sum;
                    // minRes始终存储最小的sum，如果有比这个min小的sum,更新并且重置minRes
                    // 多次new 了链表可以考虑在多加一个for循环，判断等于最小值的时候加入链表
                    minRes = new ArrayList<String>();
                    minRes.add(list1[i]);
                } else if (sum == min) {
                    minRes.add(list1[i]);
                }
            }
        }

        String[] results = new String[minRes.size()];
        return minRes.toArray(results);
    }
}
