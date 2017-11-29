use master
DROP DATABASE 图书管理信息系统 
go
create database 图书管理信息系统
on
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
)
go
use 图书管理信息系统

create table book_cate
(
类别编号 char(50) primary key,
类别名称 char(20),
关键词 char(50),
备注信息 char(50)
)

create table book
(
书籍编号 char(50) primary key,
书籍名称 char(50), 
书籍类别  char(50) foreign key references book_cate(类别编号), 
作者名称 char(50) ,
出版社名称 char(50),
出版日期 datetime,
书籍页码 int,
关键词 char(50),
登记日期 datetime,
备注信息 char(50),
)
create table reader_cate
(
种类编号 char(50) primary key,
种类名称 char(20),
借书数量 int ,
借书期限 int,
备注信息 char(50)
)

create table reader
(
读者编号 char(50) primary key,
读者姓名 char(10),
读者种类 char(50) foreign key references reader_cate(种类编号),
读者性别 char (4),
工作单位 char(50),
家庭地址 char(50),
电话号码 char(11),
电子邮件地址 char(20),
办证日期 datetime ,
备注信息 char(50),
)

create table borrow_relation
(
借阅编号 char(50) primary key,
读者编号 char(50) foreign key references reader(读者编号),
书籍编号 char(50) foreign key references book(书籍编号),
借书日期 datetime not null,
还书日期 datetime,
备注信息 char(50)
)

