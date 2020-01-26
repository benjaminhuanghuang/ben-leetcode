package cn.huang.leetcode;
/*
262. Trips and Users

 */
public class LC_0262_TripsandUsers {
    /*
SELECT Request_at Day, ROUND(COUNT(IF(Status != 'completed', TRUE, NULL)) / COUNT(*), 2) 'Cancellation Rate'
FROM Trips WHERE (Request_at BETWEEN '2013-10-01' AND '2013-10-03') AND Client_Id IN
(SELECT Users_Id FROM Users WHERE Banned = 'No') GROUP BY Request_at;
     */
}
