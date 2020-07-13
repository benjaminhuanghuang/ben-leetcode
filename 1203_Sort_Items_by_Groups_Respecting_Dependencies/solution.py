'''
1203. Sort Items by Groups Respecting Dependencies

Level: Hard

https://leetcode.com/problems/sort-items-by-groups-respecting-dependencies
'''
'''
  Solution: 

  
'''
class Solution:
    @staticmethod
    def topsort(queue, out_edges, in_degrees):
        ordering = []
        while queue:
            node = queue.popleft()
            ordering.append(node)
            for next_ in out_edges[node]:
                in_degrees[next_] -= 1
                if not in_degrees[next_]: queue.append(next_)
        return ordering
    
    def sortItems(self, n: int, m: int, group: List[int], beforeItems: List[List[int]]) -> List[int]:
        heads = [n + 2 * i for i in range(m)] 
        tails = [n + 2 * i + 1 for i in range(m)]
        nodes = list(range(n + 2 * m)) 
        
        out_edges = defaultdict(list) 
        in_degrees = defaultdict(int)

        # graph processing O(V + E) 
        for item, (g, b) in enumerate(zip(group, beforeItems)):
            if g != -1: 
                head, tail = heads[g], tails[g]
                out_edges[head].append(item); in_degrees[item] += 1
                out_edges[item].append(tail); in_degrees[tail] += 1
            
            for before in b:
                from_, to_ = group[before], group[item]
                same_group = from_ == to_
                out_ = before if same_group or from_ == -1 else tails[from_]
                to_ = item if same_group or to_ == -1 else heads[to_]
                out_edges[out_].append(to_)
                in_degrees[to_] += 1
        
        # apply topological sort
        # O(V + E) time        
        starts = [node for node in nodes if not in_degrees[node]]
        order = []
        for start in starts: 
            order += self.topsort(deque([start]), out_edges, in_degrees)
            
        # remove the sentinel nodes
        order = [node for node in order if node < n]
        return order if len(order) == n else []     