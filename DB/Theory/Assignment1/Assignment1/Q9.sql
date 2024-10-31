use Assignment123;

--q9 .. 

SELECT P.ProductID, P.Name, I.QuantityInStock
FROM Products P
JOIN Inventory I ON P.ProductID = I.ProductID
WHERE I.QuantityInStock < (SELECT AVG(QuantityInStock) FROM Inventory);