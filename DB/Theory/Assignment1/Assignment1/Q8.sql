use Assignment123;

--q8 ..
SELECT C.CustomerID, C.Name
FROM Customers C
LEFT JOIN Reviews R ON C.CustomerID = R.CustomerID
WHERE R.CustomerID IS NULL;