create DATABASE shoppingproduct;

use shoppingproduct;

CREATE TABLE manufacturer(
	manufactureId INT NOT NULL PRIMARY KEY AUTO_INCREMENT,
	manufacturer_name CHAR(25),
    support_phonenumber int
);

INSERT INTO manufacturer
	(manufactureId, manufacturer_name, support_phonenumber) VALUES
		(5001, 'Alliance', '1234567890'),
		(5002, 'Assured', '97982324393'),
        (5003, 'Action ', '235154534345'),
        (5004, 'Abridge ', '51343413145'),
        (5005, 'Facility Co', '15343144135'),
        (5006, 'Man-units', '5665335425'),
        (5007, 'Manufacturing Nation', '3452345436'),
        (5008, 'BaseManufacturing Company', '32466234346'),
        (5009, 'otal Manufacturing Co.', '63326432'),
        (5010, 'Manufacturing Oriented', '3144363'),
        (5011, 'Agile ', '15313543'),
        (5012, 'Transformative', '34615427'),
        (5013, 'CanMan ', '135451445'),
        (5014, 'Tradufacturing', '154514165758'),
        (5015, 'Manestic ', '87324872439'),
        (5016, 'Conficio ', '97982324393'),
        (5017, 'Engage ', '89724680237'),
        (5018, 'Fabrico ', '0924374034');


CREATE TABLE product_type(
	product_typeId INT NOT NULL PRIMARY KEY AUTO_INCREMENT,
	product_type_Name CHAR(25)
);

INSERT INTO product_type
    (product_typeId, product_type_Name) VALUES
		(771, 'Footwear'),
		(772, 'Food'),
        (773, 'Jewellery'),
        (774, 'Fashion'),
        (775, 'KITCHEN'),
        (776, 'SPORTS'),
        (777, 'COMPUTER'),
        (778, 'BOOK'),
        (779, 'BEAUTY');

CREATE TABLE products(
	productId INT NOT NULL PRIMARY KEY AUTO_INCREMENT,
	product_name CHAR(25),
    product_price int,
    product_typeId int,
    manufactureId int,
    FOREIGN KEY (product_typeId) REFERENCES product_type(product_typeId),
    FOREIGN KEY (manufactureId) REFERENCES manufacturer(manufactureId)
);

INSERT INTO products
	(productId, product_name, product_price,product_typeId,manufactureId) VALUES
		(101, 'Tshirt', 400, 774, 5003),
		(102, 'Bottle', 100, 775, 5005),
		(103, 'Stove', 1000, 775, 5001),
		(104, 'Jeans', 900, 774, 5003),
		(105, 'Rich Dad', 350, 778, 5009),
		(106, 'Vico Termeric', 130, 779, 5013),
		(107, 'xiomi', 20000, 777, 5002),
		(108, 'Mouse', 943, 777, 5008),
		(109, 'Dongle', 378, 777, 5009),
		(110, 'HDMI Cable', 200, 777, 5005),
		(111, 'Bulb', 60, 775, 5003),
		(112, 'Pasta', 200, 775, 5004),
		(113, 'Hair dryer', 600, 775, 5006),
		(114, 'Agnipath', 400, 779, 5001),
		(115, 'CD DVD', 100, 777, 5010),
		(116, 'Makeup Kit', 2000, 779, 5006),
		(117, 'Web Cam', 920, 777, 5002),
		(118, 'Led Strip', 200, 777, 5008),
		(119, 'trowsers', 899, 774, 5009),
		(120, 'Plazzo', 988, 774, 5010),
		(121, 'Kurti', 2333, 774, 5004);



CREATE TABLE reviews(
	productId INT,
	review_title CHAR(100),
    review_rating int,
    reviewedBy char(25),
    reviewed_date DATE
);

INSERT INTO reviews
	(productId, review_title, review_rating,reviewedBy,reviewed_date) VALUES
		(101, 'Perfect Fit and colours', 5, 'Rajesh Mishra', '20-02-16'),
		(101, 'Bad in comfort sometimes ethcy', 2, 'Milind Sood', '21-02-26'),
		(101, 'cotton is supper soft', 4, 'Kumar Rao', '21-03-26'),
		(102, 'air tight caps', 5, 'Devendra kopa', '20-04-20'),
		(103, 'burners all well placed', 4, 'Miya roza', '21-03-30'),
		(103, 'glass tops looks dope', 3, 'Sanjeevani Rao', '21-04-01'),
		(103, 'No lighter required', 5, 'Ashish agarwaal', '21-05-12'),
		(104, 'Super comfotable and skinny', 5, 'Milap kesari', '21-02-12'),
		(104, 'Got rugged jeans', 2, 'kasthi Dhiman', '21-08-26'),
		(104, 'COlour got wiped out', 3, 'Aniket Verma', '21-07-30'),
		(105, 'Must read book', 5, 'Vidhi shah', '21-12-21'),
		(105, 'eye opener for me', 4, 'Arnav Gupta', '21-05-21'),
		(105, 'Pages are of best quality', 3, 'shashank udupa', '21-03-13'),
		(107, 'best phone ever had', 5, 'Himanshu Verma', '21-06-26'),
		(107, 'Phone heating issue', 2, 'Ashutosh singh', '10-05-13');

