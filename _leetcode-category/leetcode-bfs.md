# BFS
## Code template
- Path length
```
  int steps = 0;
  queue<T> q;
  unordered_set<T> visited;

  q.push<init_value>;
  visited.insert<init_value>;

  while (q.size())
  {
    int size = q.size();
    while (size--)
    {
      auto curr = q.front();
      q.pop();
        
      q.push(nextLevel);
      }
    }
    ++steps;
  }
``` 
- Check
```
  bool isPrerequisite(int source, int target, vector<vector<int>> graph)
  {
    queue<int> q;
    unordered_set<int> visited;
    q.push(source);
    visited.insert(source);

    while (!q.empty())
    {
      int src = q.front();
      for (auto next : graph[src])
      {
        if (visited.count(next))
        {
          continue;
        }
        if (next == target)
        {
          return true;
        }
        visited.insert(next);
        q.push(next);
      }
    }
    return false;
  }
```

- 433. Minimum Genetic Mutation                     # BFS Shortest Path
- 690. Employee Importance
- 1129. Shortest Path with Alternating Colors
- 1162. As Far from Land as Possible      # queue
- 1306. Jump Game III                     # bfs search 
- 1462. Course Schedule IV

