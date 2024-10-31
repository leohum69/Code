use Assignment123;

--q16

SELECT TOP 5 P.ProductID, P.Name, SUM(OI.Quantity) AS TotalSold
FROM Products P
JOIN OrderItems OI ON P.ProductID = OI.ProductID
JOIN Orders O ON OI.OrderID = O.OrderID
WHERE O.OrderDate >= DATEADD(MONTH, -1, GETDATE())
GROUP BY P.ProductID, P.Name
ORDER BY TotalSold DESC;