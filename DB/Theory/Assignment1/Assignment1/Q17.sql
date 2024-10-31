use Assignment123;


--q17

SELECT TOP 5 O.OrderID, O.OrderNumber, O.OrderDate, C.CustomerID, C.Name, OI.ProductID, OI.Quantity
FROM Orders O
JOIN Customers C ON O.CustomerID = C.CustomerID
JOIN OrderItems OI ON O.OrderID = OI.OrderID
ORDER BY O.OrderDate DESC;