CREATE TABLE specifications(
	productId INT NOT NULL PRIMARY KEY AUTO_INCREMENT,
	brand CHAR(25),
    model_no int
);

INSERT INTO specifications
	(productId, brand, model_no) VALUES
		(101, 'Fashadil', 901),
		(102, 'Cookie', 902),
		(103, 'Blaze', 903),
		(104, 'smashing', 904),
		(105, 'Panda', 905),
		(106, 'Venust', 906),
		(107, 'Hitch', 907),
		(108, 'Fashlux', 908),
		(109, 'Opulence', 909),
		(110, 'Notch', 910),
		(111, 'Fashdeck', 911),
		(112, 'Bling', 912),
		(113, 'Link', 913),
		(114, 'fiberezz', 914);

Q1.
Show all products having type of fashion and whose price is below 1000 INR

SELECT p.*
from products p, product_type t
where
	p.product_typeId=t.product_typeId AND
	p.product_price<1000 AND
	t.product_type_Name="Fashion";

+-----------+--------------+---------------+----------------+---------------+
| productId | product_name | product_price | product_typeId | manufactureId |
+-----------+--------------+---------------+----------------+---------------+
|       101 | Tshirt       |           400 |            774 |          5003 |
|       104 | Jeans        |           900 |            774 |          5003 |
|       119 | trowsers     |           899 |            774 |          5009 |
|       120 | Plazzo       |           988 |            774 |          5010 |
+-----------+--------------+---------------+----------------+---------------+
4 rows in set (0.001 sec)

Q2. show product name, manufacturer name and support phone numbers whose
	product review rating is less than 4

SELECT p.product_name,r.review_rating ,m.manufacturer_name, m.support_phonenumber
from products p, reviews r, manufacturer m
where
	p.productId = r.productId AND
	p.manufactureId = m.manufactureId AND
	r.review_rating < 4;

+--------------+---------------+------------------------+---------------------+
| product_name | review_rating | manufacturer_name      | support_phonenumber |
+--------------+---------------+------------------------+---------------------+
| Tshirt       |             2 | Action                 |          2147483647 |
| Stove        |             3 | Alliance               |          1234567890 |
| Jeans        |             2 | Action                 |          2147483647 |
| Jeans        |             3 | Action                 |          2147483647 |
| Rich Dad     |             3 | otal Manufacturing Co. |            63326432 |
| xiomi        |             2 | Assured                |          2147483647 |
+--------------+---------------+------------------------+---------------------+
6 rows in set (0.001 sec)

Q3.
Search product whose brand name starts with 'F'

SELECT DISTINCT p.productId, p.product_name, s.brand, s.model_no
from products p, specifications s
where
	p.productId = s.productId AND
	s.brand LIKE 'F%';

+-----------+--------------+----------+----------+
| productId | product_name | brand    | model_no |
+-----------+--------------+----------+----------+
|       101 | Tshirt       | Fashadil |      901 |
|       108 | Mouse        | Fashlux  |      908 |
|       111 | Bulb         | Fashdeck |      911 |
|       114 | Agnipath     | fiberezz |      914 |
+-----------+--------------+----------+----------+
4 rows in set (0.001 sec)


Q5.
Write a query to get Product list (id, name, unit price) of above average price.

SELECT product_name, product_price
FROM products
WHERE product_price > (SELECT avg(product_price) FROM Products)
ORDER BY product_price;

+---------------+---------------+
| product_name  | product_price |
+---------------+---------------+
| Bulb          |            60 |
| Bottle        |           100 |
| CD DVD        |           100 |
| Vico Termeric |           130 |
| Led Strip     |           200 |
| HDMI Cable    |           200 |
| Pasta         |           200 |
| Rich Dad      |           350 |
| Dongle        |           378 |
| Agnipath      |           400 |
| Tshirt        |           400 |
| Hair dryer    |           600 |
| trowsers      |           899 |
| Jeans         |           900 |
| Web Cam       |           920 |
| Mouse         |           943 |
| Plazzo        |           988 |
| Stove         |          1000 |
+---------------+---------------+
18 rows in set (0.001 sec)