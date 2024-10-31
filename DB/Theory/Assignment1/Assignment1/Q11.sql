use Assignment123;

--q11
SELECT TOP 3 O.OrderID, O.OrderNumber, O.OrderDate
FROM Orders O
WHERE O.CustomerID = 1
ORDER BY O.OrderDate DESC;