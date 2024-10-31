use Assignment123;

--q7
SELECT Cat.CategoryID, Cat.CategoryName, SUM(OI.Quantity * P.Price) AS TotalRevenue
FROM Categories Cat
JOIN Products P ON Cat.CategoryID = P.CategoryID
JOIN OrderItems OI ON P.ProductID = OI.ProductID
GROUP BY Cat.CategoryID, Cat.CategoryName
ORDER BY TotalRevenue DESC;