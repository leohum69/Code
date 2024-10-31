create database labtask6a;
use labtask6a;

create table dept(
deptno int,
dname varchar(14),
loc varchar(13),
primary key(deptno),
);

insert into dept values (10, 'accounting', 'new york');
insert into dept values (20, 'research', 'dallas');
insert into dept values (30, 'sales', 'chicago');
insert into dept values (40, 'operations', 'boston');

create table emp
(empno int,
deptno int,
ename varchar(10),
job varchar(9),
mgr numeric (4),
hiredate date,
sal numeric (7, 2),
comm numeric(7, 2),
foreign key (deptno) references dept(deptno),
primary key (empno)
);

insert into emp values(7369, 10, 'smith', 'clerk', 7982, convert (date, '17-dec-1980'), 800, null);
insert into emp values(7499, 40, 'allen', 'salesman',7698, convert(date, '28-feb-1981'), 1688,388);
insert into emp values(7521, 30, 'ward', 'salesman', 7698, convert (date, '22-feb-1981'), 1250, 500);
insert into emp values(7566, 10, 'jones', 'manager',7839, convert (date, '2-apr-1981'), 2975, null);
insert into emp values(7654, 10, 'martin', 'salesman',7698, convert (date, '28-sep-1981'), 1250, 1400);
insert into emp values(7698, 40, 'blake', 'manager',7839, convert (date, '1-may-1981'), 2850, null);
insert into emp values(7782, 30, 'clark', 'manager',7839, convert (date, '9-jun-1981'), 2450, null);
insert into emp values(7788, 10, 'scott', 'analyst', 7566, convert(date, '9-dec-1982'), 3080, null);
insert into emp values(7839, 30, 'king', 'president', null, convert(date, '17-nov-1981'), 5000, null);
insert into emp values(7844, 30, 'turner', 'salesman',7698, convert (date, '8-sep-1981'), 1588, 8);
insert into emp values(7876, 10, 'adams','clerk', 7788, convert(date, '12-jan-1983'), 1100, null);
insert into emp values(7980, 30, 'james', 'clerk',7698, convert(date, '3-dec-1981'), 950, null);
insert into emp values(7902, 40, 'ford', 'analyst',7566, convert (date, '3-dec-1981'), 3000, null);
insert into emp values(7934, 10, 'miller', 'clerk',7782, convert (date, '23-jan-1982'), 1300, null);
insert into emp values(7612, 20, 'cook', 'research',7566, convert (date, '3-dec-1981'), 3000, null);
insert into emp values(7634, 20, 'bairstow', 'research',7782, convert (date, '23-jan-1982'), 1300, null);
insert into emp values(7602, 20, 'broad', 'research',7566, convert (date, '3-dec-1981'), 3000, null);
insert into emp values(7134, 20, 'buttler', 'research',7782, convert (date, '23-jan-1982'), 1300, null);

create view newtab as
select emp.*,dept.dname from emp inner join dept
ON emp.deptno = dept.deptno
where sal>=2000 and dept.dname = 'research';

select * from newtab;

create view xd as
select deptno,min(emp.sal) as minimum, max(emp.sal) as maximum
from emp
group by emp.deptno;


select emp.* from emp,xd 
where emp.sal = xd.minimum and emp.deptno = xd.deptno
order by emp.deptno;

select emp.* from emp,xd 
where emp.sal = xd.maximum and emp.deptno = xd.deptno
order by emp.deptno;

select * from emp
where emp.sal = (select max(emp.sal) from emp 
				where(emp.sal <(
					select max(emp.sal) from emp)));

select CONCAT(emp.ename,' is ',emp.job) as INTRO from emp
where emp.job in ('teacher','clerk','lecturer');

