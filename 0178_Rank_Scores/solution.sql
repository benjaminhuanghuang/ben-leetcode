/*
178. Rank Scores

https://leetcode.com/problems/rank-scores/

*/

--- MS SQL Server
SELECT Score,
(SELECT COUNT(DISTINCT Score) FROM Scores WHERE Score >= s.Score) Rank
FROM Scores s ORDER BY Score DESC;


-- 解法二：

SELECT Score,
(SELECT COUNT(*) FROM (SELECT DISTINCT Score s FROM Scores) t WHERE s >= Score) Rank
FROM Scores ORDER BY Score DESC;
