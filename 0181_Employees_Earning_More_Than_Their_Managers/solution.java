package cn.huang.leetcode;

/*
181. Employees Earning More Than Their Managers

 */
public class LC_0181_EmployeesEarningMoreThanTheirManagers {
    /*


SELECT e1.Name AS Employee
FROM Employee e1, Employee e2
WHERE e1.ManagerId = e2.Id
 AND e1.Salary > e2.Salary

 SELECT e1.Name FROM Employee e1, Employee e2
WHERE e1.ManagerId = e2.Id AND e1.Salary > e2.Salary;
     */
}
