use Assignment123;

--q19 ..

SELECT P.ProductID, P.Name, I.QuantityInStock, AVG(R.Rating) AS CategoryAverageRating
FROM Products P
JOIN Inventory I ON P.ProductID = I.ProductID
LEFT JOIN Reviews R ON P.ProductID = R.ProductID
JOIN Categories C ON P.CategoryID = C.CategoryID
WHERE R.ProductID IS NULL AND I.QuantityInStock > 0
GROUP BY P.ProductID, P.Name, I.QuantityInStock, C.CategoryID;