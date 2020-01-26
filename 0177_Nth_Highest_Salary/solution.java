package cn.huang.leetcode;
/*
177. Nth Highest Salary
 */


/*
http://www.sqltutorial.org/sql-limit/

// N is the offset, 1 is the row moves
 */
public class LC_0177_NthHighestSalary {
    /*
    CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
    BEGIN
      SET N = N - 1;
      RETURN (
          SELECT DISTINCT Salary FROM Employee ORDER BY Salary DESC LIMIT N,1
      );
    END
     */
}
