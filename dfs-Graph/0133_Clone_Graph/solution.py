# Definition for a undirected graph node
class UndirectedGraphNode(object):
    def __init__(self, x):
        self.label = x
        self.neighbors = []

class Solution(object):
    def cloneGraph_dfs(self, node):
        """
        :type node: UndirectedGraphNode
        :rtype: UndirectedGraphNode
        """
        if not node:
            return None

        dic = {}
        return self.dfs(node, dic)

    def dfs(self, node, dic):
        if node in dic:
            return dic[node]

        newNode = UndirectedGraphNode(node.label)
        dic[node] = newNode

        for n in node.neighbors:
            newNode.neighbors.append(self.dfs(n, dic))

        return newNode

    def cloneGraph_bfs(self, node):
        if not node:
            return None

        queue = []
        dic = {}

        queue.append(node)
        nodeCopy = UndirectedGraphNode(node.label)
        dic[node] = nodeCopy

        while queue:
            node_source = queue.pop(0)

            for neighbor_source in node_source.neighbors:
                if neighbor_source in dic:
                    dic[node_source].neighbors.append(dic[neighbor_source])
                else:
                    neighborCopy = UndirectedGraphNode(neighbor_source.label)
                    dic[node_source].neighbors.append(neighborCopy)
                    dic[neighbor_source] = neighborCopy
                    queue.append(neighbor_source)

        return nodeCopy