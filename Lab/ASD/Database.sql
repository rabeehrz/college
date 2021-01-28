CREATE DATABASE asd;

USE asd;
--------------------------------

CREATE TABLE `EMPLOYEE` (
	`EMPNO` INT(4),
	`ENAME` VARCHAR(2),
	`DESIGNATION` VARCHAR(2),
	`SALARY` INT(8)
);

ALTER TABLE EMPLOYEE ADD QUALIFICATION VARCHAR(2);

ALTER TABLE EMPLOYEE
MODIFY COLUMN EMPNO INT(6);

RENAME TABLE EMPLOYEE TO EMP_NEW;

ALTER TABLE EMP_NEW
DROP COLUMN QUALIFICATION;

TRUNCATE TABLE EMP_NEW;

DROP TABLE EMP_NEW;

--------------------------------
CREATE TABLE `employee` (
	`EmpID` INT NOT NULL AUTO_INCREMENT,
	`Emp_no` INT,
	`Ename` VARCHAR(255),
	`Designation` VARCHAR(255),
	`Salary` INT,
	`DeptId` INT,
	PRIMARY KEY (`EmpID`)
);

INSERT INTO 
employee(Emp_no, Ename, Designation, Salary, DeptId)
VALUES 
(66928, 'BLAZE', 'MANAGER', 55000, 3001),
(67832, 'CLARE', 'MANAGER' ,51000, 1001),
(65646, 'JONAS', 'MANAGER', 59140, 2001),
(67858, 'SCARLET', 'ANALYST', 62000, 2001),
(69062, 'FRANK', 'ANALYST', 62000, 2001),
(63679, 'SANDRINE', 'CLERK', 18000, 2001),
(64989, 'ADELYN', 'SALESMAN', 34000, 3001),
(65271, 'WADE', 'SALESMAN', 27000, 3001),
(66564, 'MADDEN', 'SALESMAN', 27000, 3001),
(68454, 'TUCKER', 'SALESMAN', 32000, 3001),
(68736, 'ADNRES', 'CLERK', 24000, 2001),
(69000, 'JULIUS', 'CLERK', 21000, 3001),
(69324, 'MARKER', 'CLERK', 28000, 1001);

SELECT * FROM employee;

SELECT Emp_no, Ename, Designation FROM employee;

DELETE FROM employee WHERE Emp_no=68454;

INSERT INTO 
employee(Emp_no,Ename,Designation,DeptId) 
VALUES 
(67654,'RABEEH','ANALYST',2001);

SELECT * FROM employee WHERE Salary>25000 AND DeptId=2001;

UPDATE employee SET Salary=15000 WHERE Ename='RABEEH';

UPDATE employee SET Designation="ANALYST", Salary=62000 WHERE Ename="ADELYN";

SELECT Ename FROM employee WHERE Designation IN ("MANAGER", "ANALYST");

SELECT Ename FROM employee WHERE Salary>30000 AND Salary<60000;

UPDATE employee SET Salary=Salary*1.05 WHERE DeptId=2001;

SELECT * FROM employee WHERE salary<30000 OR DeptID=1001;

----------------------------------------------------------

CREATE TABLE `CAR` (
	`id` INT NOT NULL AUTO_INCREMENT,
	`name` VARCHAR(255),
	`company` VARCHAR(255),
	`country` VARCHAR(255),
	`approxprice` FLOAT,
	PRIMARY KEY (`id`)
);

INSERT INTO 
CAR(name, company, country, approxprice)
VALUES
('Beet', 'Chevrolet', 'USA', 4),
('Swift', 'Maruti', 'Japan', 6),
('Escort', 'Ford', 'USA', 4.2),
('Sunny', 'Nissan', 'Japan', 8),
('Beetle', 'Volkswagen', 'Germany', 21),
('Etios', 'Toyota', 'Japan', 7.2),
('Sail', 'Chevrolet', 'USA', 5),
('Aria', 'Tata', 'India', 7),
('Passat', 'Volkswagen', 'Germany', 25),
('SX4', 'Maruti', 'Japan', 6.7);

SELECT DISTINCT company FROM CAR;

SELECT DISTINCT company, country FROM CAR;

