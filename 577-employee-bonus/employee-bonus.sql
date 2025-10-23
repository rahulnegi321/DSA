# Write your MySQL query statement below
SELECT e.name,b.bonus
FROM Employee as e
LEFT JOIN 
Bonus AS b ON e.empID = b.empId
WHERE (b.bonus is null OR b.bonus < 1000)
