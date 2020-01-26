package cn.huang.leetcode;
/*
432. All O`one Data Structure

Implement a data structure supporting the following operations:

    Inc(Key) - Inserts a new key with value 1. Or increments an existing key by 1. Key is guaranteed to be a non-empty string.
    Dec(Key) - If Key's value is 1, remove it from the data structure. Otherwise decrements an existing key by 1.
        If the key does not exist, this function does nothing. Key is guaranteed to be a non-empty string.
    GetMaxKey() - Returns one of the keys with maximal value. If no element exists, return an empty string "".
    GetMinKey() - Returns one of the keys with minimal value. If no element exists, return an empty string "".


 Challenge: Perform all these in O(1) time complexity.

 */

import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;

/*
http://bgmeow.xyz/2017/02/15/LeetCode-432/

 */
public class LC_0432_AllOoneDataStructure {
    class AllOne {

        HashMap<Integer, HashSet<String>> wordchest; // it's like a nice little treasure chest with compartments for all of our Strings
        //sorted based on their assigned integer value. HashSet is used for speed, other data structures might work with O(1) time on average.
        HashMap<String,Integer> wordvals; // This is like a table of contents for our treasure chest
        int min;
        int max;
        int numElements;
        /** Initialize your data structure here. */
        public AllOne() {
            wordchest = new HashMap<Integer,HashSet<String>>();
            for(int i=1;i<4;i++) wordchest.put(i,new HashSet<String>());
            wordvals = new HashMap<String,Integer>();
            min = 0;
            max = 0;
        }

        /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
        public void inc(String key) {
            //System.out.println("inc");
            int n = wordvals.getOrDefault(key,0)+1;
            wordvals.put(key,n);
            if(n!=1) {
                wordchest.get(n-1).remove(key);
                if((min==n-1)&&wordchest.get(n-1).size()==0) min++;
                if(wordchest.get(n)==null) wordchest.put(n,new HashSet<String>());
            } else {
                numElements++;
                min=1;
            }
            wordchest.get(n).add(key);
            if(max<n) max++;
        }

        /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
        public void dec(String key) {
            int n = wordvals.getOrDefault(key,0)-1;
            if(n==-1) return;
            if(n<min && n!=0) min=n;
            wordchest.get(n+1).remove(key);
            if(n==0) {
                numElements--;
                if(numElements==1) min=max;

                if(numElements==0){
                    min=0;
                    max=0;
                }  else while(wordchest.get(min).isEmpty()) min++;
                wordvals.remove(key);
                return;
            }
            if(wordchest.get(max).isEmpty()) max--;
            wordvals.put(key,n);
            wordchest.get(n).add(key);

        }


        /** Returns one of the keys with maximal value. */
        public String getMaxKey() {
            //System.out.println(max);
            if(wordchest.get(max)==null) return "";
            Iterator<String> itr = wordchest.get(max).iterator();
            if(!itr.hasNext()) return "";
            String r = itr.next();
            return r;
        }

        /** Returns one of the keys with Minimal value. */
        public String getMinKey() {
            //System.out.println(numElements);
            if(wordchest.get(min)==null) return "";
            Iterator<String> itr = wordchest.get(min).iterator();
            if(!itr.hasNext()) return "";
            String r = itr.next();
            return r;
        }
    }
}
