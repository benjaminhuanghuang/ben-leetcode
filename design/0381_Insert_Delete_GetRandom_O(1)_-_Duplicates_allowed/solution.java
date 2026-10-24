package cn.huang.leetcode;
/*
381. Insert Delete GetRandom O(1) - Duplicates allowed

Design a data structure that supports all following operations in average O(1) time.
Note: Duplicate elements are allowed.

    insert(val): Inserts an item val to the collection.
    remove(val): Removes an item val from the collection if present.
    getRandom: Returns a random element from current collection of elements. The probability of each element being
    returned is linearly related to the number of same value the collection contains.

Example:

// Init an empty collection.
RandomizedCollection collection = new RandomizedCollection();

// Inserts 1 to the collection. Returns true as the collection did not contain 1.
collection.insert(1);

// Inserts another 1 to the collection. Returns false as the collection contained 1. Collection now contains [1,1].
collection.insert(1);

// Inserts 2 to the collection, returns true. Collection now contains [1,1,2].
collection.insert(2);

// getRandom should return 1 with the probability 2/3, and returns 2 with the probability 1/3.
collection.getRandom();

// Removes 1 from the collection, returns true. Collection now contains [1,2].
collection.remove(1);

// getRandom should return 1 and 2 both equally likely.
collection.getRandom();

 */


import java.util.HashMap;
import java.util.HashSet;
import java.util.Random;

/*
 We can use two maps.

 One tracks the index of the element, so that we can quickly insert and remove.
 The other maps tracks the order of each inserted element, so that we can randomly access any element in time O(1).
 */
public class LC_0381_InsertDeleteGetRandomO1_Duplicatesallowed {
    class RandomizedCollection {
        HashMap<Integer, HashSet<Integer>> map1;   // value, indexes
        HashMap<Integer, Integer> map2;            // index, value
        Random r;

        /** Initialize your data structure here. */
        public RandomizedCollection() {
            map1 = new HashMap<Integer, HashSet<Integer>>();
            map2 = new HashMap<Integer, Integer>();
            r = new Random();
        }

        /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
        public boolean insert(int val) {
            //add to map2
            int size2 = map2.size();
            map2.put(size2+1, val);

            if(map1.containsKey(val)){
                map1.get(val).add(size2+1);
                return false;
            }else{
                HashSet<Integer> set = new HashSet<Integer>();
                set.add(size2+1);
                map1.put(val, set);
                return true;
            }
        }

        /** Removes a value from the collection. Returns true if the collection contained the specified element. */
        public boolean remove(int val) {
            if(map1.containsKey(val)){
                HashSet<Integer> set = map1.get(val);
                int toRemove = set.iterator().next();


                //remove from set of map1
                set.remove(toRemove);

                if(set.size()==0){
                    map1.remove(val);
                }

                if(toRemove == map2.size()){
                    map2.remove(toRemove);
                    return true;
                }

                int size2 = map2.size();
                int key = map2.get(size2);

                HashSet<Integer> setChange = map1.get(key);
                setChange.remove(size2);
                setChange.add(toRemove);



                map2.remove(size2);
                map2.remove(toRemove);

                map2.put(toRemove, key);

                return true;
            }

            return false;
        }

        /** Get a random element from the collection. */
        public int getRandom() {
            if(map1.size()==0)
                return -1;

            if(map2.size()==1){
                return map2.get(1);
            }

            return map2.get(r.nextInt(map2.size())+1); // nextInt() returns a random number in [0, n).
        }
    }
}
