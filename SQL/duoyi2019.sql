--	@author: Luming
--	@date: 18/9/6 22:17
--	说明:多益2019内推笔试，创建存储过程，根据职称自动更改工资
--
drop database if exists test;
create database test;
use test;
create table 职员
(
	职称 varchar(20),
	工资 int
);
insert into 职员(职称,工资) values("教授",10);
insert into 职员(职称,工资) values("副教授",10);
create procedure update_salary
(
)
begin
	update 职员 set 工资 = 500 where 职称 = "教授";
	update 职员 set 工资 = 1000 where 职称 = "副教授";
end; 
