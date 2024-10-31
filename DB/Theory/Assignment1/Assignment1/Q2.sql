use Assignment123;

-- Insert into Categories
INSERT INTO Categories (CategoryID, CategoryName)
VALUES (1, 'Electronics'), (2, 'Fashion'), (3, 'Books'), (4, 'Home Appliances'), (5, 'Sports');

-- Insert into Sellers
INSERT INTO Sellers (SellerID, Name, ContactInfo)
VALUES 
(1, 'TechStore', 'tech@store.com'),
(2, 'FashionWorld', 'fashion@world.com'),
(3, 'BookNest', 'info@booknest.com'),
(4, 'HomeComfort', 'support@homecomfort.com'),
(5, 'SportyGoods', 'info@sportygoods.com');

-- Insert into Customers
INSERT INTO Customers (CustomerID, Name, Email, Phone, AddressID)
VALUES
(1, 'John Doe', 'john.doe@example.com', '1234567890', 1),
(2, 'Jane Smith', 'jane.smith@example.com', '0987654321', 2),
(3, 'Robert Brown', 'robert.brown@example.com', '1122334455', 3),
(4, 'Emily Davis', 'emily.davis@example.com', '2233445566', 4),
(5, 'Michael Scott', 'michael.scott@example.com', '3344556677', 5),
(6, 'Sarah Johnson', 'sarah.johnson@example.com', '4455667788', 6),
(7, 'David Wilson', 'david.wilson@example.com', '5566778899', 7),
(8, 'Chris Evans', 'chris.evans@example.com', '6677889900', 8),
(9, 'Natalie Reed', 'natalie.reed@example.com', '7788990011', 9),
(10, 'Paul Walker', 'paul.walker@example.com', '8899001122', 10);

-- Insert into Addresses
INSERT INTO Addresses (AddressID, CustomerID, AddressLine1, City, State, Zip, Country)
VALUES
(1, 1, '123 Main St', 'New York', 'NY', '10001', 'USA'),
(2, 2, '456 Elm St', 'Los Angeles', 'CA', '90001', 'USA'),
(3, 3, '789 Pine St', 'Chicago', 'IL', '60601', 'USA'),
(4, 4, '101 Maple St', 'Houston', 'TX', '77001', 'USA'),
(5, 5, '202 Oak St', 'Philadelphia', 'PA', '19101', 'USA'),
(6, 6, '303 Cedar St', 'Phoenix', 'AZ', '85001', 'USA'),
(7, 7, '404 Birch St', 'San Antonio', 'TX', '78201', 'USA'),
(8, 8, '505 Walnut St', 'San Diego', 'CA', '92101', 'USA'),
(9, 9, '606 Poplar St', 'Dallas', 'TX', '75201', 'USA'),
(10, 10, '707 Aspen St', 'San Jose', 'CA', '95101', 'USA');

-- Insert into Products
INSERT INTO Products (ProductID, Name, Description, Price, SellerID, CategoryID)
VALUES
(1, 'Smartphone', 'Latest smartphone', 699.99, 1, 1),
(2, 'Laptop', 'High-performance laptop', 1299.99, 1, 1),
(3, 'T-Shirt', 'Comfortable cotton t-shirt', 19.99, 2, 2),
(4, 'Jeans', 'Stylish blue jeans', 39.99, 2, 2),
(5, 'Fiction Book', 'Best-selling novel', 14.99, 3, 3),
(6, 'Non-Fiction Book', 'Informative non-fiction book', 24.99, 3, 3),
(7, 'Vacuum Cleaner', 'Powerful vacuum cleaner', 199.99, 4, 4),
(8, 'Microwave Oven', 'High-efficiency microwave', 149.99, 4, 4),
(9, 'Basketball', 'Professional-grade basketball', 29.99, 5, 5),
(10, 'Tennis Racket', 'Lightweight tennis racket', 89.99, 5, 5),
(11, 'Smartwatch', 'Fitness tracking smartwatch', 199.99, 1, 1),
(12, 'Headphones', 'Noise-cancelling headphones', 149.99, 1, 1),
(13, 'Sneakers', 'Comfortable running sneakers', 59.99, 2, 2),
(14, 'Blender', 'Multi-speed blender', 89.99, 4, 4),
(15, 'Yoga Mat', 'Non-slip yoga mat', 29.99, 5, 5),
(16, 'Gaming Console', 'Latest generation gaming console', 499.99, 1, 1),
(17, 'Monitor', '4K resolution monitor', 299.99, 1, 1),
(18, 'Shirt', 'Formal dress shirt', 34.99, 2, 2),
(19, 'Air Fryer', 'Healthy cooking air fryer', 129.99, 4, 4),
(20, 'Tablet', '10-inch display tablet', 349.99, 1, 1);

