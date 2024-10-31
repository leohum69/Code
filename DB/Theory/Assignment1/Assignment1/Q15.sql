use Assignment123;

--q15

SELECT S.SellerID, S.Name, SUM(OI.Quantity) AS TotalProductsSold
FROM Sellers S
JOIN Products P ON S.SellerID = P.SellerID
JOIN OrderItems OI ON P.ProductID = OI.ProductID
GROUP BY S.SellerID, S.Name
ORDER BY TotalProductsSold DESC;