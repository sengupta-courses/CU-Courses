/*Homework 4*/ 
/*Pourna Sengupta*/
USE HW_4_SQL;
/*1. Show a list of the Company Name and Country for all Suppliers located in Japan or Germany.*/
SELECT CompanyName, Country 
FROM hwSuppliers
WHERE Country IN ('Japan', 'Germany'); 

/*2. Show a list of Products' Product Name, Quantity per Unit 
and Unit Price for products with a Unit Price less than $7 but more than $ 4.*/
SELECT ProductName, QuantityPerUnit, UnitPrice
FROM hwProducts
WHERE UnitPrice BETWEEN 4 AND 7; 

/*3. Show a list of Customers' Company Name, Contact Title and City whose Country is USA and City 
is Portland OR Country is Canada and City is Vancouver.*/
SELECT CompanyName, ContactTitle, City
FROM hwCustomers
WHERE Country = 'USA' AND City = 'Portland' OR Country = 'Canada' AND City = 'Vancouver'; 

/*4. Show a list the Contact Name and Contact Title for all Suppliers with a SupplierID from 
5 to 8 (inclusive) and sort in descending order by ContactName.*/
SELECT ContactName, ContactTitle
FROM hwSuppliers 
WHERE SupplierID BETWEEN 5 AND 8
ORDER BY ContactName DESC; 


/*5. Show a product name and unit price of the least expensive Products (i.e. lowest unit price)? 
You MUST use a Sub Query.*/
SELECT ProductName, UnitPrice
FROM hwProducts 
WHERE UnitPrice = 
	(SELECT MIN(UnitPrice) FROM hwproducts); 


/*6. Show a list of Ship Country and their Order Counts that is shipped outside the USA between 
May 4th and 5th 2015.*/
SELECT ShipCountry, COUNT(OrderID) AS Orders
FROM hwOrders 
WHERE ShippedDate BETWEEN '2015-05-04' AND '2015-05-05'
AND ShipCountry != 'USA' 
GROUP BY ShipCountry;


/*7. Show a list of all employees with their first name, last name and hiredate (formated to mm/dd/yyyy) 
who are NOT living in the USA and have been employed for at least 5 years.*/
SELECT FirstName, LastName, HireDate
FROM hwEmployees 
WHERE Country != 'USA' 
AND (YEAR(CURRENT_TIMESTAMP()) - YEAR(HireDate)) > 5; 


/*8. Show a list of Product Name and their 'Inventory Value' (Inventory Value = units in stock multiplied 
by their unit price) for products whose 'Inventory Value' is over 3000 but less than 4000.*/
SELECT ProductName, UnitsInStock * UnitPrice AS InventoryValue
FROM hwProducts 
WHERE (UnitsInStock * UnitPrice) BETWEEN 3000 AND 4000; 


/*9. Show a list of Products' product Name, Unit in Stock and ReorderLevel level whose Product Name starts with 
'S' that are currently in stock (i.e. at least one Unit in Stock) and inventory level is at or below the reorder level.*/
SELECT ProductName, UnitsInStock, ReorderLevel
FROM hwProducts 
WHERE (ProductName LIKE 'S%'
AND UnitsInStock BETWEEN 1 AND ReorderLevel); 

/*10. Show a Product Name, Unit Price for all products, whose Quantity Per Unit
has/measure in 'box' that have been discontinued (i.e. discontinued = 1).*/
SELECT ProductName, UnitPrice 
FROM hwProducts
WHERE (LOCATE('box', QuantityPerUnit) AND Discontinued = 1); 


/*11. Show a list of Product Name and their TOTAL inventory value (inventory value = UnitsInStock * UnitPrice) 
for Supplier's Country from Japan.*/
SELECT ProductName, UnitsInStock * UnitPrice AS InventoryValue 
FROM hwProducts 
INNER JOIN hwSuppliers ON hwProducts.SupplierID = hwSuppliers.SupplierID
WHERE hwSuppliers.Country = 'Japan'; 


/*12. Show a list country and their customer's count that is greater than 8.*/
SELECT Country, COUNT(CustomerID) AS Customers
FROM hwCustomers 
GROUP BY Country
HAVING COUNT(CustomerID) > 8; 


/*13. Show a list of Orders' Ship Country, Ship City and their Order count for Ship Country 'Austria' and 'Argentina'.*/
SELECT ShipCountry, ShipCity, COUNT(OrderID) AS OrderCount
FROM hwOrders
WHERE ShipCountry IN ('Austria', 'Argentina')
GROUP BY OrderID;



/*14. Show a list of Supplier's Company Name and Product's Product Name for supplier's country from Spain.*/
SELECT CompanyName, hwProducts.ProductName
FROM hwSuppliers 
INNER JOIN hwProducts ON hwSuppliers.SupplierID = hwProducts.SupplierID
WHERE Country = 'Spain'; 


