using System;
using System.Collections.Generic;

 public class Solution582 {
    public IList<int> KillProcess(IList<int> pid, IList<int> ppid, int kill) {
        Dictionary<int, List<int>> dict = new Dictionary<int, List<int>>();
        for (int i =0; i < pid.Count; i++)
        {
            int parent = ppid[i];
            if(!dict.ContainsKey(parent))
                dict[parent] = new List<int>();
            dict[parent].Add(pid[i]);
        }
        
        List<int> res = new List<int>();
        Queue<int> queue = new Queue<int>();
        queue.Enqueue(kill);
        while(queue.Count > 0)
        {
            int process = queue.Dequeue();
            res.Add(process);
            if (dict.ContainsKey(process))
            {
                foreach(var p in dict[process])
                {
                    queue.Enqueue(p);
                }
            }
        }
        return res;
    }
}