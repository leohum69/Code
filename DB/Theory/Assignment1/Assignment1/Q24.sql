use Assignment123;

--q24 ..

SELECT Cat.CategoryID, Cat.CategoryName, SUM(OI.Quantity) AS TotalProductsSold
FROM Categories Cat
JOIN Products P ON Cat.CategoryID = P.CategoryID
JOIN OrderItems OI ON P.ProductID = OI.ProductID
GROUP BY Cat.CategoryID, Cat.CategoryName
HAVING SUM(OI.Quantity) > 10
ORDER BY TotalProductsSold DESC;

--SELECT Cat.CategoryID, Cat.CategoryName, SUM(OI.Quantity) AS TotalProductsSold
--FROM Categories Cat
--JOIN Products P ON Cat.CategoryID = P.CategoryID
--JOIN OrderItems OI ON P.ProductID = OI.ProductID
--GROUP BY Cat.CategoryID, Cat.CategoryName
--ORDER BY TotalProductsSold DESC;
