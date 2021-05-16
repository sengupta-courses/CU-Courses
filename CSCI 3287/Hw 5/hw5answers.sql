/*Homework 5*/
/*Pourna Sengupta*/

USE HW_5_DW;

/*1. Show a list of Customer Name, Gender, Sales Person Name and Sales Person's City
 for all products sold on September 2015, whose Sales Price is more than 20 and Quantity 
 sold is more than 8.*/
 SELECT c.CustomerName, c.Gender, s.SalesPersonName, s.City AS SalesPersonCity
 FROM Dim_Customer c, Dim_SalesPerson s, Dim_Date d, Fact_ProductSales f
 WHERE c.CustomerID = f.CustomerID
 AND s.SalesPersonID = f.SalesPersonID
 AND d.DateKey = f.SalesDateKey
 AND d.MONTHNAME = 'September'
 AND d.YEAR = '2015'
 AND f.SalesPrice > 20 
 AND f.Quantity > 8; 
 /*
'Linda Ronstadt','F','Tom Petty','Boulder'
'Elon Musk','M','Jacob Leis','Lafayette'
*/


/*2. Show a list of Store Name, Store's City and Product Name for all products sold on 
March 2017, whose Product Cost is less than 50 and store located in 'Boulder'.*/
SELECT st.StoreName, st.City AS StoreCity, p.ProductName
FROM Dim_Store st, Dim_Product p, Dim_Date d, Fact_ProductSales f
WHERE st.StoreID = f.StoreID
AND p.ProductKey = f.ProductID
AND d.DateKey = f.SalesDateKey
AND d.MONTHNAME = 'March'
AND d.YEAR = '2017'
AND f.ProductCost < 50 
AND st.City = 'Boulder'; 
/*
'ValueMart Boulder','Boulder','Wheat Flour 1kg'
'ValueMart Boulder','Boulder','Jasmine Rice 5kg'
'ValueMart Boulder','Boulder','SunFlower Oil 1 ltr'
*/



/*3. Show a list of Top 2 Sales Person by their Total Revenue for 2017, 
i.e. Top 2 sales person with HIGHEST Total Revenue.*/
SELECT top.SalesPersonName, SUM(top.TotalRevenue) AS TopSalesRevenue 
FROM 
	(SELECT sp.SalesPersonName, f.ProductID, ((SUM(f.Quantity)) * f.SalesPrice) AS TotalRevenue
    FROM Fact_ProductSales f, Dim_SalesPerson sp, Dim_Date d
    WHERE f.SalesPersonID = sp.SalesPersonID
    AND d.DateKey = f.SalesDateKey 
    AND YEAR = '2017'
    
    GROUP BY f.SalesPersonID, sp.SalesPersonName, f.ProductID, f.Quantity, f.SalesPrice) top
GROUP BY top.SalesPersonName 
ORDER BY TopSalesRevenue Desc
LIMIT 2;
/*
'Julian Brand','2588.00'
'Jasmin Farah','1158.00'
*/



/*4. Display a Customer Name and Total Revenue who has LOWEST Total Revenue in 2017.*/
SELECT c.CustomerName, SUM(f.SalesPrice * f.Quantity) AS TotalRevenue 
FROM Fact_ProductSales f
JOIN Dim_Customer c ON (f.CustomerID = c.CustomerID)
JOIN Dim_Date d ON (f.SalesDateKey = d.DateKey)
WHERE (d.Year = '2017')
GROUP BY c.CustomerName
ORDER BY SUM(f.SalesPrice * f.Quantity) ASC
LIMIT 1;
/*
'Melinda Gates' , '437.50'
*/


/*5. Show a list of Store Name (in alphabetical order) and their 'Total Sales Price' for 
the year between 2010 and 2017.*/
SELECT s.StoreName, SUM(f.SalesPrice) As TotalSalesPrice
FROM Fact_ProductSales f
JOIN Dim_Store s ON (f.StoreID = s.StoreID)
JOIN Dim_Date d ON (f.SalesDateKey = d.DateKey)
WHERE(d.Year = '2017') 
	OR (d.Year = '2016') 
	OR (d.Year = '2015')
	OR (d.Year = '2014') 
	OR (d.Year = '2013')
	OR (d.Year = '2012') 
	OR (d.Year = '2011') 
	OR (d.Year = '2010')  
GROUP BY s.StoreName
ORDER BY s.StoreName ASC;
/*
'ValueMart Berthoud','1554.00'
'ValueMart Boulder','7961.00'
'ValueMart Lyons','1759.50'
*/


/*6. Display a list of Store Name, Product Name and their Total Profits from product name 
like 'Jasmine Rice' for 2010.*/
SELECT s.StoreName, p.ProductName, SUM((f.SalesPrice * f.Quantity) - (f.ProductCost * f.Quantity)) AS TotalProfit
FROM Fact_ProductSales f
JOIN Dim_Store s ON (f.StoreID = s.StoreID)
JOIN Dim_Product p ON (f.ProductID = p.ProductKey)
JOIN Dim_Date d ON (f.SalesDateKey = d.DateKey)
WHERE p.ProductName LIKE 'Jasmine Rice%' AND d.Year = '2010'
GROUP BY s.StoreName,p.ProductName;
/*
'ValueMart Boulder','Jasmine Rice 5kg','50.00'
'ValueMart Lyons','Jasmine Rice 5kg','19.00'
'ValueMart Berthoud','Jasmine Rice 5kg','18.00'
*/