-- Insert into Orders
INSERT INTO Orders (OrderID, OrderNumber, OrderDate, CustomerID)
VALUES
(1, 'ORD123', '2024-10-01', 1),
(2, 'ORD124', '2024-10-02', 2),
(3, 'ORD125', '2024-10-03', 3),
(4, 'ORD126', '2024-10-03', 3),
(5, 'ORD127', '2024-10-04', 4),
(6, 'ORD128', '2024-10-05', 5),
(7, 'ORD129', '2024-10-06', 6),
(8, 'ORD130', '2024-10-07', 7),
(9, 'ORD131', '2024-10-08', 8),
(10, 'ORD132', '2024-10-09', 9),
(11, 'ORD133', '2024-10-10', 10),
(12, 'ORD134', '2024-10-11', 1),
(13, 'ORD135', '2024-10-12', 2),
(14, 'ORD136', '2024-10-13', 3),
(15, 'ORD137', '2024-10-14', 4),
(16, 'ORD138', '2024-10-15', 5),
(17, 'ORD139', '2024-10-16', 6),
(18, 'ORD140', '2024-10-17', 7),
(19, 'ORD141', '2024-10-18', 8),
(20, 'ORD142', '2024-10-19', 9);

-- Insert into OrderItems
INSERT INTO OrderItems (OrderItemID, OrderID, ProductID, Quantity)
VALUES
(1, 1, 1, 2),
(2, 1, 2, 1),
(3, 2, 3, 3),
(4, 3, 5, 1),
(5, 3, 6, 2),
(6, 4, 9, 1),
(7, 4, 10, 2),
(8, 5, 7, 1),
(9, 5, 8, 2),
(10, 6, 4, 2),
(11, 6, 3, 1),
(12, 7, 12, 1),
(13, 7, 13, 2),
(14, 8, 17, 1),
(15, 9, 16, 2),
(16, 10, 1, 1),
(17, 11, 19, 1),
(18, 12, 2, 1),
(19, 13, 5, 1),
(20, 14, 6, 1);

-- Insert into Payments
INSERT INTO Payments (PaymentID, PaymentMethod, Amount, PaymentDate, OrderID)
VALUES
(1, 'Credit Card', 1699.97, '2024-10-01', 1),
(2, 'PayPal', 59.97, '2024-10-02', 2),
(3, 'Credit Card', 39.98, '2024-10-03', 3),
(4, 'Credit Card', 119.97, '2024-10-03', 4),
(5, 'PayPal', 299.98, '2024-10-04', 5),
(6, 'Credit Card', 119.97, '2024-10-05', 6),
(7, 'Credit Card', 239.98, '2024-10-06', 7),
(8, 'PayPal', 299.99, '2024-10-07', 8),
(9, 'Credit Card', 499.99, '2024-10-08', 9),
(10, 'PayPal', 129.99, '2024-10-09', 10),
(11, 'Credit Card', 349.99, '2024-10-10', 11),
(12, 'Credit Card', 699.99, '2024-10-11', 12),
(13, 'PayPal', 29.99, '2024-10-12', 13),
(14, 'Credit Card', 14.99, '2024-10-13', 14),
(15, 'Credit Card', 24.99, '2024-10-14', 15),
(16, 'PayPal', 199.99, '2024-10-15', 16),
(17, 'Credit Card', 299.99, '2024-10-16', 17),
(18, 'Credit Card', 399.99, '2024-10-17', 18),
(19, 'Credit Card', 349.99, '2024-10-18', 19),
(20, 'PayPal', 599.99, '2024-10-19', 20);

-- Insert into Reviews
INSERT INTO Reviews (ReviewID, ProductID, CustomerID, Rating, ReviewText)
VALUES
(1, 1, 1, 5, 'Excellent phone!'),
(2, 2, 2, 4, 'Great laptop for the price.'),
(3, 3, 3, 5, 'Love this t-shirt!'),
(4, 4, 4, 3, 'Good jeans, but could be better.'),
(5, 5, 5, 5, 'Amazing book!'),
(6, 6, 6, 4, 'Very informative.'),
(7, 7, 7, 5, 'Best vacuum cleaner I ever bought!'),
(8, 8, 8, 4, 'Solid microwave oven.'),
(9, 9, 9, 5, 'Great basketball!'),
(10, 10, 10, 4, 'Good for beginner tennis players.');

SELECT * FROM [Sellers]
SELECT * FROM [Customers]
SELECT * FROM [Categories]
SELECT * FROM [Orders]
SELECT * FROM [Addresses]
SELECT * FROM [Products]
SELECT * FROM [ShoppingCart]
SELECT * FROM [OrderItems]
SELECT * FROM [CartItems]
SELECT * FROM [Payments]
SELECT * FROM [Reviews]
SELECT * FROM [Inventory]
