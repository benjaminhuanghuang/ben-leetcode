package cn.huang.leetcode;

import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

/*
    690. Employee Importance

    For example, employee 1 is the leader of employee 2, and employee 2 is the leader of employee 3.
    They have importance value 15, 10 and 5, respectively.
    Then employee 1 has a data structure like [1, 15, [2]], and employee 2 has [2, 10, [3]], and employee 3 has [3, 5, []].
    Note that although employee 3 is also a subordinate of employee 1, the relationship is not direct.

    Now given the employee information of a company, and an employee id, you need to return the total importance value of this employee and all his subordinates.


 */
public class LC_0690_EmployeeImportance {
    // Employee info
    class Employee {
        // It's the unique id of each node;
        // unique id of this employee
        public int id;
        // the importance value of this employee
        public int importance;
        // the id of direct subordinates
        public List<Integer> subordinates;
    }

    public int getImportance(List<Employee> employees, int id) {
        HashMap<Integer, Employee> map = new HashMap<>();

        for (Employee e : employees)
            map.put(e.id, e);

        return dfs(id, map);
    }

    private int dfs(int id, HashMap<Integer, Employee> map) {
        Employee e = map.get(id);

        if (e.subordinates.size() == 0)
            return e.importance;

        int imp = e.importance;

        for (int sub : e.subordinates)
            imp += dfs(sub, map);

        return imp;
    }
    public int getImportance_bfs(List<Employee> employees, int id) {
        HashMap<Integer, Employee> map = new HashMap<>();

        for (Employee e : employees)
            map.put(e.id, e);
        LinkedList<Integer> ids = new LinkedList<>();
        ids.push(id);
        int sum =0;
        while(!ids.isEmpty())
        {
            int eId = ids.poll();
            Employee e = map.get(eId);
            sum += e.importance;
            for(int subId: e.subordinates){
                ids.push(subId);
            }
        }
        return sum;
    }
}

