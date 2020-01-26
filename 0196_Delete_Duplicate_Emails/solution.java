package cn.huang.leetcode;
/*
196. Delete Duplicate Emails
 */
public class LC_0196_DeleteDuplicateEmails {

    /*
    DELETE FROM Person WHERE Id NOT IN
(SELECT Id FROM (SELECT MIN(Id) Id FROM Person GROUP BY Email) p);

解法二：

DELETE p2 FROM Person p1 JOIN Person p2
ON p2.Email = p1.Email WHERE p2.Id > p1.Id;


解法三：

DELETE p2 FROM Person p1, Person p2
WHERE p1.Email = p2.Email AND p2.Id > p1.Id;
     */
}
