# Graph
图的存储方式有两种：邻接矩阵(Adjacency Matrix)和邻接表

- Undirected graph
 只记录边的信息，每个边由两个顶点构成
```
vector<vector<int>>& graph
```

- Directed graph
```
unordered_map<string, priority_queue<string, deque<string>, greater<string>>> _tripsGrpah;
```


## data structure for Graph
- directed graph
```
  graph = vector<vector<int>>(numCourses);
```
or
```
 graph = ordered_map<key, vector<int>>;
```



## 常见题目
- City, Equation, Friends

- DFS find circle

- Find circle, Union found, in-degres

- Topological Sort


## Clone
- 133. Clone Graph      #  use map to prevent duplicate


## Graph traversal / Find path (DFS, BFS)
- Avoid cycles and repetition

- Trade-offs betwee BFS vs DFS

  Depth first search is a bit simpler to implement since it can be done with simple recursion. 
Breadth first search can also be useful to find the **shortest path**, whereas depth first search may
traverse one adjacent node very deeply before ever going onto the immediate neighbors.


### DFS problems
- 841. Keys and Rooms

## 染色法
验证图中的节点否有是否可以分为**两个不相交的集合**

### 染色法 problem

- 785. Is Graph Bipartite?
- 886. Possible Bipartition


## Leetcode problems
-	133. Clone Graph    
-	207. Course Schedule    
-	210. Course Schedule II    
-	261. Graph Valid Tree    
-	269. Alien Dictionary    
-	310. Minimum Height Trees    
-	323. Number of Connected Components in an Undirected Graph    
-	332. Reconstruct Itinerary    
-	399. Evaluate Division    
-	444. Sequence Reconstruction    
-	684. Redundant Connection    
-	685. Redundant Connection II    
-	743. Network Delay Time    
-	765. Couples Holding Hands    
-	785. Is Graph Bipartite?    
- 797. All Paths From Source to Target
-	802. Find Eventual Safe States    
-	839. Similar String Groups    
-	841. Keys and Rooms    
-	854. K-Similar Strings    
- 886. Possible Bipartition [Medium][#785]
-	928. Minimize Malware Spread II    
- 934. Shortest Bridge                                # 多起点，多终点最短路径
-	959. Regions Cut By Slashes [Medium]    
-	990. Satisfiability of Equality Equations [Medium]   
-	996. Number of Squareful Arrays    
-	997. Find the Town Judge    
- 1129. Shortest Path with Alternating Colors
- 1361. Validate Binary Tree Nodes           # indegree
- 1436. Destination City			
- 1466. Reorder Routes to Make All Paths Lead to the City Zero    # BFS
- 1557. Minimum Number of Vertices to Reach All Nodes    # in degree
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			



