package cn.huang.leetcode;
/*
184. Department Highest Salary
 */
public class LC_0184_DepartmentHighestSalary {
    /*
    select Department.Name as Department,
　　　　Employee.Name as Employee,
　　　　Employee.Salary as Salary
from Department join Employee
　　　on Department.Id = Employee.DepartmentId
where (Department.Id, Employee.Salary) in
　　　(select DepartmentId, max(Salary) from Employee group by DepartmentId);


select
d.Name as Department, e.Name as Employee, e.Salary as Salary
from Department d, Employee e,
(select MAX(Salary) as Salary,  DepartmentId as DepartmentId from Employee GROUP BY DepartmentId) h
where
e.Salary = h.Salary and
e.DepartmentId = h.DepartmentId and
e.DepartmentId = d.Id;

     */
}
