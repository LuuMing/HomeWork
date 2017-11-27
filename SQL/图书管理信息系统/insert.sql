use 图书管理信息系统
insert book_cate values(1,'数学','考研 数学','无')
insert book_cate values(2,'语文','考研 语文','无')

insert reader_cate values(1,'老师',30,30,'老师每次最多可借阅30本，期限30天')
insert reader_cate values(2,'学生',10,10,'学生每次最多可借阅10本，期限10天')

insert reader_cate(种类编号,种类名称) values(3,'外来人员')

select * from reader_cate