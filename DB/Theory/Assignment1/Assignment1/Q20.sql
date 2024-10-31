use Assignment123;

--q20 
WITH ProductSales AS (
    SELECT P.ProductID, P.Name, SUM(OI.Quantity) AS TotalSales
    FROM Products P
    JOIN OrderItems OI ON P.ProductID = OI.ProductID
    JOIN Orders O ON OI.OrderID = O.OrderID
    GROUP BY P.ProductID, P.Name
)
SELECT TOP 3 PS.ProductID, PS.Name, PS.TotalSales, R.Rating, R.ReviewText
FROM ProductSales PS
LEFT JOIN Reviews R ON PS.ProductID = R.ProductID
ORDER BY PS.TotalSales DESC;