SELECT * FROM CAR WHERE approxprice BETWEEN 4 AND 7;

SELECT name, company FROM CAR WHERE country='India' AND approxprice<=8;

SELECT name, company, country FROM CAR WHERE company='Nissan' OR country='GERMANY';

SELECT name FROM CAR WHERE company IN('Maruti', 'Ford');

ALTER TABLE CAR ADD year INT;
UPDATE CAR SET year=2020;

SELECT name AS Car_name FROM CAR;

ALTER TABLE CAR RENAME COLUMN name TO car_name;

SELECT car_name AS cars_Toyota FROM CAR WHERE company='Toyota';

SELECT * FROM CAR ORDER BY car_name ASC;

SELECT * FROM CAR ORDER BY approxprice ASC;

---------------------------------------------------------

CREATE TABLE `Student` (
	`Rollno` INT NOT NULL AUTO_INCREMENT,
	`Name` VARCHAR(255),
	`Physics` INT,
	`Chemistry` INT,
	`Maths` INT,
	PRIMARY KEY (`Rollno`)
);

INSERT INTO 
Student(Name, Physics, Chemistry, Maths)
VALUES
('Adam', 20, 20, 33),
('Bob', 18, 9, 41),
('Bright', 22, 7, 31),
('Duke', 13, 21, 20),
('Elvin', 14, 22, 23),
('Fetcher', 2, 10, 48),
('Georgina', 22, 12, 22),
('Mary', 24, 14, 31),
('Tom', 19, 15, 24),
('Zack', 8, 20, 36);

SELECT AVG(Physics) FROM Student;

SELECT MAX(Maths) AS highest_marks_maths FROM Student;

SELECT MIN(Chemistry) AS lowest_mark_chemistry FROM Student;

SELECT COUNT(Physics) FROM Student WHERE Physics>=12;

SELECT * FROM Student WHERE Physics>=12 AND Chemistry>=12 AND Maths>=25;

SELECT Name,
CASE
    WHEN Physics >= 12 THEN 'Pass'
    ELSE 'Fail'
END AS Physics,
CASE
    WHEN Chemistry >= 12 THEN 'Pass'
    ELSE 'Fail'
END AS Chemistry,
CASE
    WHEN Maths >= 25 THEN 'Pass'
    ELSE 'Fail'
END AS Maths
FROM Student;

SELECT (COUNT(Maths)/(SELECT COUNT(*) FROM Student)*100) AS maths_pass 
FROM Student WHERE Maths>=25;

SELECT (COUNT(*)/(SELECT COUNT(*) FROM Student)*100) AS total_pass_perc 
FROM Student 
WHERE Maths>=25
AND Physics>=12
AND Chemistry>=12;

SELECT SUM(Physics+Chemistry+Maths)/(SELECT COUNT(*) FROM Student) AS Average FROM Student;

SELECT COUNT(*) AS Passed FROM Student WHERE Physics>=12 AND Chemistry>=12 AND Maths>=25;

----------------------------

CREATE TABLE `acct_details` (
	`acct_no` VARCHAR(255),
	`branch` VARCHAR(255),
	`name` VARCHAR(255),
	`phone` VARCHAR(255)
);

INSERT INTO 
acct_details(acct_no, branch, name, phone)
VALUES
('A40123401', 'Chicago', 'Mike Adams', '(378)400-1234'),
('A40123402', 'Miami', 'Diana George', '(372)420-2345'),
('B40123403', 'Miami', 'Diaz Elizabeth', '(371)450-3456'),
('B40123404', 'Atlanta', 'Jeoffrey George', '(371)450-3456'),
('B40123405', 'New York', 'Jennifer Kaitlyn',  '(373)470-5678'),
('C40123406', 'Chicago', 'Kaitlyn Vincent', '(318)200-3235'),
('C40123407', 'Miami', 'Abraham Gottfield', '(328)300-2256'),
('C50123409', 'New Jersey', 'Stacy Williams', '(338)400-5237'),
('D50123409', 'New York', 'Catherine George', '(348)500-6228'),
('D50123410', 'Miami', 'Oliver Scott', '(358)600-7230');

SELECT name from acct_details WHERE name LIKE 'D%';

SELECT DISTINCT branch from acct_details WHERE branch LIKE '%New%';

