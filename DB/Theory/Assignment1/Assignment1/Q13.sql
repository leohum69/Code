use Assignment123;

--q13
SELECT C.CustomerID, C.Name
FROM Customers C
JOIN Orders O ON C.CustomerID = O.CustomerID
WHERE O.OrderDate >= DATEADD(DAY, -30, GETDATE());