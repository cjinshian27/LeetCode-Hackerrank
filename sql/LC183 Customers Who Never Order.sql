SELECT name AS Customers
FROM Customers 
WHERE id NOT IN 
(SELECT c.id FROM Customers c, Orders o WHERE c.id = o.customerId);
