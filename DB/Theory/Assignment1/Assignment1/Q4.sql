use Assignment123;

--q4
SELECT TOP 5 C.CustomerID, C.Name, SUM(P.Amount) AS TotalSpent
FROM Customers C
JOIN Orders O ON C.CustomerID = O.CustomerID
JOIN Payments P ON O.OrderID = P.OrderID
GROUP BY C.CustomerID, C.Name
ORDER BY TotalSpent DESC;