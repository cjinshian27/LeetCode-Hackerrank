SELECT e1.name AS Employee
FROM employee AS e1, employee AS e2
WHERE e1.salary > e2.salary AND e2.id = e1.managerId