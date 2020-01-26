/*
685. Redundant Connection II

https://leetcode.com/problems/redundant-connection/
*/

#include <vector>

#include "common/DSU.h"

using namespace std;

/*
https://zxi.mytechroad.com/blog/graph/leetcode-685-redundant-connection-ii/
*/

class Solution
{
public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        DSU s(edges.size() + 1);

        for (const auto &edge : edges)
            if (!s.Union(edge[0], edge[1]))
                return edge;

        return {};
    }
};