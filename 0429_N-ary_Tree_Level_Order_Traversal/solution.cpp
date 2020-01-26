/*
429. N-ary Tree Level Order Traversal
https://leetcode.com/problems/n-ary-tree-level-order-traversal/
 */
#include <vector>
#include <queue>
using namespace std;

class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};
/*
Solution1: Recursion

Time complexity: O(n)
Space complexity: O(n)
*/
class Solution
{
public:
    vector<vector<int>> levelOrder(Node *root)
    {
        vector<vector<int>> ans;
        preorder(root, 0, ans);
        return ans;
    }

private:
    void preorder(Node *root, int d, vector<vector<int>> &ans)
    {
        if (root == nullptr)
            return;
        while (ans.size() <= d)
            ans.push_back({});
        ans[d].push_back(root->val);
        for (auto child : root->children)
            preorder(child, d + 1, ans);
    }
};
/*
Solution2 : Iterative 
*/
class Solution
{
public:
    vector<vector<int>> levelOrder(Node *root)
    {
        if (!root)
            return {};
        vector<vector<int>> ans;
        queue<Node *> q;
        q.push(root);
        int depth = 0;
        while (!q.empty())
        {
            int size = q.size();
            ans.push_back({});
            while (size--)
            {
                Node *n = q.front();
                q.pop();
                ans[depth].push_back(n->val);
                for (auto child : n->children)
                    q.push(child);
            }
            ++depth;
        }
        return ans;
    }
};