SELECT UPPER(name) FROM acct_details;

SELECT name FROM acct_details WHERE name LIKE '___n%n';

SELECT name from acct_details WHERE name LIKE 'D%_a%Eli%';

SELECT name FROM acct_details WHERE acct_no LIKE '%6';

UPDATE acct_details SET name=UPPER(name);

SELECT name FROM acct_details WHERE name LIKE '%T';

SELECT REVERSE(name) FROM acct_details;

SELECT LPAD(phone, 15, "+1") FROM acct_details; 

SELECT SUBSTR(acct_no, 2) FROM acct_details;

SELECT * from acct_details WHERE name LIKE '%Williams%' AND acct_no LIKE '_4%';

SELECT reverse('nmutuAotedOehT');

SELECT LTRIM('123231xyzTech','123231xyz');

SELECT RTRIM('Computer ');

SELECT RPAD('computer', 12, 'X');

SELECT POSITION('e' IN 'Welcome to Kerala');

SELECT INITCAP('mARKcALAwaY');

SELECT LENGTH('Database Management Systems');

SELECT CONCAT('Julius', 'Caesar');

SELECT SUBSTR('India is my country',7,2);

-----------------------------------------

CREATE TABLE Subjects (
	Sub_id INT NOT NULL,
	Sub_name VARCHAR(255) NOT NULL
);

INSERT INTO
Subjects(Sub_id,Sub_name)
VALUES
(1,'Maths'),
(2,'Physics'),
(3,'Chemistry'),
(4,'English');

SELECT * FROM Subjects;

ALTER TABLE Subjects
ADD CONSTRAINT PK
PRIMARY KEY(Sub_id);

\d+ Subjects;


CREATE TABLE IF NOT EXISTS Staff (
	Staff_id INT NOT NULL UNIQUE,
	Staff_name VARCHAR(255),
	Dept VARCHAR(255),
	Age INT CHECK (Age>22),
	Salary INT CHECK (Salary<35000)
);

INSERT INTO
Staff(Staff_id,Staff_name,Dept,Age,Salary)
VALUES
(1,'John','Purchasing',24,30000),
(2,'Sera','Sales',25,20000),
(3,'Jane','Sales',28,25000);

SELECT * FROM Staff;

\d+ Staff;

ALTER TABLE staff DROP CONSTRAINT staff_salary_check;

\d+ Staff;

ALTER TABLE staff DROP CONSTRAINT staff_staff_id_key;

\d+ Staff;

CREATE TABLE Bank (
	Bank_code VARCHAR(3),
	Bank_name VARCHAR(255),
	Head_office VARCHAR(255),
	Branches INT
);

ALTER TABLE Bank
ADD CONSTRAINT
PKey PRIMARY KEY (Bank_code);

ALTER TABLE Bank
ALTER COLUMN Bank_name
SET NOT NULL; 

ALTER TABLE Bank
ADD CONSTRAINT 
CK CHECK (Branches>0); 

\d+ Bank;

INSERT INTO
Bank(Bank_code,Bank_name,Head_office,Branches)
VALUES
('AAA','SIB','Ernakulam',6),
('BBB','Federal','Kottayam',6),
('CCC','Canara','Trivandrum',3),
('SBT','Indian','Delhi',7);

CREATE TABLE Branch (
	Branch_id INT,
	Branch_name VARCHAR(255) DEFAULT 'New Delhi',
	Bank_id VARCHAR(3),
	PRIMARY KEY (Branch_id),
	FOREIGN KEY (Bank_id) REFERENCES Bank(Bank_code) ON DELETE CASCADE
);

\d+ Staff;

INSERT INTO
Branch(Branch_id,Branch_name,Bank_id)
VALUES
(1,'Kottayam','CCC'),
(5,'Calicut','SBT');

SELECT * FROM Branch;

INSERT INTO
Branch(Branch_id,Bank_id)
VALUES
(6,'SBT');

SELECT * FROM Branch;

DELETE * FROM Bank WHERE Bank_code='SBT';

SELECT * FROM Bank;

SELECT * FROM Branch;

CREATE VIEW sales_staff AS SELECT * FROM staff WHERE dept='Sales'; 

