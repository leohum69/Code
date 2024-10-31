create database labtask8;
use labtask8;

CREATE TABLE tblEmployee (
id INTEGER NOT NULL,
firstName VARCHAR(255) NOT NULL,
lastName VARCHAR(255) NOT NULL,
salary INTEGER NOT NULL,
departID INTEGER NULL
);
CREATE TABLE tblDepartment (
id INTEGER NOT NULL,
name VARCHAR(255) NOT NULL,
location VARCHAR(255) NOT NULL
);
INSERT INTO tblEmployee  VALUES 
(1, 'Abhishek', 'Yadav', 37000, 1);
INSERT INTO tblEmployee  VALUES 
(2, 'Raj', 'Verma', 47500, 3);
INSERT INTO tblEmployee  VALUES 
(3, 'Tony', 'Bell', 44000, 2);
INSERT INTO tblEmployee  VALUES 
(4, 'Rahul', 'Sharma', 27000, NULL);
INSERT INTO tblEmployee  VALUES 
(5, 'Vishal', 'Maurya', 18500, 4);
INSERT INTO tblEmployee  VALUES 
(6, 'Jyoti', 'Kakawat', 28000, 5);
INSERT INTO tblEmployee  VALUES 
(7, 'Vipin', 'Mehra', 30000, 5);
INSERT INTO tblEmployee  VALUES 
(8, 'Pradeep', 'Gupta', 70000, 1);
INSERT INTO tblEmployee  VALUES 
(9, 'Sumit', 'Jolly', 55000, 6);
INSERT INTO tblEmployee  VALUES 
(10, 'Jyoti', 'Mishra', 20000, NULL);
INSERT INTO tblEmployee  VALUES 
(11, 'Karan', 'Pratap', 25000, 2);
INSERT INTO tblEmployee  VALUES 
(12, 'Aleem', 'Shaikh', 35000, 4);
INSERT INTO tblEmployee  VALUES 
(13, 'Kavita', 'Thakur', 30000, 4);
INSERT INTO tblEmployee  VALUES 
(14, 'Sufyan', 'Mukadam', 40000, 6);
INSERT INTO tblEmployee  VALUES 
(15, 'Ashish', 'Mehra', 37000, NULL);
INSERT INTO tblEmployee  VALUES 
(16, 'Mehul', 'Joshi', 65000, NULL);
INSERT INTO tblEmployee  VALUES 
(17, 'Payal', 'Yadav', 15000, 5);
INSERT INTO tblEmployee  VALUES 
(18, 'Swapnil', 'Patil', 36000, 5);
INSERT INTO tblEmployee  VALUES 
(19, 'Richa', 'Patel', 37000, 3);
INSERT INTO tblEmployee  VALUES 
(20, 'Mahesh', 'Singh', 33000, 5);
INSERT INTO tblEmployee  VALUES 
(21, 'Kaleem', 'Khan', 8000, 4);
INSERT INTO tblEmployee  VALUES 
(22, 'Heena', 'Shaikh', 14000, NULL);
INSERT INTO tblEmployee  VALUES 
(23, 'Rahul', 'Kotian', 26000, 3);
INSERT INTO tblEmployee  VALUES 
(24, 'Naveen', 'Kapoor', 37000, NULL);
INSERT INTO tblEmployee  VALUES 
(25, 'Sanjay', 'Sawant', 65000, 3);
INSERT INTO tblDepartment VALUES
(1, 'SQL', 'Mumbai');
INSERT INTO tblDepartment VALUES
(2, 'Finance', 'Pune');
INSERT INTO tblDepartment VALUES
(3, 'SDM', 'Thane');
INSERT INTO tblDepartment VALUES
(4, 'MySQL', 'Chennai');
INSERT INTO tblDepartment VALUES
(5, 'DB2', 'Kolkata');
INSERT INTO tblDepartment VALUES
(6, 'Oracle', 'Delhi');
INSERT INTO tblDepartment VALUES
(7, 'Marketing', 'Delhi');
INSERT INTO tblDepartment VALUES
(8, 'Networking', 'Mumbai');
INSERT INTO tblDepartment VALUES
(9, 'HR', 'Mumbai');


select * from tblEmployee;
--q1
select e.ID as EMP_NUMBER,CONCAT(e.firstName,' ',e.lastName) as FULL_NAME, e.salary,d.name as DEPT_NAME,d.location as DEPT_LOCATION
from
tblEmployee as e left outer join tblDepartment as d
ON e.departID = d.id;

--q2
select count(e.id) as TOTAL_EMPS_IN_EACH_DEPARTMENT,d.name
from tblEmployee as e join tblDepartment as d
on e.departID = d.id
group by d.name;

--q3
SELECT d.name, CONCAT(e.firstName,' ',e.lastName) as FULL_NAME, e.salary
FROM tblEmployee as e
JOIN tblDepartment as d ON e.departID = d.id
WHERE e.salary = (
    SELECT MIN(salary)
    FROM tblEmployee
    WHERE departID = e.departID
);



--q4
select q.department_name,q.average_salary from (SELECT d.name AS department_name,AVG(e.salary) AS average_salary
FROM tblEmployee e
JOIN tblDepartment d ON e.departID = d.id
GROUP BY d.name)as q where q.average_salary = (select  Min(salary) from (select Avg(E.salary)as salary from tblEmployee as E group by e.departID)as z);
