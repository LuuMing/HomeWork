USE master
GO
CREATE DATABASE 学生选课表
ON 
( NAME = 学生选课_dat,
   FILENAME = 'c:\学生选课.mdf',
   SIZE = 10,
   MAXSIZE = 50,
   FILEGROWTH = 5 )
LOG ON
( NAME = '学生选课_log',
   FILENAME = 'c:\学生选课.ldf',
   SIZE = 5MB,
   MAXSIZE = 25MB,
   FILEGROWTH = 5MB )
GO
use 学生选课表
create table 学生
(
学号 char(10) constraint PK_学生_学号  primary key,
姓名 char(10) constraint U_学生_姓名  not null,
性别 char(2)  not null constraint CK_学生_性别 check(性别 in ('男','女')),
年龄 int  ,
系名 char(50),
)

create table 课程
(
课程号 char(10) constraint PK_课程_课程号 primary key,
课程名 char(10) not null constraint C_课程_课程名 unique,
学期   char(2)  not null constraint S_课程_学期 check(学期 in (' 1','2','3','4','5','6','7','8')),
学分   int   not null constraint R_课程_学分 check(学分 in ('1','2','3')),
)

create table 学生选课
(
学号 char(10) references 学生()
课程号 
成绩 int constraint 学生选课_成绩
)
