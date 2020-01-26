/*
380. Insert Delete GetRandom O(1)

Design a data structure that supports all following operations in average O(1) time.

insert(val): Inserts an item val to the set if not already present.
remove(val): Removes an item val from the set if present.
getRandom: Returns a random element from current set of elements. Each element must have the same 
probability of being returned.


Example:

// Init an empty set.
RandomizedSet randomSet = new RandomizedSet();

// Inserts 1 to the set. Returns true as 1 was inserted successfully.
randomSet.insert(1);

// Returns false as 2 does not exist in the set.
randomSet.remove(2);

// Inserts 2 to the set, returns true. Set now contains [1,2].
randomSet.insert(2);

// getRandom should return either 1 or 2 randomly.
randomSet.getRandom();

// Removes 1 from the set, returns true. Set now contains [2].
randomSet.remove(1);

// 2 was already in the set, so return false.
randomSet.insert(2);

// Since 2 is the only number in the set, getRandom always return 2.
randomSet.getRandom();


 */
using System;
using System.Collections.Generic;

public class RandomizedSet
{

    private Dictionary<int, int> map; // value -> index
    private List<int> list; // value
    private Random rand;
    /** Initialize your data structure here. */
    public RandomizedSet()
    {
        map = new Dictionary<int, int>();
        list = new List<int>();
        rand = new Random();
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    public bool Insert(int val)
    {
        if (map.ContainsKey(val))
            return false;
        map[val] = list.Count;
        list.Add(val);
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    public bool Remove(int val)
    {
        if (!map.ContainsKey(val))
            return false;
        int index = map[val];
        map.Remove(val);
        int last = list[list.Count - 1];
        list.RemoveAt(list.Count - 1);
        if (last != val)
        {
            list[index] = last;
            map[last] = index;
        }
        return true;
    }

    /** Get a random element from the set. */
    public int GetRandom()
    {
        if (list.Count > 0)
        {
            int index = rand.Next(0, list.Count);
            return list[index];
        }
        else
            return 0;
    }
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.Insert(val);
 * bool param_2 = obj.Remove(val);
 * int param_3 = obj.GetRandom();
 */
