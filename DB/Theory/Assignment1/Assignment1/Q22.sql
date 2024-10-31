use Assignment123;


--q22
SELECT Cat.CategoryID, Cat.CategoryName, COUNT(P.ProductID) AS TotalProducts, SUM(OI.Quantity * P.Price) AS TotalRevenue
FROM Categories Cat
LEFT JOIN Products P ON Cat.CategoryID = P.CategoryID
LEFT JOIN OrderItems OI ON P.ProductID = OI.ProductID
GROUP BY Cat.CategoryID, Cat.CategoryName
ORDER BY TotalRevenue DESC;
