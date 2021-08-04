-- Approach I by wx
-- 633 ms
select Employee from (select a.Name as Employee, a.Salary as sa, b.Salary as sb from Employee a Left join Employee b on a.ManagerId =b.Id) as c where sa>sb

-- Approach I: Using WHERE clause [Accepted]
-- 834 ms
SELECT
    a.Name AS 'Employee'
FROM
    Employee AS a,
    Employee AS b
WHERE
    a.ManagerId = b.Id
        AND a.Salary > b.Salary
;

-- Approach II: Using JOIN clause [Accepted]
-- Actually, JOIN is a more common and efficient way to link tables together, and we can use ON to specify some conditions.
-- 382 ms
SELECT
     a.NAME AS Employee
FROM Employee AS a JOIN Employee AS b
     ON a.ManagerId = b.Id
     AND a.Salary > b.Salary
;