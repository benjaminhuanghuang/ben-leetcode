/*

133. Clone Graph

https://leetcode.com/problems/clone-graph/
*/

#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>

using namespace std;

class Node
{
public:
  int val;
  vector<Node *> neighbors;

  Node() {}

  Node(int _val, vector<Node *> _neighbors)
  {
    val = _val;
    neighbors = _neighbors;
  }
};

/*

Solution: Queue + Hashtable

Time complexity: O(V+E)
Space complexity: O(V+E)
*/

class Solution
{
public:
  Node *cloneGraph(Node *node)
  {
    if (!node)
      return nullptr;

    // prevent duplicate
    unordered_map<Node *, Node *> copied;
    copied[node] = new Node(node->val, {});

    queue<Node *> q;
    q.push(node);
    while (!q.empty())
    {
      Node *sourceNode = q.front();
      q.pop();
      for (Node *sourceNeighbor : sourceNode->neighbors)
      {
        if (!copied.count(sourceNeighbor))
        {
          // clone neighbor
          copied[sourceNeighbor] = new Node(sourceNeighbor->val, {});
          q.push(sourceNeighbor);
        }
        // 
        copied[sourceNode]->neighbors.push_back(copied[sourceNeighbor]);
      }
    }
    return copied[node];
  }
};