\d+ sales_staff;

SELECT * FROM sales_staff;

DROP TABLE Branch;
CREATE TABLE Branch(
	branchid INT,
	branchname VARCHAR(10) CONSTRAINT Df DEFAULT 'New Delhi',
	bankid VARCHAR(3),
	CONSTRAINT pk PRIMARY KEY(branchid),
	CONSTRAINT Fk FOREIGN KEY(bankid) REFERENCES Bank(Bank_code) ON DELETE CASCADE
);

ALTER TABLE Branch 
ALTER branchname 
DROP DEFAULT;

\d+ Branch;

ALTER TABLE Branch DROP CONSTRAINT Pk;

\d+ Branch;

CREATE OR REPLACE VIEW sales_staff as(SELECT * from staff
WHERE salary>'20000' and dept='Sales');

DROP VIEW sales_staff;

--------------------------------------------

CREATE TABLE `Items` (
	`itemid` INT,
	`itemname` VARCHAR(255),
	`category` VARCHAR(255),
	`price` INT,
	`instock` INT,
	PRIMARY KEY (`itemid`)
);

INSERT INTO
Items(itemid,itemname,category,price,instock)
VALUES
(5,'sony z5 premium','electronics',5005,1),
(4,'Samsing Galaxy S4','electronics',5005,1),
(3,'One Plus 7','electronics',6006,2),
(2,'Iphone X','electronics',7007,6),
(1,'Xiomi','electronics',1001,6);

CREATE TABLE `Customers` (
	`custid` INT,
	`custname` VARCHAR(255),
	`address` VARCHAR(255),
	`state` VARCHAR(255),
	PRIMARY KEY (`custid`)
);

INSERT INTO
Customers(custid,custname,address,state)
VALUES
(111,'elvin','202 jai street','delhi'),
(113,'soman','puthumana','kerala'),
(115,'mickey','juhu','maharastra'),
(112,'patrick','harinagar','tamilnadu'),
(114,'jaise','kottarakara','kerala');


CREATE TABLE `Orders` (
	`orderid` INT,
	`itemid` INT,
	`quantity` INT,
	`orderdate` DATE,
	`custid` INT,
	PRIMARY KEY (`orderid`),
	FOREIGN KEY (itemid) REFERENCES Items(itemid),
	FOREIGN KEY (custid) REFERENCES Customers(custid)
);

INSERT INTO
Orders(orderid,itemid,quantity,orderdate,custid)
VALUES
(1,1,2,'2014-10-11',111),
(2,3,1,'2012-01-29',113),
(3,5,1,'2013-05-13',115),
(4,4,3,'2014-12-22',114);

CREATE TABLE `Delivery` (
	`deliveryid` INT,
	`orderid` INT,
	`custid` INT,
	PRIMARY KEY (`deliveryid`),
	FOREIGN KEY (orderid) REFERENCES Orders(orderid),
	FOREIGN KEY (custid) REFERENCES Customers(custid)
);

INSERT INTO
Delivery(deliveryid,orderid,custid)
VALUES
(1001,1,111),
(1002,2,113),
(1003,3,115);

SELECT * FROM Orders INNER JOIN Customers ON Orders.custid=Customers.custid;

SELECT * FROM Customers WHERE custid IN (SELECT custid FROM Delivery);

SELECT orderdate FROM Orders WHERE custid IN (SELECT custid FROM Customers WHERE custname LIKE 'J%');

SELECT Items.itemname,Items.price FROM Orders
INNER JOIN Customers ON Orders.custid=Customers.custid
INNER JOIN Items ON Orders.itemid=Items.itemid
WHERE Customers.custname='Mickey';

SELECT Customers.* FROM Orders INNER JOIN
Customers ON Orders.custid=Customers.custid
WHERE Orders.orderdate>='2013-01-01' 
AND Orders.orderid NOT IN (
SELECT orderid FROM Delivery
);

SELECT itemid FROM Orders;

SELECT custname FROM Customers WHERE custid IN ( SELECT custid FROM Delivery );

SELECT Customers.custname FROM Orders INNER JOIN
Customers ON Orders.custid=Customers.custid
WHERE Orders.orderid NOT IN (
SELECT orderid FROM Delivery
);

