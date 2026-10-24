/*
692. Top K Frequent Words

Level: Medium

https://leetcode.com/problems/top-k-frequent-words

- 347. Top K Frequent Elements
*/
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>

#include <algorithm>

#include "common/ListNode.h"
#include "common/TreeNode.h"

using namespace std;


/*
  Solution: 

  http://zxi.mytechroad.com/blog/heap/leetcode-692-top-k-frequent-words/

   priority_queue 
   O(n log k) / O(n)
*/

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> count;
        for (const string& word : words)
            ++count[word];
        
        auto comparator = [](const pair<string, int>& a, const pair<string, int>& b) {
            // order by alphabet ASC
            if (a.second == b.second) 
                return  a.first < b.first;
            // order by freq DESC
            return a.second > b.second;
        };
        
        // Min heap by frequency
        priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(comparator)> q(comparator);
        
        // O(n*logk)
        for (const auto& kv : count) {
            q.push(kv);
            if (q.size() > k) q.pop();
        }
        
        vector<string> ans;
        
        while (!q.empty()) {
            ans.push_back(q.top().first);
            q.pop();
        }
        
        std::reverse(ans.begin(), ans.end());
        return ans; 
    }
};