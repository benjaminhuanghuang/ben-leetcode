/*
184. Department Highest Salary

https://leetcode.com/problems/department-highest-salary/
 */
select
d.Name as Department, e.Name as Employee, e.Salary as Salary
from Department d, Employee e,
(select MAX(Salary) as Salary,  DepartmentId as DepartmentId from Employee GROUP BY DepartmentId) h
where
e.Salary = h.Salary and
e.DepartmentId = h.DepartmentId and
e.DepartmentId = d.Id;

