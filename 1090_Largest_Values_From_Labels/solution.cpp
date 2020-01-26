/*
1090. Largest Values From Labels
https://leetcode.com/problems/largest-values-from-labels/

We have a set of items: the i-th item has value values[i] and label labels[i].

Then, we choose a subset S of these items, such that:

    |S| <= num_wanted
    For every label L, the number of items in S with label L is <= use_limit.

Return the largest possible sum of the subset S.
 */
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
using namespace std;

/*
https://www.cnblogs.com/rookielet/p/11037560.html
 */
class Solution
{
public:
    int largestValsFromLabels(vector<int> &values, vector<int> &labels, int num_wanted, int use_limit)
    {
        //优先出列判定为!cmp，所以values大的先出列
        auto cmp = [&values](int a, int b) { return values[a] < values[b];};
        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
 
        for (int i = 0; i < values.size(); i++)
        {
            pq.push(i);   // sort i by values[i]
        }
        map<int, int> labelCounter;
        int res = 0;
        while (!pq.empty() && num_wanted > 0)
        {
            int index = pq.top();
            pq.pop();
            int value = values[index];
            int label = labels[index];

            if (labelCounter[label] < use_limit)
            {
                res += value;
                num_wanted--;
                labelCounter[label]++;
            }
        }
        return res;
    }
};

/*
    Sort all labels by value. Then, start with the largest value, greedily pick labels. 
    Track how many labels we have used in m, and do not pick that label if we reached the limit.
 */
class Solution2
{
public:
    int largestValsFromLabels(vector<int> &vs, vector<int> &ls, int wanted, int limit, int res = 0)
    {
        // Multimap is an associative container that contains a sorted list of key-value pairs, 
        // while permitting multiple entries with the same key. 
        // Sorting is done according to the comparison function Compare, applied to the keys.
        multimap<int, int> s;
        unordered_map<int, int> m;
        for (auto i = 0; i < vs.size(); ++i)
            s.insert({vs[i], ls[i]});
        for (auto it = rbegin(s); it != rend(s) && wanted > 0; ++it)
        {
            if (++m[it->second] <= limit)
            {
                res += it->first;
                --wanted;
            }
        }
        return res;
    }
};