DELETE
From Person
WHERE Id NOT IN (SELECT * FROM
                (SELECT MIN(p1.Id)
                FROM Person p1
                GROUP BY p1.Email) AS tmp);
