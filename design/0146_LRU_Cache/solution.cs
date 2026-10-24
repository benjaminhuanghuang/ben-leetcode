using System.Collections.Generic;

public class LRUCache {
    private readonly int capacity;
    private Dictionary<int, int> dict;
    private List<int> keyCache;

    public LRUCache(int capacity) {
        this.capacity = capacity;
        this.dict = new Dictionary<int, int>();
        this.keyCache = new List<int>();
    }

    public int Get(int key) {
        if (dict.ContainsKey(key))
        {
            // put the key of recently accessed element at the end of key cache.
            this.keyCache.Remove(key);
            this.keyCache.Add(key);
            return this.dict[key];
        }
        return -1;
    }

    public void Set(int key, int value) {
        if (dict.ContainsKey(key))
        {
            this.dict[key] = value;
            this.keyCache.Remove(key);
            this.keyCache.Add(key);
        }
        else
        {
            if (this.capacity == dict.Count)
            {
                this.dict.Remove(this.keyCache[0]);
                this.keyCache.RemoveAt(0);    
            }   
            this.dict[key] = value;
            this.keyCache.Add(key);
        }       
    }
}