/*7. Display Total Revenue from 'ValueMart Boulder' Store for each Quarter during 2016, 
sort your result by Quarter in chronological order.*/
SELECT SUM(f.SalesPrice * f.Quantity)
FROM Fact_ProductSales f
JOIN Dim_Store s ON (f.StoreID = s.StoreID)
JOIN Dim_Date d ON (f.SalesDateKey = d.DateKey)
WHERE s.StoreName = 'ValueMart Boulder' AND (d.Year = '2016') 
GROUP BY d.QUARTER 
ORDER BY  d.QUARTER ASC;
/*
'1622.50'
'1144.50'
'2259.50'
'1492.50'
*/

/*8. Display Customer Name and Total Sales Price for all items purchased by customers 
Melinda Gates and Harrison Ford.*/
SELECT c.CustomerName, SUM(f.SalesPrice) AS TotalSalesPrice
FROM Fact_ProductSales f
JOIN Dim_Customer c ON (f.CustomerID = c.CustomerID)
WHERE (c.CustomerName = 'Melinda Gates') OR (c.CustomerName = 'Harrison Ford')
GROUP BY c.CustomerName;
/*
'Harrison Ford','2234.00'
'Melinda Gates','1717.00'
*/


/*9. Display Store Name, Sales Price and Quantity for all items sold in March 12th 2017.*/
SELECT s.StoreName, f.SalesPrice, f.Quantity
FROM Fact_ProductSales f
JOIN Dim_Store s ON (f.StoreID = s.StoreID)
JOIN Dim_Date d ON (f.SalesDateKey = d.DateKey)
WHERE Date = '2017-03-12';
/*
'ValueMart Boulder','6.50','8'
'ValueMart Boulder','24.00','3'
'ValueMart Boulder','43.50','9'
*/

/*10. Display Sales Person Name and Total Revenue for the best performing Sales Person, 
i.e., the Sales Person with the HIGHEST Total Revenue.*/
SELECT s.SalesPersonName, SUM(f.SalesPrice * f.Quantity) AS TotalRevenue
FROM Fact_ProductSales f 
JOIN Dim_SalesPerson s ON (f.SalesPersonID = s.SalesPersonID)
GROUP BY s.SalesPersonName
ORDER BY SUM(f.SalesPrice * f.Quantity) DESC
LIMIT 1;
/*
'Julian Brand' , '21164.50'
*/

/*11. Display the Top 3 Product Name by their HIGHEST Total Profit.*/
SELECT p.ProductName
FROM Fact_ProductSales f
JOIN Dim_Product p ON (f.ProductID = p.ProductKey)
GROUP BY p.ProductName
ORDER BY SUM((f.SalesPrice * f.Quantity)-(f.ProductCost * f.Quantity)) DESC
LIMIT 3;
/*
'SunFlower Oil 1 ltr'
'Jasmine Rice 5kg'
'Tide Laundry Detergent 1kg case'
*/

/*12. Display Year, MonthName and Total Revenue for the 1st 3 months 
(i.e. January, February and March) of 2017.*/
SELECT d.Year, d.MONTHNAME, SUM(f.SalesPrice * f.Quantity) AS TotalRevenue
FROM Fact_ProductSales f
JOIN Dim_Date d ON (f.SalesDateKey = d.DateKey)
WHERE d.Year = '2017' AND d.Quarter = 1
GROUP BY d.MONTHNAME;
/*
'2017','January','1417.50'
'2017','February','1595.50'
'2017','March','1954.00'
*/

/*13. Display Product Name, average product cost and average sales price for the products 
sold in 2017. Show averages rounded to 2 decimal places.*/
SELECT p.ProductName, ROUND(AVG(f.ProductCost),2) AS AverageProductCost, ROUND(AVG(f.SalesPrice),2) AS AverageSalesPrice
FROM Fact_ProductSales f 
JOIN Dim_Product p ON (f.ProductID = p.ProductKey)
JOIN Dim_Date d ON (f.SalesDateKey = d.DateKey)
WHERE (d.Year = '2017')
GROUP BY p.ProductName;
/*
'Wheat Flour 1kg','5.50','6.50'
'Jasmine Rice 5kg','22.50','24.00'
'SunFlower Oil 1 ltr','42.00','43.50'
'Dawn Dish Soap, case','18.00','20.00'
'Tide Laundry Detergent 1kg case','135.00','139.00'
*/

/*14. Display Customer Name, average sales price and average quantity for all items purchased 
by customer Melinda Gates. Show averages rounded to 2 decimal places.*/
SELECT c.CustomerName, ROUND(AVG(f.SalesPrice),2) AS AverageSalesPrice, ROUND(AVG(Quantity),2) As AverageQuantity
FROM Fact_ProductSales f 
JOIN Dim_Customer d ON (f.CustomerID = c.CustomerID)
WHERE (c.CustomerName = 'Melinda Gates');
/*
'Melinda Gates' , '26.02', '4.98'
*/

/*15. Display Store Name, Maximum sales price and Minimum sales price for store located in 
'Boulder' city. Show MIN / MAX rounded to 2 decimal places.*/
SELECT s.StoreName, MAX(f.SalesPrice), MIN(f.SalesPrice)
FROM Fact_ProductSales f
JOIN Dim_Store s ON (f.StoreID = s.StoreID)
WHERE s.City = 'Boulder'
GROUP BY s.StoreName;
/*
'ValueMart Boulder' , '139.00' , '6.50'
*/


