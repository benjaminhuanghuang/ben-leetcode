package cn.huang.leetcode;
/*
177. Nth Highest Salary

https://leetcode.com/problems/nth-highest-salary/
*/


/*
http://www.sqltutorial.org/sql-limit/

// N is the offset, 1 is the row moves

CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  SET N = N - 1;
  RETURN (
      SELECT DISTINCT Salary FROM Employee ORDER BY Salary DESC LIMIT N,1
  );
END