SELECT Customers.custname, COUNT(Orders.custid) FROM Orders INNER JOIN
Customers ON Orders.custid=Customers.custid 
GROUP BY Customers.custname 
ORDER BY 2 DESC LIMIT 1;

SELECT custname FROM Customers WHERE custid IN (
SELECT Orders.custid FROM Orders INNER JOIN
Items ON Orders.itemid=Items.itemid
WHERE Items.price>5000);

SELECT custname,address FROM Customers WHERE custid NOT IN 
(SELECT Orders.custid FROM Orders INNER JOIN
Items ON Orders.itemid=Items.itemid
WHERE Items.itemname='Samsing Galaxy S4');

SELECT * FROM Orders LEFT JOIN
Customers ON Orders.custid=Customers.custid;
SELECT * FROM Orders RIGHT JOIN
Customers ON Orders.custid=Customers.custid;

SELECT * FROM Customers GROUP BY state;

SELECT * FROM Items HAVING price > (SELECT AVG(price) FROM Items);

--------------------------------------------


CREATE or REPLACE FUNCTION prime(prime INT) RETURNS VOID as
$$
DECLARE
flag INT;
count INT =0;
i INT;
start INT=2;
rem INT;
BEGIN
WHILE (count<prime) LOOP flag =0;
FOR i IN 2..(start/2) LOOP rem=start%i;
IF  rem = 0 THEN
flag = 1;
END IF;
END LOOP;
IF flag = 0 THEN
RAISE NOTICE   ' % ' , start;
count=count+1;
END IF;
start=start +1;
END LOOP;
END;
$$ LANGUAGE plpgsql;


SELECT FROM prime(5);

CREATE or REPLACE FUNCTION fib(fib INT) RETURNS VOID as
$$
DECLARE
value INT=1;
new INT=1;
temp INT;
count INT;
BEGIN
RAISE NOTICE ' % ', value; RAISE NOTICE ' % ', new; FOR count in 3..fib LOOP temp=new;
new=new+value;
value=temp;
RAISE NOTICE ' % ', new;
END LOOP;
END;
$$ LANGUAGE plpgsql;

select * from fib(8);

CREATE TABLE student_grade(
	roll INT primary key,
	name VARCHAR(10),
	mark1 INT,
	mark2 INT, 
	mark3 INT,
	grade VARCHAR(4)
);

INSERT INTO student_grade 
VALUES
(1, 'Raj', 50, 45, 48),
(2, 'Mohan', 50, 50, 50),
(3, 'Varun', 35, 40, 40);

CREATE or REPLACE FUNCTION set_student_grade() RETURNS VOID as $$
BEGIN
UPDATE student_grade
SET grade='pass'
WHERE (mark1+mark2+mark3)/3 >40; UPDATE student_grade
SET grade='fail'
WHERE (mark1+mark2+mark3)/3 <=40; END;
$$ LANGUAGE plpgsql;

SELECT FROM set_student_grade(); 
SELECT * FROM student_grade;


CREATE or REPLACE FUNCTION create_circle() RETURNS VOID as $$
DECLARE
data1 INT=5;
data2 REAL;
count INT=5;
i INT ;
BEGIN
CREATE TABLE circle(rad INT ,area REAL); FOR i IN 1..count LOOP data2=3.1416*data1*data1;
INSERT INTO circle VALUES(data1,data2); data1=data1+5;
END LOOP;
END;
$$ LANGUAGE plpgsql;

SELECT FROM create_circle(); 
SELECT * FROM circle;

CREATE TABLE stud(
	name VARCHAR(10),
	mark INT
);

CREATE or REPLACE FUNCTION insert_stud() RETURNS VOID as $$
DECLARE
data1 INT []= '{ 25,76,43,45,67,57,97,56,89,8 }';
data2 VARCHAR(20)[]='{Ronaldo,Messi,Neymar,Suarez,Dybala,Pele,Maradona,Diego,Pogba,Neuer}'; i INT ;
BEGIN
FOR i IN 1..10 LOOP
INSERT INTO stud VALUES(data2[i],data1[i]);
END LOOP;
END;
$$ LANGUAGE plpgsql;


SELECT FROM insert_stud(); 
SELECT * FROM stud;

