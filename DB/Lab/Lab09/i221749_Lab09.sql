create database Labtask9;
use Labtask9;

create table Users(
	id INT not null primary key check (id BETWEEN 1 AND 1749),
	name varchar(20) not null,
	username varchar(20) not null,
	DOB BIGINT NULL
);

CREATE TABLE Posts (
    id INT NOT NULL PRIMARY KEY CHECK (id BETWEEN 1 AND 1749), 
    description VARCHAR(255) NOT NULL, 
    date BIGINT NOT NULL, 
    user_id INT NOT NULL,
    FOREIGN KEY (user_id) REFERENCES Users(id)
);

CREATE TABLE Comments (
    id INT NOT NULL PRIMARY KEY CHECK (id BETWEEN 1 AND 1749), 
    description VARCHAR(255) NOT NULL, 
    date BIGINT NOT NULL, 
    post_id INT NOT NULL, 
    user_id INT NOT NULL,
    FOREIGN KEY (post_id) REFERENCES Posts(id), 
    FOREIGN KEY (user_id) REFERENCES Users(id)
);

INSERT INTO Users (id, name, username, DOB) VALUES
(1, 'Mirza Humayun Masood', 'i221749', 1065482111), 
(2, 'Saif-Ur-Rehman', 'i221697', 1069974911), 
(3, 'Muhammad Bilal', 'i221636', 1094858111),  
(4, 'Umer Farooq', 'i220518', 1084403711); 

--delete from Users;
--select id,name,username,DATEADD(SECOND, DOB, '1970-01-01') as DOB from Users;

INSERT INTO Posts (id, description, date, user_id) VALUES
(1, 'Me is Very very Bored', 1609459200, 1),  
(2, 'Sir Naveed is very cool', 1612137600, 2),
(3, 'I hate DATA BASE A LOTTTTT', 1614556800, 3),  
(4, 'Meow Meow Meow ', 1617235200, 4);  
--delete from Posts;
--select id,description,user_id,DATEADD(SECOND, date, '1970-01-01') as DOB from Posts;

INSERT INTO Comments (id, description, date, post_id, user_id) VALUES
(1, 'Wow Very dangerous', 1617321600, 1, 2),  
(2, 'MOYE MOYE', 1617408000, 1, 3),  
(3, 'BADO BADI', 1617494400, 2, 1),  
(4, 'MEOW MOEW', 1617580800, 3, 4); 
delete from Comments;
select id,description,user_id,post_id,DATEADD(SECOND, date, '1970-01-01') as DOB from Comments;

update Comments
set description = 'HEHEHEHE'
where id = 4;

--select id,description,user_id,post_id,DATEADD(SECOND, date, '1970-01-01') as DOB from Comments;


