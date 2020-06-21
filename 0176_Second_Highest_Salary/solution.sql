
/*
	
  176. Second Highest Salary

  https://leetcode.com/problems/second-highest-salary/
 */


 select (select distinct (Salary) from Employee order by Salary Desc limit 1,1) as SecondHighestSalary