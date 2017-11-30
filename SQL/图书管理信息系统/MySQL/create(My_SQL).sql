DROP DATABASE LMS;
create database LMS;
/*on
(
name = '图书管理信息系统_dat',
filename = 'c:\图书管理信息系统.mdf',
size = 10,
maxsize = 50,
filegrowth = 5
)
log on
(
name = '图书管理信息系统_log',
filename = 'c:\图书管理信息系统.ldf',
size = 5,
maxsize = 25,
filegrowth = 5mb
)*/
use LMS;

create table book_cate
(
num char(50) primary key,
name char(20),
key_words char(50),
logs char(50)
);

create table book
(
num char(50) primary key,
name char(50), 
cate char(50) references book_cate(num), 
author_name char(50) ,
pub_name char(50),
pub_date datetime,
pages int,
keywords char(50),
reg_date datetime,
logs char(50)
);
create table reader_cate
(
num char(50) primary key,
name char(20),
total int ,
limite int,
logs char(50)
);

create table reader
(
num char(50) primary key,
name char(10),
cate char(50) references reader_cate(num),
sex char (4),
company char(50),
address char(50),
phone char(11),
email char(20),
reg_time datetime ,
logs char(50)
);

create table borrow_relation
(
num char(50) primary key,
reader_num char(50) references reader(num),
book_num char(50) references book(num),
out_time datetime not null,
in_time datetime,
logs char(50)
);
