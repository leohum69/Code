use Assignment123;


--q21
SELECT C.CustomerID, C.Name, O.OrderID, O.OrderNumber, A.AddressLine1, A.City, A.State, A.Zip
FROM Customers C
RIGHT JOIN Orders O ON C.CustomerID = O.CustomerID
LEFT JOIN Addresses A ON C.AddressID = A.AddressID;