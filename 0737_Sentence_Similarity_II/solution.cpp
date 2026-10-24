#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>   // for string ==
#include <climits>

#include "common/DSU.h"

using namespace std;

/*
https://zxi.mytechroad.com/blog/hashtable/leetcode-737-sentence-similarity-ii/
DFS / Union Find
*/

 class Solution_DFS {
public:
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<pair<string, string>>& pairs) {
        if (words1.size() != words2.size()) return false;
        
        g_.clear();
        ids_.clear();
        
        for (const auto& p : pairs) {
            g_[p.first].insert(p.second);
            g_[p.second].insert(p.first);
        }        
        
        int id = 0;
        
        for (const auto& p : pairs) {
            if(!ids_.count(p.first)) dfs(p.first, ++id);
            if(!ids_.count(p.second)) dfs(p.second, ++id);
        }
        
        for (int i = 0; i < words1.size(); ++i) {
            if (words1[i] == words2[i]) continue;
            auto it1 = ids_.find(words1[i]);
            auto it2 = ids_.find(words2[i]);
            if (it1 == ids_.end() || it2 == ids_.end()) return false;
            if (it1->second != it2->second) return false;
        }
        
        return true;
    }
private:
    bool dfs(const string& curr, int id) {
        ids_[curr] = id;        
        for (const auto& next : g_[curr]) {
            if (ids_.count(next)) continue;
            if (dfs(next, id)) return true;
        }
        return false;
    }
    
    unordered_map<string, int> ids_;
    unordered_map<string, unordered_set<string>> g_;
};


/*
  Time complexity: O(|Pairs| + |words1|)
  Space complexity: O(|Pairs|)
*/
class Solution_UnionFind {
public:
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<pair<string, string>>& pairs) {
        if (words1.size() != words2.size()) return false;
        
        DSU s(pairs.size() * 2);
        
        unordered_map<string, int> indies; // word to index
        
        for (const auto& pair : pairs) {
            int u = getIndex(pair.first, indies, true);
            int v = getIndex(pair.second, indies, true);
            s.Union(u, v);
        }
        
        for (int i = 0; i < words1.size(); ++i) {
            if (words1[i] == words2[i]) continue;
            int u = getIndex(words1[i], indies);
            int v = getIndex(words2[i], indies);
            if (u < 0 || v < 0) return false;
            if (s.Find(u) != s.Find(v)) return false;
        }
        
        return true;
    }
private:
    int getIndex(const string& word, unordered_map<string, int>& indies, bool create = false) {
        auto it = indies.find(word);
        if (it == indies.end()) {
            if (!create) return INT_MIN;
            int index = indies.size();
            indies.emplace(word, index);
            return index;
        }
        
        return it->second;
    }
};