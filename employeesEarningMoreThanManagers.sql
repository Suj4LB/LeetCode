--Q.- Write a solution to find the employees who earn more than their managers.
-- Return the result table in any order.

+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| id          | int     |
| name        | varchar |
| salary      | int     |
| managerId   | int     |
+-------------+---------+
id is the primary key (column with unique values) for this table.
Each row of this table indicates the ID of an employee, their name, salary, and the ID of their manager.

Solution - 

SELECT t1.name as Employee
FROM Employee AS t1
INNER JOIN Employee AS t2 ON t1.managerId=t2.id
WHERE t1.salary > t2.salary