/*15. What is the 'Average Unit Price' (rounded to two decimal places) of all the products whose ProductName ends with 'T'?*/
SELECT ROUND(AVG(UnitPrice), 2) AS AvgUnitPrice
FROM hwProducts 
WHERE ProductName LIKE '%T'; 


/*16. Show a list of employee's full name, title and their Order count for employees who has more than 120 orders.*/
SELECT CONCAT(hwEmployees.FirstName,' ',hwEmployees.LastName) AS Employee, hwEmployees.Title, COUNT(hwOrders.OrderID) AS OrderCount 
FROM hwEmployees, hwOrders
WHERE hwEmployees.EmployeeID = hwOrders.EmployeeID
GROUP BY hwEmployees.EmployeeID
HAVING COUNT(hwOrders.OrderID) > 120; 


/*17. Show a list customer's company Name and their country who has NO Orders on file (i.e. NULL Orders).*/
SELECT CompanyName, Country
FROM hwCustomers
WHERE CustomerID NOT IN (SELECT CustomerID FROM hwOrders);  


/*18. Show a list of Category Name and Product Name for all products that are currently out of stock (i.e. UnitsInStock = 0).*/
SELECT hwCategories.CategoryName, hwProducts.ProductName
FROM hwCategories, hwProducts 
WHERE hwCategories.CategoryID = hwProducts.CategoryID
AND hwProducts.UnitsInStock = 0; 


/*19. Show a list of products' Product Name and Quantity Per Unit, which are measured as 'pkg' or 'pkgs' or 
'jars' for a supplier’s country from Japan.*/
SELECT ProductName, QuantityPerUnit
FROM hwProducts
LEFT JOIN hwSuppliers ON hwSuppliers.SupplierID = hwProducts.SupplierID
WHERE (LOCATE('pkg', hwProducts.QuantityPerUnit) OR LOCATE('pkgs', hwProducts.QuantityPerUnit) OR LOCATE('jars', hwProducts.QuantityPerUnit)) 
AND hwSuppliers.Country = 'Japan'; 

/*20. Show a list of customer's company name, their Order’s ship name and total value of all their orders 
(rounded to 2 decimal places) for customer's from Mexico. (value of order = (UnitPrice multiplied by Quantity) less discount).*/
SELECT hwCustomers.CompanyName, hwOrders.ShipName AS ShipName, 
	ROUND((hwOrderDetails.UnitPrice * hwOrderDetails.Quantity),2) AS OrderValue
FROM hwCustomers, hwOrders, hwOrderDetails 
WHERE hwCustomers.CustomerID = hwOrders.CustomerID 
AND hwOrders.OrderID = hwOrderDetails.OrderID 
AND hwCustomers.Country IN ('Mexico'); 

/*21. Show a list of products' Product Name and suppliers' Region whose product name starts with 'L' and Region is NOT blank/empty.*/
SELECT hwProducts.ProductName, hwSuppliers.Region 
FROM hwProducts
INNER JOIN hwSuppliers ON hwSuppliers.SupplierID = hwProducts.SupplierID
WHERE hwSuppliers.Region IS NOT NULL AND hwProducts.ProductName LIKE 'L%'; 

/*22. Show a list of Order's Ship Country, Ship Name and Order Date (formatted as MonthName and Year, e.g. March 2015) 
for all Orders from 'Versailles' Ship City whose Customer's record doesn't exists in Customer table.*/
SELECT ShipCountry, ShipName, CONCAT(MONTHNAME(OrderDate), ' ', YEAR(OrderDate)) AS OrderDate 
FROM hwOrders, hwCustomers
WHERE ShipCity = 'Versailles'
AND hwOrders.CustomerID != hwCustomers.CustomerID; 


/*23. Show a list of products' Product Name and Units In Stock whose Product Name starts with 'F' and Rank them 
based on UnitsInStock from highest to lowest (i.e. highest UnitsInStock rank = 1, and so on). Display rank number as well.*/
SELECT ProductName, UnitsInStock, RANK() OVER (ORDER BY UnitsInStock DESC) AS Ranking
FROM hwProducts 
WHERE ProductName LIKE 'F%'; 


/*24. Show a list of products' Product Name and Unit Price for ProductID from 1 to 5 (inclusive)
and Rank them based on UnitPrice from lowest to highest. Display rank number as well.*/
SELECT ProductName, UnitPrice, RANK() OVER (ORDER BY UnitPrice ASC) AS Ranking 
FROM hwProducts 
WHERE ProductID BETWEEN 1 and 5; 



/*25. Show a list of employees' first name, last name, country and date of birth (formatted to mm/dd/yyyy) who were born after 1984 
and Rank them by date of birth (oldest employee rank 1st, and so on) for EACH country, i.e. Rank number should reset/restart for EACH country.*/
SELECT FirstName, LastHName, Country, CONVERT(datetime, Birthdate, 101) AS DOB 
FROM hwEmployees
WHERE DOB > '1/1/1984'; 






