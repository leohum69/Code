use Assignment123;

--q3.1
SELECT TOP 5 P.ProductID, P.Name, AVG(R.Rating) AS AverageRating
FROM Products P
JOIN Reviews R ON P.ProductID = R.ProductID
GROUP BY P.ProductID, P.Name
ORDER BY AverageRating DESC;

--q3.2 
SELECT C.CustomerID, C.Name
FROM Customers C
LEFT JOIN Reviews R ON C.CustomerID = R.CustomerID
WHERE R.CustomerID IS NOT NULL;

--q3.3
SELECT Cat.CategoryID, Cat.CategoryName, SUM(OI.Quantity * P.Price) AS TotalRevenue
FROM Categories Cat
JOIN Products P ON Cat.CategoryID = P.CategoryID
JOIN OrderItems OI ON P.ProductID = OI.ProductID
GROUP BY Cat.CategoryID, Cat.CategoryName
ORDER BY TotalRevenue DESC;
--q3.4

SELECT C.CustomerID, C.Name, COUNT(DISTINCT P.SellerID) AS SellersCount
FROM Customers C
JOIN Orders O ON C.CustomerID = O.CustomerID
JOIN OrderItems OI ON O.OrderID = OI.OrderID
JOIN Products P ON OI.ProductID = P.ProductID
GROUP BY C.CustomerID, C.Name
HAVING COUNT(DISTINCT P.SellerID) >= 2;
