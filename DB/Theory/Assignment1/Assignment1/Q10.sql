use Assignment123;

--q10

SELECT C.CustomerID, C.Name, COUNT(O.OrderID) AS NumberOfOrders
FROM Customers C
JOIN Orders O ON C.CustomerID = O.CustomerID
GROUP BY C.CustomerID, C.Name
HAVING COUNT(O.OrderID) > 5;


--SELECT C.CustomerID, C.Name, COUNT(O.OrderID) AS NumberOfOrders
--FROM Customers C
--JOIN Orders O ON C.CustomerID = O.CustomerID
--GROUP BY C.CustomerID, C.Name;
