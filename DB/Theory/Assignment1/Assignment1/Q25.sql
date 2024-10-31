use Assignment123;

--q25 ..

SELECT C.CustomerID, C.Name, COUNT(O.OrderID) AS TotalOrders
FROM Customers C
JOIN Orders O ON C.CustomerID = O.CustomerID
GROUP BY C.CustomerID, C.Name
HAVING COUNT(O.OrderID) > 5
ORDER BY TotalOrders DESC;

--SELECT C.CustomerID, C.Name, COUNT(O.OrderID) AS TotalOrders
--FROM Customers C
--JOIN Orders O ON C.CustomerID = O.CustomerID
--GROUP BY C.CustomerID, C.Name
--ORDER BY TotalOrders DESC;
