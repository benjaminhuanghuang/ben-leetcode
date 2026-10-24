package cn.huang.leetcode;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

/*
    705. Design HashSet
 */
public class LC_0705_DesignHashSet {

    class MyHashSet {

        /**
         * Initialize your data structure here.
         */
        List<Integer> list;

        public MyHashSet() {
            list = new ArrayList<>();
        }

        public void add(int key) {
            if (!list.contains(key)) {
                list.add(key);
            }
        }

        public void remove(int key) {
            Iterator<Integer> it = list.iterator();
            while (it.hasNext()) {
                int val = it.next();
                if (val == key) {
                    it.remove();
                    return;
                }
            }
        }

        /**
         * Returns true if this set did not already contain the specified element
         */
        public boolean contains(int key) {
            return list.contains(key);
        }
    }
    //https://blog.csdn.net/fuxuemingzhu/article/details/81016992
}
