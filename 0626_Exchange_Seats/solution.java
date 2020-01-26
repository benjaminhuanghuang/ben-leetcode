package cn.huang.leetcode;
/*

626. Exchange Seats

Mary is a teacher in a middle school and she has a table seat storing students' names and their corresponding seat ids.
The column id is continuous increment.

Mary wants to change seats for the adjacent students.

Can you write a SQL query to output the result for Mary?

+---------+---------+
|    id   | student |
+---------+---------+
|    1    | Abbot   |
|    2    | Doris   |
|    3    | Emerson |
|    4    | Green   |
|    5    | Jeames  |
+---------+---------+

For the sample input, the output is:

+---------+---------+
|    id   | student |
+---------+---------+
|    1    | Doris   |
|    2    | Abbot   |
|    3    | Green   |
|    4    | Emerson |
|    5    | Jeames  |
+---------+---------+

Note:
If the number of students is odd, there is no need to change the last one's seat.
 */
public class LC_0626_ExchangeSeats {
    /*
        select case when id = (select max(id) from seat) and mod(id, 2) = 1 then id when id < (select max(id) from seat) and mod(id, 2) = 1
        then id + 1 when mod(id, 2) = 0 then id - 1 end as id, student from seat order by id
     */
}
