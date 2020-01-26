package cn.huang.leetcode;
/*
185. Department Top Three Salaries

 */
public class LC_0185_DepartmentTopThreeSalaries {
    /*
SELECT d.Name AS Department, e.Name AS Employee, e.Salary FROM Employee e
JOIN Department d on e.DepartmentId = d.Id
WHERE (SELECT COUNT(DISTINCT Salary) FROM Employee WHERE Salary > e.Salary
AND DepartmentId = d.Id) < 3 ORDER BY d.Name, e.Salary DESC;

     */
}
