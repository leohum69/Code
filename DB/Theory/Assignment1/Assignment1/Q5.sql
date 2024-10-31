use Assignment123;
--q5
SELECT P.ProductID, P.Name, AVG(R.Rating) AS AverageRating
FROM Products P
JOIN Reviews R ON P.ProductID = R.ProductID
GROUP BY P.ProductID, P.Name
ORDER BY AverageRating DESC;