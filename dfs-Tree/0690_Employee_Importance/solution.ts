class Employee {
  id: number;
  importance: number;
  subordinates: number[];

  constructor(id: number, importance: number, subordinates: number[]) {
    this.id = id;
    this.importance = importance;
    this.subordinates = subordinates;
  }
}

/*
Build an id -> Employee map for O(1) lookup, then DFS down the
subordinate tree starting at `id`, summing importance along the way.

Time complexity: O(n) — each employee is visited once.
Space complexity: O(n) — the map plus recursion stack.
*/
function getImportance(employees: Employee[], id: number): number {
  // Map id -> employee
  const byId = new Map<number, Employee>();
  for (const employee of employees) byId.set(employee.id, employee);

  function dfs(employeeId: number): number {
    const employee = byId.get(employeeId)!;
    let total = employee.importance;
    for (const subordinateId of employee.subordinates) {
      total += dfs(subordinateId);
    }
    return total;
  }

  return dfs(id);
}

export {};