CREATE TABLE class_cse (
	roll INT PRIMARY KEY,
	name VARCHAR(10),
	phone VARCHAR(15)
);


CREATE SEQUENCE csekey
START 101;
CREATE or REPLACE FUNCTION class_cse() RETURNS VOID as
$$
DECLARE
data1 VARCHAR []= '{ 0482-239091,0484-234562 ,0485-11234,0489-43617,0481-23145}';
data2 VARCHAR(20)[]='{ Naruto,Sasuke,Kakashi,Sakura,Pain }';
i INT ;
j INT;
BEGIN
FOR i IN 1..5 LOOP
INSERT INTO class_cse VALUES(nextval('csekey'),data2[i],data1[i]); END LOOP;
END;
$$ LANGUAGE plpgsql;

SELECT FROM class_cse(); 
SELECT * FROM class_cse;

-----------------------------------

CREATE TABLE stdnt(
	id INT,
	sname VARCHAR(15),
	m1 INT,
	m2 INT,
	m3 INT,
	gr CHAR(1)
);

INSERT INTO stdnt(id,sname,m1,m2,m3) 
VALUES(88,'anu',39,67,92),
(10,'jan',58,61,29),
(30,'karuna',87,79,77),
(29,'jossy',39,80,45);

SELECT * FROM stdnt;

CREATE OR REPLACE FUNCTION get_grade() RETURNS void AS $$
DECLARE
    total INT ;
grade char(1); rec_film RECORD; cur_films CURSOR
       FOR SELECT * FROM stdnt;
BEGIN
OPEN cur_films; LOOP
FETCH cur_films INTO rec_film;
EXIT WHEN NOT FOUND;
total = rec_film.m1+rec_film.m2+rec_film.m3; IF total>240 THEN
          grade='A';
      ELSIF total>180 THEN
		grade='B';
      ELSIF total>120 THEN
        grade='C';
     ELSIF total>60 THEN
        grade='D';
ELSE
            grade='F';
      END IF;
update stdnt set gr=grade where m1=rec_film.m1; END LOOP;
CLOSE cur_films; END; $$
LANGUAGE plpgsql;


SELECT get_grade(); 
SELECT * FROM stdnt;
--
CREATE TABLE bankdetails(
	accno INT,
	name VARCHAR(15),
	balance INT,
	adate DATE
); 

CREATE TABLE banknew(
	accno INT,
	interest INT
);


INSERT INTO bankdetails 
VALUES(1001,'aby',3005,'10-oct-15'),
(1002,'alan',4000,'05-may-95'),
(1003,'amal',5000,'16-mar-92'),
(1004,'jeffin',3500,'01-apr-50'),
(1005,'majo',6600,'01-jan-01');


SELECT * FROM bankdetails;

CREATE OR REPLACE FUNCTION get_interest() RETURNS void AS $$
DECLARE
    interest INT ;
    account   RECORD;
    movacc CURSOR
       FOR SELECT * FROM bankdetails;
BEGIN
   OPEN movacc;
   LOOP
      FETCH movacc INTO account;
      EXIT WHEN NOT FOUND;
interest=0.08*account.balance;
INSERT INTO banknew VALUES (account.accno,interest); END LOOP;
   CLOSE movacc;
END; $$
LANGUAGE plpgsql;

SELECT get_interest(); 
SELECT * FROM banknew;

--

CREATE TABLE people_list(
	id INT,
	name varchar(20),
	dt_joining DATE,
	place varchar(20)
);
CREATE TABLE exp_list(
	id INT,
	name varchar(20),
	exp INT
);
INSERT INTO people_list VALUES
(101,'Robert','03-APR-2005','CHY'),
(102,'Mathew','07-JUN-2008','CHY'),
(103,'Luffy','15-APR-2003','FSN'),
(104,'Lucci','13-AUG-2009','KTM'),
(105,'Law','14-APR-2005','WTC'),
(101,'Vivi','21-SEP-2010','ABA');

CREATE OR REPLACE FUNCTION set_exp() RETURNS void AS $$
DECLARE
    exp INT;
    proff   RECORD;
    today DATE;
    movproff CURSOR
