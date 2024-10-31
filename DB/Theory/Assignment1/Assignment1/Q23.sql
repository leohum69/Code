use Assignment123;


--q23 ..

SELECT P.ProductID, P.Name, Cat.CategoryName, OI.Quantity, OI.Quantity * P.Price AS TotalRevenue
FROM Products P
JOIN Categories Cat ON P.CategoryID = Cat.CategoryID
JOIN OrderItems OI ON P.ProductID = OI.ProductID
WHERE Cat.CategoryName = 'Electronics' AND OI.Quantity BETWEEN 5 AND 10
ORDER BY TotalRevenue DESC;

--SELECT P.ProductID, P.Name, Cat.CategoryName, OI.Quantity, OI.Quantity * P.Price AS TotalRevenue
--FROM Products P
--JOIN Categories Cat ON P.CategoryID = Cat.CategoryID
--JOIN OrderItems OI ON P.ProductID = OI.ProductID
--WHERE Cat.CategoryName = 'Electronics'
--ORDER BY TotalRevenue DESC;
