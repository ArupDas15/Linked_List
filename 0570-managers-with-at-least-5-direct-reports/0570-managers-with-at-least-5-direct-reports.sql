# Write your MySQL query statement below
SELECT e.name 
from Employee AS e 
where e.id in (
    SELECT managerId 
    FROM Employee 
    GROUP BY managerId 
    HAVING COUNT(DISTINCT id)>4
);