FOR SELECT * FROM people_list; BEGIN
OPEN movproff;
SELECT current_date INTO today; LOOP
      FETCH movproff INTO proff;
      EXIT WHEN NOT FOUND;
SELECT DATE_PART('year', today::date) - DATE_PART('year', proff.dt_joining::date) INTO exp; 
	IF exp>10 THEN
		INSERT INTO exp_list VALUES (proff.id,proff.name,exp); END IF;
   	END LOOP;
   CLOSE movproff;
END; $$
LANGUAGE plpgsql;

SELECT FROM set_exp(); 
SELECT * FROM exp_list;

--

CREATE TABLE emp_list(
	id INT,
	Name VARCHAR(20),
	M_sal INT
);

INSERT INTO emp_list values
(101,'Mathew',55000),
(102,'Jose',80000),
(103,'John',250000),
(104,'Ann',600000);

SELECT * FROM emp_list;


CREATE OR REPLACE FUNCTION sal_incre() RETURNS void AS $$
DECLARE
    yearsal INT;
    monsal INT;
    sal   RECORD;
    movsal CURSOR
FOR SELECT * FROM emp_list; BEGIN
   OPEN movsal;
   LOOP
FETCH movsal INTO sal; EXIT WHEN NOT FOUND; yearsal=sal.m_sal*12; monsal=sal.m_sal;
IF yearsal>500000 THEN
UPDATE emp_list SET m_sal=monsal*1.1 WHERE m_sal=monsal;
ELSIF yearsal>200000 THEN
UPDATE emp_list SET m_sal=monsal*1.15 WHERE m_sal=monsal; ELSIF yearsal>60000 THEN
UPDATE emp_list SET m_sal=monsal*1.2WHERE m_sal=monsal; ELSE
UPDATE emp_list SET m_sal=monsal*1.25 WHERE m_sal=monsal; END IF;
   END LOOP;
   CLOSE movsal;
END; $$
LANGUAGE plpgsql;

SELECT FROM sal_incre(); 
SELECT * FROM emp_list;


-------------------


CREATE TABLE customer_details(
	cust_id int UNIQUE,
	cust_name VARCHAR(25),
	address VARCHAR(30)
);

CREATE TABLE emp_details(
	empid INT UNIQUE,
	empname VARCHAR(20),
	salary INT
);

CREATE TABLE cust_count(count_row INT);

--


CREATE OR REPLACE FUNCTION cust_det_insert() RETURNS TRIGGER AS $cust_det_insert$
    BEGIN
     RAISE NOTICE 'A row is inserted';
RETURN NEW;
    END;
$cust_det_insert$
LANGUAGE plpgsql;
CREATE TRIGGER cust_det_insert AFTER INSERT ON customer_details
FOR EACH STATEMENT EXECUTE PROCEDURE cust_det_insert();

INSERT INTO customer_details VALUES(1,'Leo','Messi');

--

CREATE OR REPLACE FUNCTION emp_sal_check() RETURNS trigger AS $emp_sal$ BEGIN
IF NEW.salary >20000 THEN
RAISE NOTICE 'Employee % has salary greater than 20000 ',NEW.empname;
END IF;
        RETURN NEW;
    END;
$emp_sal$ LANGUAGE plpgsql;
CREATE TRIGGER emp_sal AFTER INSERT OR UPDATE ON emp_details FOR EACH ROW EXECUTE PROCEDURE emp_sal_check();

INSERT INTO emp_details VALUES(1,'Ronaldo',25000);

--

CREATE OR REPLACE FUNCTION cust_count() RETURNS trigger AS $cust_count$ DECLARE
count INT;
BEGIN
SELECT * FROM cust_count INTO count; IF (TG_OP = 'DELETE') THEN
IF count !=0 THEN
UPDATE cust_count SET count_row=count_row-1; END IF;
ELSIF (TG_OP = 'INSERT') THEN
UPDATE cust_count SET count_row=count_row+1; END IF;
RETURN NEW;
END;
$cust_count$ LANGUAGE plpgsql;

CREATE TRIGGER cust_count_change
AFTER INSERT OR DELETE ON customer_details
FOR EACH ROW EXECUTE PROCEDURE cust_count();

