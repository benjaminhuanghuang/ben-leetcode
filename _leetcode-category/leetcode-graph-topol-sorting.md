# Topological Sorting


## Usage
- Sorting
- Find cycle


The graph should be DAG(Directed Acyclic Graph)

1.从 DAG 图中选择一个 没有前驱（即入度为0）的顶点并输出。
2.从图中删除该顶点和所有以它为起点的有向边。
3.重复 1 和 2 直到当前的 DAG 图为空或当前图中不存在无前驱的顶点为止。后一种情况说明有向图中必然存在环。

## DAG Data structor
- ordered map

- vector<vector<int>>



## toplogical sorting with DFS


```

  for each node:
    if not marked:
      if(dfs(node) == CYCLE) return CYCLE
  return OK


  dfs(node):
    if node is marked as visited: return OK
    if node is marked as visiting: return CYCLE
    mark node as visiting
      for each neighbor in node.neighbors:
        if dfs(neighbor) == CYCLE: return CYCLE
    marked node as visited

    # 最先进入ordered_list实际上最后被访问
    ADD node the head of the ordered_list  # sorted result

    return OK
```



## toplogical sorting
1. 找出所有入度为0的顶点，入栈
2. 选一个栈中元素
  2.1 删除出度
  2.2 如果入度为0，入栈
3. 如果无环，则输出顺序为拓扑排序

## Reference



## Problems
- 201. Course Schedule II
- 207. Course Schedule      # toplogical sort or dfs find cycle