use Assignment123;

--q6
SELECT C.CustomerID, C.Name, O.OrderDate, COUNT(O.OrderID) AS NumberOfOrders
FROM Customers C
JOIN Orders O ON C.CustomerID = O.CustomerID
GROUP BY C.CustomerID, C.Name, O.OrderDate
HAVING COUNT(O.OrderID) > 1;