INSERT INTO customer_details VALUES(1,'Leo','Messi');
INSERT INTO customer_details VALUES(2,'Paul','Pogba');

--


CREATE TABLE deleted(empid INT ,empname varchar(20),salary int); 
CREATE TABLE updated(empid INT,empname varchar(20),salary int);

CREATE OR REPLACE FUNCTION del_upd() RETURNS trigger AS $del_upd$ BEGIN
IF (TG_OP = 'DELETE') THEN
INSERT INTO deleted VALUES(OLD.empid,OLD.empname,OLD.salary); ELSIF (TG_OP = 'UPDATE') THEN
INSERT INTO updated VALUES(OLD.empid,OLD.empname,OLD.salary); END IF;
RETURN NEW;
END;
$del_upd$ LANGUAGE plpgsql;
CREATE TRIGGER del_upd
AFTER UPDATE OR DELETE ON emp_details
FOR EACH ROW EXECUTE PROCEDURE del_upd();


--

CREATE OR REPLACE FUNCTION div(a INT,b INT) RETURNS INT as
$$
DECLARE
result INT;
BEGIN
IF b=0 THEN
RAISE EXCEPTION  'DVIDE BY ZERO  ' ;
ELSE
result=a/b;
RETURN result ;
END IF;
END;
$$
LANGUAGE plpgsql;

--


CREATE OR REPLACE FUNCTION get_the_sal(id INT) RETURNS INT as $$
DECLARE
result INT;
BEGIN
SELECT salary INTO result FROM emp_details WHERE empid=id; IF RESULT IS NULL THEN
RAISE EXCEPTION 'NO DATA FOUND' ;
ELSE
RETURN result;
END IF;
END;
$$
LANGUAGE plpgsql;

--

CREATE TABLE ebill(cname varchar(20),preread int,curread int);


CREATE OR REPLACE FUNCTION check_reading() RETURNS TRIGGER AS $checkread$
BEGIN
IF NEW.preread=NEW.curread THEN
RAISE EXCEPTION 'DATA ENTRY ERROR A % B %' ,NEW.preread,NEW.curread; ELSE
RAISE NOTICE 'STATEMENT PROCESSED' ;
END IF;
RETURN NEW;
END;
$checkread$
LANGUAGE plpgsql;

CREATE TRIGGER check_reading
BEFORE INSERT ON ebill
FOR EACH ROW EXECUTE PROCEDURE check_reading();

----------------------------------------------


CREATE OR REPLACE FUNCTION fact(fact INT) RETURNS INT AS
$$
DECLARE
	count INT = 1;
    result INT = 1;
BEGIN
FOR count IN 1..fact LOOP result = result* count; END LOOP;
RETURN result;
END;
$$ LANGUAGE plpgsql;

--


CREATE TABLE student_details (
	roll int,
	marks int,
	phone int
);
INSERT INTO student_details VALUES(1,70,94969474), 
(2,85,94959413),
(3,78,82818650);

CREATE OR REPLACE PROCEDURE boost()
LANGUAGE plpgsql
AS $$
BEGIN
UPDATE student_details SET marks=marks*1.05; END;
$$;
--

CREATE TABLE student(
	id INT, 
	name VARCHAR(255), 
	m1 INT, 
	m2 INT, 
	m3 INT, 
	total INT, 
	grade VARCHAR(2)
);

CREATE OR REPLACE PROCEDURE insert_grade(sid INT ,sgrade CHAR) LANGUAGE plpgsql
AS $$
BEGIN
UPDATE student SET grade=sgrade WHERE id=sid;
END;
$$;

CREATE OR REPLACE FUNCTION insert_stud(id INT ,name varchar(20),m1 INT, m2 INT, m3 INT) RETURNS VOID AS
$$
DECLARE
total INT;
grade CHAR;
BEGIN
total=m1+m2+m3;
INSERT INTO student VALUES(id,name,m1,m2,m3,total);
IF  total >=240 THEN
grade='A';
ELSIF total >=180 THEN grade='B';
ELSIF total>=120 THEN grade='C';
ELSIF total>=60 THEN
grade = 'D' ;
ELSE
grade ='F';
END IF;
CALL insert_grade(id,grade); END;
$$
LANGUAGE plpgsql;

--



